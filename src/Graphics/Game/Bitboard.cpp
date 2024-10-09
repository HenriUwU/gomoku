/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/09 17:30:33 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

Bitboard::Bitboard() {
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
	_firstPlayerBoardDiagonals.fill(0);
	_secondPlayerBoardDiagonals.fill(0);
	_firstPlayerBoardAntiDiagonals.fill(0);
	_secondPlayerBoardAntiDiagonals.fill(0);
}

Bitboard::~Bitboard() {}

bool	Bitboard::placeStone(int x, int y, int player) {
	uint32_t	mask = uint32_t(1) << x;

	if (!isLegalMove(x, y, player))
		return (false);

	(player == 1) ? _firstPlayerBoardLines[y] |= mask : _secondPlayerBoardLines[y] |= mask;

	update(x, y, player, true);
	
	std::vector<std::pair<int, int>> onverraplustard;

	int captures = makeCapture(x, y, player, onverraplustard);
	(player == 1) ? playersCaptures[0] += captures : playersCaptures[1] += captures;

	if (fiveInARow(x, y, player) || (playersCaptures[0] == 5 || playersCaptures[1] == 5) || fifthCaptureAvailable()) {
		if (player == 1)
			endGameState = P1VICTORY;
		else if (player == 2 && gameState != AIVERSUS)
			endGameState = P2VICTORY;
		else
			endGameState = AIVICTORY;
	}
	return (true);
}

bool	Bitboard::fifthCaptureAvailable() {
	if (playersCaptures[0] != 4 && playersCaptures[1] != 4)
		return (false);
	
	if (playersCaptures[0] == 4) {
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			for (int x = 0; x < BOARD_SIZE; x++)
			{
				if (isLegalMove(x, y, 1))
				{
					placeStoneAI(x, y, 1, false);
					if (isCapturingMove(x, y, 1))
					{
						removeStone(x, y, 1);
						return (true);
					}
					removeStone(x, y, 1);
				}
			}
		}
	}
	if (playersCaptures[1] == 4) {
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			for (int x = 0; x < BOARD_SIZE; x++)
			{
				if (isLegalMove(x, y, 2))
				{
					placeStoneAI(x, y, 2, false);
					if (isCapturingMove(x, y, 2))
					{
						removeStone(x, y, 2);
						return (true);
					}
					removeStone(x, y, 2);
				}
			}
		}
	}
	return (false);
}

std::vector<std::pair<int, int>>	Bitboard::placeStoneAI(int x, int y, int player, bool mode) {
	uint32_t							mask = uint32_t(1) << x;
	std::vector<std::pair<int, int>>	removedStones;

	(player == 1) ? _firstPlayerBoardLines[y] |= mask : _secondPlayerBoardLines[y] |= mask;
	update(x, y, player, true);
	
	if (mode)
		makeCapture(x, y, player, removedStones);
	
	return removedStones;
}

void	Bitboard::removeStone(int x, int y, int player) {
	uint32_t mask = uint32_t(1) << x;

	if (getBit(x, y)) {
		if (player == 1) {
			_firstPlayerBoardLines[y] &= ~mask;
			update(x, y, 1, false);
		} else {
			_secondPlayerBoardLines[y] &= ~mask;
			update(x, y, 2, false);
		}
	}
}

bool	Bitboard::isGameOver() {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (fiveInARow(x, y, 1) || fiveInARow(x, y, 2))
				return (true);
		}
	}
	return (false);
}

bool	Bitboard::isLegalMove(int x, int y, int player) {
	if (getBit(x, y))
		return (false);

	if (isDoubleThree(x, y, player) && !isCapturingMove(x, y, player)) {
		if (!aiPlaying)
			forbiddenMoves = DOUBLE_THREE;
		return (false);
	}
	return (true);
}

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::getAllStones() {
	std::unordered_set<std::pair<int, int>, pair_hash>	stones;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (getBit(x, y)) {
				stones.emplace(x, y);
			}
		}
	}
	return (stones);
}

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generatePossibleMoves(int player) {
	std::unordered_set<std::pair<int, int>, pair_hash>		uniqueMoves;
	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	int														margin = 1;

	for (auto& stone : currentStones) {
		int startX = std::max(0, stone.first - margin);
		int endX = std::min(BOARD_SIZE - 1, stone.first + margin);
		int startY = std::max(0, stone.second - margin);
		int endY = std::min(BOARD_SIZE - 1, stone.second + margin);

		for (int x = startX; x <= endX; ++x) {
			for (int y = startY; y <= endY; ++y) {
				if (!getBit(x, y)) {
					if (isLegalMove(x, y, player))
						uniqueMoves.emplace(x, y);
				}
			}
		}
	}
	return (uniqueMoves);
}

/* std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generateMoves(int player) {
	uint32_t patterns[10] = {
		// In a row
		0b1100, 0b0011, 0b1110, 0b0111, 0b1111,
		// Broken
		0b1001, 0b1010, 0b0101, 0b1011, 0b1101
	};

	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	std::unordered_set<std::pair<int, int>, pair_hash>		possibleMoves;

	for (auto& stone : currentStones) {
		for (int i = 0; i < 10; i++) {
			// Horizontal axis
			int 		x = stone.first;
			int 		y = stone.second;
			uint32_t	firstPlayerBitboard = _firstPlayerBoardLines[y];
			uint32_t	secondPlayerBitboard = _secondPlayerBoardLines[y];
			// Horizontal axis, right direction
			if (x + 3 < BOARD_SIZE) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					xMin = (x - 1 > 0) ? x - 1 : x;
					xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

					while (xMin < xMax) {
						if (isLegalMove(xMin, y, player))
							possibleMoves.emplace(xMin, y);
						xMin++;
					} 
				}
			}
			// Horizontal axis, left direction
			if (x - 3 > 0) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					xMin = (x - 4 > 0) ? x - 4 : 0;
					xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

					while (xMin < xMax) {
						if (isLegalMove(xMin, y, player))
							possibleMoves.emplace(xMin, y);
						xMin++;
					}
				}
			}
			// Vertical axis
			x = stone.second;
			y = stone.first;
			firstPlayerBitboard = _firstPlayerBoardColumns[y];
			secondPlayerBitboard = _secondPlayerBoardColumns[y];
			// Vertical axis, up direction
			if (x + 3 < BOARD_SIZE) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					xMin = (x - 1 > 0) ? x - 1 : x;
					xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

					while (xMin < xMax) {
						if (isLegalMove(y, xMin, player))
							possibleMoves.emplace(y, xMin);
						xMin++;
					}
				}
			}
			// Vertical axis, down direction
			if (x - 3 > 0) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					xMin = (x - 4 > 0) ? x - 4 : 0;
					xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

					while (xMin < xMax) {
						if (isLegalMove(y, xMin, player))
							possibleMoves.emplace(y, xMin);
						xMin++;
					}
				}
			}
			// Diagonal axis
			int boardSide = (x < stone.second + 1) ? 1 : 2;
			x = stone.first;
			y = rotateY45(x, stone.second);
			firstPlayerBitboard = _firstPlayerBoardDiagonals[y];
			secondPlayerBitboard = _secondPlayerBoardDiagonals[y];
			// Diagonal axis, up direction
			if ((boardSide == 1 && x + 3 < y + 1) || (boardSide == 2 && x + 3 < BOARD_SIZE)) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					if (boardSide == 1) {
						xMin = (x - 1 < 0) ? x : x - 1;
						xMax = (x + 4 >= y + 1) ? y : x + 4;
					}
					else {
						xMin = (x - 1 < y + 1) ? x : x - 1;
						xMax = (x + 4 >= BOARD_SIZE - 1) ? BOARD_SIZE - 1 : x + 4;
					}

					while (xMin < xMax) {
						if (isLegalMove(xMin, (boardSide == 1) ? y - xMin : y + (BOARD_SIZE - xMin), player))
							possibleMoves.emplace(xMin, (boardSide == 1) ? y - xMin : y + (BOARD_SIZE - xMin));
						xMin++;
					}
				}
			}
			// Diagonal axis, down direction
			if ((boardSide == 1 && x - 3 >= 0) || (boardSide == 2 && x - 3 > y + 1)) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					if (boardSide == 1) {
						xMin = (x - 4 < 0) ? x : x - 4;
						xMax = (x + 1 >= y + 1) ? y : x + 1;
					}
					else {
						xMin = (x - 4 <= y + 1) ? y + 1 : x - 4;
						xMax = (x + 1 > BOARD_SIZE - 1) ? BOARD_SIZE - 1 : x + 1;
					}

					while (xMin < xMax) {
						if (isLegalMove(xMin, (boardSide == 1) ? y - xMin : y + (BOARD_SIZE - xMin), player))
							possibleMoves.emplace(xMin, (boardSide == 1) ? y - xMin : y + (BOARD_SIZE - xMin));
						xMin++;
					}
				}
			}
			// Anti-Diagonal axis
			boardSide = (x < BOARD_SIZE - stone.second) ? 1 : 2;
			x = stone.first;
			y = rotateY315(x, stone.second);
			firstPlayerBitboard = _firstPlayerBoardAntiDiagonals[y];
			secondPlayerBitboard = _secondPlayerBoardAntiDiagonals[y];
			// Anti-Diagonal axis, up direction
			if ((boardSide == 1 && x + 3 <= BOARD_SIZE - y) || (boardSide == 2 && x + 3 <= BOARD_SIZE - 1)) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					if (boardSide == 1) {
						xMin = (x - 4 < 0) ? x : x - 4;
						xMax = (x + 1 >= BOARD_SIZE - y) ? BOARD_SIZE - y - 1 : x + 1;
					}
					else {
						xMin = (x - 4 < BOARD_SIZE - y) ? BOARD_SIZE - y - 1 : x - 4;
						xMax = (x + 1 > BOARD_SIZE - 1) ? BOARD_SIZE - 1 : x + 1;
					}

					while (xMin < xMax) {
						if (isLegalMove(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin), player))
							possibleMoves.emplace(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin));
						xMin++;
					}
				}
			}
			// Anti-Diagonal axis, down direction
			if ((boardSide == 1 && x - 3 >= 0) || (boardSide == 2 && x - 3 >= BOARD_SIZE - y)) {
				int xMin = 0;
				int xMax = 0;
				uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
				uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

				if (firstPlayerSelection == patterns[i] || secondPlayerSelection == patterns[i]) {
					if (boardSide == 1) {
						xMin = (x - 4 < 0) ? x : x - 4;
						xMax = (x + 1 >= BOARD_SIZE - y) ? y : x + 1;
					}
					else {
						xMin = (x - 4 <= BOARD_SIZE - y) ? BOARD_SIZE - y : x - 4;
						xMax = (x + 1 > BOARD_SIZE - 1) ? BOARD_SIZE - 1 : x + 1;
					}

					while (xMin < xMax) {
						if (isLegalMove(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin), player))
							possibleMoves.emplace(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin));
						xMin++;
					}
				}
			}
		}
	}
	return (possibleMoves);
} */

void	Bitboard::printBoard(){
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoardDiagonals[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoardDiagonals[y] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}

void	Bitboard::clear() {
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
	_firstPlayerBoardDiagonals.fill(0);
	_secondPlayerBoardDiagonals.fill(0);
	_firstPlayerBoardAntiDiagonals.fill(0);
	_secondPlayerBoardAntiDiagonals.fill(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_generate_moves.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:04:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/10 13:56:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

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

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generateMoves(int player) {
	uint32_t patterns[PATTERNS_OF_FOUR] = {
		0b1100, 0b0011, 0b1110, 0b0111, 0b1111,
		0b1001, 0b1010, 0b0101, 0b1011, 0b1101
	};
	
	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	std::unordered_set<std::pair<int, int>, pair_hash>		possibleMoves;

	for (auto& stone : currentStones) {
		for (int i = 0; i < 10; i++) {
			generateMovesHorizontal(possibleMoves, stone, patterns, i, player);
			generateMovesVertical(possibleMoves, stone, patterns, i, player);
			generateMovesDiagonal(possibleMoves, stone, patterns, i, player);
		}
	}
	
	return (possibleMoves);
}

void	Bitboard::generateMovesHorizontal(std::unordered_set<std::pair<int, int>, pair_hash>& possibleMoves, std::pair<int, int> stone, uint32_t patterns[], int patternIndex, int player) {
	int x = stone.first;
	int y = stone.second;

	uint32_t firstPlayerBitboard = _firstPlayerBoardLines[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardLines[y];

	if (x + 3 < BOARD_SIZE) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 1 > 0) ? x - 1 : x;
			xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(xMin, y, player))
					possibleMoves.emplace(xMin, y);
				xMin++;
			} 
		}
	}
	
	if (x - 3 > 0) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 4 > 0) ? x - 4 : 0;
			xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(xMin, y, player))
					possibleMoves.emplace(xMin, y);
				xMin++;
			}
		}
	}
}

void	Bitboard::generateMovesVertical(std::unordered_set<std::pair<int, int>, pair_hash>& possibleMoves, std::pair<int, int> stone, uint32_t patterns[], int patternIndex, int player) {
	int x = stone.second;
	int y = stone.first;

	uint32_t firstPlayerBitboard = _firstPlayerBoardColumns[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardColumns[y];

	if (x + 3 < BOARD_SIZE) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 1 > 0) ? x - 1 : x;
			xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(y, xMin, player))
					possibleMoves.emplace(y, xMin);
				xMin++;
			} 
		}
	}
	
	if (x - 3 > 0) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 4 > 0) ? x - 4 : 0;
			xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(y, xMin, player))
					possibleMoves.emplace(y, xMin);
				xMin++;
			}
		}
	}
}

void	Bitboard::generateMovesDiagonal(std::unordered_set<std::pair<int, int>, pair_hash>& possibleMoves, std::pair<int, int> stone, uint32_t patterns[], int patternIndex, int player) {
	int boardSide = (stone.first + stone.second < BOARD_SIZE) ? 1 : 2;
	int x = stone.first;
	int y = rotateY45(x, stone.second);
	
	uint32_t firstPlayerBitboard = _firstPlayerBoardDiagonals[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardDiagonals[y];
	
	if ((boardSide == 1 && x + 3 < y + 1) || (boardSide == 2 && x + 3 < BOARD_SIZE)) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);
		
		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
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
	
	if ((boardSide == 1 && x - 3 >= 0) || (boardSide == 2 && x - 3 > y + 1)) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
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
}

void	Bitboard::generateMovesAntiDiagonal(std::unordered_set<std::pair<int, int>, pair_hash>& possibleMoves, std::pair<int, int> stone, uint32_t patterns[], int patternIndex, int player) {
	int boardSide = (stone.first < stone.second + 1) ? 1 : 2;
	int x = stone.first;
	int y = rotateY315(x, stone.second);
	
	uint32_t firstPlayerBitboard = _firstPlayerBoardAntiDiagonals[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardAntiDiagonals[y];
	
	if ((boardSide == 1 && x + 3 < BOARD_SIZE - y) || (boardSide == 2 && x + 3 < BOARD_SIZE)) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);
		
		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			if (boardSide == 1) {
				xMin = (x - 1 < 0) ? x : x - 1;
				xMax = (x + 4 >= BOARD_SIZE - y) ? BOARD_SIZE - y : x + 4;
			}
			else {
				xMin = (x - 1 < BOARD_SIZE - y) ? BOARD_SIZE - y : x - 1;
				xMax = (x + 4 > BOARD_SIZE) ? BOARD_SIZE : x + 4;
			}
			
			while (xMin < xMax) {
				if (isLegalMove(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin), player))
					possibleMoves.emplace(xMin, (boardSide == 1) ? y + xMin : y - (BOARD_SIZE + xMin));
				xMin++;
			}
		}
	}
	
	if ((boardSide == 1 && x - 3 >= 0) || (boardSide == 2 && x - 3 >= BOARD_SIZE - y)) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
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
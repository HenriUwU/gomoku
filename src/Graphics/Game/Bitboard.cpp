/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/09/09 14:00:46 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

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
	makeCapture(x, y, player);

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
					placeStoneAI(x, y, 1);
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
					placeStoneAI(x, y, 2);
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

void	Bitboard::placeStoneAI(int x, int y, int player) {
	uint32_t	mask = uint32_t(1) << x;

	(player == 1) ? _firstPlayerBoardLines[y] |= mask : _secondPlayerBoardLines[y] |= mask;
	update(x, y, player, true);
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
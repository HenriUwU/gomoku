/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:19 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 20:00:51 by hsebille         ###   ########.fr       */
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

	if (isGameOver() || (playersCaptures[0] == 5 || playersCaptures[1] == 5) || fifthCaptureAvailable()) {
		if (player == 1)
			endGameState = P1VICTORY;
		else if (player == 2 && gameState != AIVERSUS)
			endGameState = P2VICTORY;
		else
			endGameState = AIVICTORY;
	}
	return (true);
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
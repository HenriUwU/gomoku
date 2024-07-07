/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/07 16:10:33 by hsebille         ###   ########.fr       */
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

	createColumns();
	createDiagonals();
	createAntiDiagonals();

	makeCapture(x, y, player);

	if (fiveInARow(x, y, player))
		gameState = MENU;

	return (true);
}

void	Bitboard::placeStoneAI(int x, int y, int player) {
	uint32_t	mask = uint32_t(1) << x;

	(player == 1) ? _firstPlayerBoardLines[y] |= mask : _secondPlayerBoardLines[y] |= mask;

	createColumns();
	createDiagonals();
	createAntiDiagonals();
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

void	Bitboard::removeStone(int x, int y, int player) {
	uint32_t mask = uint32_t(1) << x;

	if (getBit(x, y)) {
		if (player == 1) {
			_firstPlayerBoardLines[y] &= ~mask;
		} else {
			_secondPlayerBoardLines[y] &= ~mask;
		}
		createColumns();
		createDiagonals();
		createAntiDiagonals();
	}
}

bool	Bitboard::isLegalMove(int x, int y, int player) {
	if (getBit(x, y))
		return (false);

	if (isDoubleThree(x, y, player) && !isCapturingMove(x, y, player))
		return (false);
	return (true);
}

std::vector<std::pair<int, int>>	Bitboard::getAllStones() {
	std::vector<std::pair<int, int>>	stones;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (getBit(x, y)) {
				stones.push_back(std::make_pair(x, y));
			}
		}
	}
	return (stones);
}

std::vector<std::pair<int, int>>	Bitboard::generatePossibleMoves(int player) {
	std::vector<std::pair<int, int>>	currentStones = getAllStones();
	std::vector<std::pair<int, int>>	possibleMoves;
	std::set<std::pair<int, int>>		uniqueMoves;
	int margin = 2;

	for (auto& stone : currentStones) {
		int startX = std::max(0, stone.first - margin);
		int endX = std::min(BOARD_SIZE - 1, stone.first + margin);
		int startY = std::max(0, stone.second - margin);
		int endY = std::min(BOARD_SIZE - 1, stone.second + margin);

		for (int x = startX; x <= endX; ++x) {
			for (int y = startY; y <= endY; ++y) {
				if (!getBit(x, y) && isLegalMove(x, y, player)) {
					uniqueMoves.insert({x, y});
				}
			}
		}
	}

	possibleMoves.assign(uniqueMoves.begin(), uniqueMoves.end());
	return (possibleMoves);
}

void	Bitboard::printBoard(){
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoardLines[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoardLines[y] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}
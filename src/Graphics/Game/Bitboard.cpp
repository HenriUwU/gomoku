/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/02 21:36:06 by hsebille         ###   ########.fr       */
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

void	Bitboard::removeStone(int x, int y, int player) {
	uint32_t	mask = uint32_t(1) << x;
	
	(player == 1) ? _secondPlayerBoardLines[y] ^= mask : _firstPlayerBoardLines[y] ^= mask;
}

bool	Bitboard::isLegalMove(int x, int y, int player) {
	if (getBit(x, y))
		return (false);

	if (isDoubleThree(x, y, player) && !isCapturingMove(x, y, player))
		return (false);
	return (true);
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
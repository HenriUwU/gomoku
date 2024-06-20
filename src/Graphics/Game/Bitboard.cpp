/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/20 13:59:25 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

Bitboard::Bitboard() {
	//--- Initialize the bitboards and set all bits to 0 ---//
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
}

Bitboard::~Bitboard() {}

bool	Bitboard::placeStone(int x, int y, int player) {
	uint32_t	mask;
	
	mask = uint32_t(1) << x;

	//--- Verfify if cell is empty ---//
	if (getBit(x, y) != 0)
		return (false);
	//--- Place the stone ---//
	if (player == 1)
		_firstPlayerBoardLines[y] |= mask;
	else
		_secondPlayerBoardLines[y] |= mask;
	createColumns();
	//createDiagonals();
	return (true);
}

void	Bitboard::createColumns() {
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			uint32_t	mask;
			
			mask = uint32_t(1) << y;
			if (getBit(x, y) == 1)
				_firstPlayerBoardColumns[x] |= mask;
			else if (getBit(x, y) == 2)
				_secondPlayerBoardColumns[x] |= mask;
		}
	}
}

/* void	Bitboard::createDiagonals() {
	for (int diagonalSize = 0; diagonalSize < BOARD_SIZE * 2 + 1; diagonalSize++) {
		int x = BOARD_SIZE - 1;
		int y = 0;

		if (x > 0)
			x--;
		for (int diagonal = 0; diagonal + x < BOARD_SIZE; diagonal++) {
			uint32_t	mask;

			mask = uint32_t(1) << (diagonal + x);
			if (getBit(diagonal + x, y) == 1)
				_firstPlayerBoardDiagonals[diagonalSize] |= mask;
			else if (getBit(diagonal + x, y) == 2)
				_secondPlayerBoardDiagonals[diagonalSize] |= mask;
			y++;
		}
	}
} */

void	Bitboard::printBoard() {
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

int	Bitboard::getBit(int x, int y) const {
	uint32_t	mask;

	mask = uint32_t(1) << x;
	if (_firstPlayerBoardLines[y] & mask)
		return (1);
	else if (_secondPlayerBoardLines[y] & mask)
		return (2);
		
	return (0);
}

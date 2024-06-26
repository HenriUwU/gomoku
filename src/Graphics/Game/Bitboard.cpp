/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/26 12:03:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

Bitboard::Bitboard() {
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
}

Bitboard::~Bitboard() {}

bool	Bitboard::placeStone(int x, int y, int player) {
	uint32_t	mask;
	
	mask = uint32_t(1) << x;

	if (isCapturingMove(x, y, player))
		std::cout << "Capture" << std::endl;

	if (getBit(x, y) != 0)
		return (false);
	if (player == 1)
		_firstPlayerBoardLines[y] |= mask;
	else
		_secondPlayerBoardLines[y] |= mask;
	createColumns();
	createDiagonals();
	createAntiDiagonals();
	return (true);
}

int	Bitboard::rotateY45(int x, int y) {
	if (x + y < BOARD_SIZE) {
		return (x + y);
	}
	else
		return (y - (BOARD_SIZE - x));
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
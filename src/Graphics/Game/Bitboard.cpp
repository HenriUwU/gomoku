/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 15:19:59 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

Bitboard::Bitboard() {
	//--- Initialize the bitboards and set all bits to 0 ---//
	_firstPlayerBoard.fill(0);
	_secondPlayerBoard.fill(0);
}

Bitboard::~Bitboard() {}

void	Bitboard::placeStone(int x, int y, int player) {
	uint32_t	mask;
	
	mask = uint32_t(1) << x;

	//--- Verfify if cell is empty ---//
	if ((_firstPlayerBoard[y] & mask) || (_secondPlayerBoard[y] & mask))
		return;
	
	//--- Place the stone ---//
	if (player == 1)
		_firstPlayerBoard[y] |= mask;
	else
		_secondPlayerBoard[y] |= mask;
}

void	Bitboard::printBoard() {
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoard[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoard[y] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}

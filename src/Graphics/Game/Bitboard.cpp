/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 13:20:15 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

Bitboard::Bitboard() {
	//--- Initialize the bitboards and set all bits to 0 ---//
	_firstPlayerBoard.fill(0);
	_secondPlayerBoard.fill(0);
}

Bitboard::~Bitboard() {}

void	Bitboard::getBitPosition(int x, int y, int &bitboardIndex, int &bitPosition) {
	int pos;
	
	//---- Get the position of the bit in the bitboard ---//
	pos = BOARD_SIZE * y + x;

	//--- Get the index of the bitboard ---//
	bitboardIndex = pos / 64;

	//--- Get the position of the bit in the corresponding index ---//
	bitPosition = pos % 64;
}

void	Bitboard::placeStone(int x, int y, int player) {
	int			bitboardIndex;
	int			bitPosition;
	uint64_t	mask;

	if (!isCellEmpty(x, y))
		return ;
	getBitPosition(x, y, bitboardIndex, bitPosition);
	
	mask = uint64_t(1) << bitPosition;
	if (player == 1)
		_firstPlayerBoard[bitboardIndex] |= mask;
	else
		_secondPlayerBoard[bitboardIndex] |= mask;
}

bool	Bitboard::isCellEmpty(int x, int y) {
	int			bitboardIndex;
	int			bitPosition;
	uint64_t	mask;

	getBitPosition(x, y, bitboardIndex, bitPosition);
	
	mask = uint64_t(1) << bitPosition;
	if ((_firstPlayerBoard[bitboardIndex] & mask) || (_secondPlayerBoard[bitboardIndex] & mask))
		return (false);
	return (true);
}

void	Bitboard::printBoard() {
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			int bitboardIndex;
			int bitPosition;

			getBitPosition(x, y, bitboardIndex, bitPosition);
			uint64_t mask = uint64_t(1) << bitPosition;

			if (_firstPlayerBoard[bitboardIndex] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoard[bitboardIndex] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}

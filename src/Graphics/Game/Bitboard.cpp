/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 12:46:56 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

Bitboard::Bitboard() {
	//--- Initialize the bitboards and set all bits to 0 ---//
	_firstPlayerBoard.fill(0);
	_secondPlayerBoard.fill(0);
}

Bitboard::~Bitboard() {}

void	Bitboard::getBitPosition(int x, int y, int &bitboardIndex, int &bitboardPosition) {
	int pos;
	
	//---- Get the position of the bit in the bitboard ---//
	pos = BOARD_SIZE * y + x;

	//--- Get the index of the bitboard ---//
	bitboardIndex = pos / 64;

	//--- Get the position of the bit in the corresponding index ---//
	bitboardPosition = pos % 64;
}

void	Bitboard::placeStone(int x, int y, int player) {
	int			bitboardIndex;
	int			bitboardPosition;
	uint64_t	mask;

	if (!isCellEmpty(x, y))
		return ;
	getBitPosition(x, y, bitboardIndex, bitboardPosition);
	
	mask = uint64_t(1) << bitboardPosition;
	if (player == 1)
		_firstPlayerBoard[bitboardIndex] |= mask;
	else
		_secondPlayerBoard[bitboardIndex] |= mask;
}

bool	Bitboard::isCellEmpty(int x, int y) {
	int			bitboardIndex;
	int			bitboardPosition;
	uint64_t	mask;

	getBitPosition(x, y, bitboardIndex, bitboardPosition);
	
	mask = uint64_t(1) << bitboardPosition;
	if ((_firstPlayerBoard[bitboardIndex] & mask) || (_secondPlayerBoard[bitboardIndex] & mask))
		return (false);
	return (true);
}

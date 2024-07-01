/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:57:17 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/01 11:12:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

uint32_t	Bitboard::getSelection(uint32_t bitboard, int nbBits, int bitsPos) {
	bitboard >>= bitsPos;

	uint32_t mask = (1 << nbBits) - 1;
	uint32_t selection = bitboard & mask;

	return (selection);
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

int	getBit2(int x, int y, std::array<uint32_t, 19> bitboard) { // need to change name and eventually remove the other getBit
	uint32_t	mask;

	mask = uint32_t(1) << x;
	if (bitboard[y] & mask)
		return (1);
		
	return (0);
}

int	Bitboard::rotateY45(int x, int y) {
	if (x + y < BOARD_SIZE) //BOARD_SIZE == 1
		return (x + y);
	else
		return (y - (BOARD_SIZE - x)); //BOARD_SIZE == 2
}

int	Bitboard::rotateY315(int x, int y) {
	if (x < y + 1) //BOARD_SIZE == 1
		return (y - x);
	else
		return (y + (BOARD_SIZE - x)); //BOARD_SIZE == 2
}

static void	rotate(int nbRotations, uint32_t& bitboard) {
	for (int i = 0; i < nbRotations; i++) {
		bitboard <<= 1;
		
		uint32_t bitSelector = uint(1) << 19;
		if (bitboard & bitSelector) {
			uint32_t rotatingMask = uint32_t(1) << 0;
			uint32_t xorMask = uint32_t(1) << 19;
			bitboard |= rotatingMask;
			bitboard ^= xorMask;
		}
	}
}

void	Bitboard::createColumns() {
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);

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

void	Bitboard::createDiagonals() {
	std::array<uint32_t, BOARD_SIZE> firstPlayerBoardColumnsCopy = _firstPlayerBoardColumns;
	std::array<uint32_t, BOARD_SIZE> secondPlayerBoardColumnsCopy = _secondPlayerBoardColumns;
	
	_firstPlayerBoardDiagonals.fill(0);
	_secondPlayerBoardDiagonals.fill(0);

	for (int y = 0; y < BOARD_SIZE; y++) {
		rotate(y, firstPlayerBoardColumnsCopy[y]);
		rotate(y, secondPlayerBoardColumnsCopy[y]);
	}
	
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			uint32_t mask;

			mask = uint32_t(1) << y;
			if (getBit2(x, y, firstPlayerBoardColumnsCopy))
				_firstPlayerBoardDiagonals[x] |= mask;
			else if (getBit2(x, y, secondPlayerBoardColumnsCopy))
				_secondPlayerBoardDiagonals[x] |= mask;
		}
	}
}

void	Bitboard::createAntiDiagonals() {
	std::array<uint32_t, BOARD_SIZE> firstPlayerBoardColumnsCopy = _firstPlayerBoardColumns;
	std::array<uint32_t, BOARD_SIZE> secondPlayerBoardColumnsCopy = _secondPlayerBoardColumns;
	
	_firstPlayerBoardAntiDiagonals.fill(0);
	_secondPlayerBoardAntiDiagonals.fill(0);

	for (int y = 0; y < BOARD_SIZE; y++) {
		rotate(BOARD_SIZE - y, firstPlayerBoardColumnsCopy[y]);
		rotate(BOARD_SIZE - y, secondPlayerBoardColumnsCopy[y]);
	}
	
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			uint32_t mask;

			mask = uint32_t(1) << y;
			if (getBit2(x, y, firstPlayerBoardColumnsCopy))
				_firstPlayerBoardAntiDiagonals[x] |= mask;
			else if (getBit2(x, y, secondPlayerBoardColumnsCopy))
				_secondPlayerBoardAntiDiagonals[x] |= mask;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/22 17:32:34 by laprieur         ###   ########.fr       */
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
	createDiagonals();
	createAntiDiagonals();
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
	// 1. Get the two vertex
	// 2. Define number of stones between vertex
	// 3. Get stones between vertex
	
	// origin = BOARD_SIZE
	// x = BOARD_SIZE
	// y = 0
	
	uint32_t mask = uint32_t(1) << 0;
	if (getBit(BOARD_SIZE - 1, 0) == 1)
		_firstPlayerBoardDiagonals[0] |= mask;
	else if (getBit(BOARD_SIZE - 1, 0) == 2)
		_secondPlayerBoardDiagonals[0] |= mask;
	
	for (int y = 1; y < BOARD_SIZE; y++) {
		for (int x = BOARD_SIZE - 2; x > 0; x--) {
			
			int nbStonesBetweenVertex = y - 1;
			
			uint32_t mask1 = uint32_t(1) << 0;
			if (getBit(x, 0) == 1)
				_firstPlayerBoardDiagonals[y] |= mask1;
			else if (getBit(x, 0) == 2)
				_secondPlayerBoardDiagonals[y] |= mask1;
			
			uint32_t mask2 = uint32_t(1) << (y + 1);
			if (getBit(BOARD_SIZE - 1, y) == 1)
				_firstPlayerBoardDiagonals[y] |= mask2;
			else if (getBit(BOARD_SIZE - 1, y) == 2)
				_secondPlayerBoardDiagonals[y] |= mask2;
			
			if (nbStonesBetweenVertex > 0) {
				for (int i = 1; i <= nbStonesBetweenVertex; i++) {
					uint32_t mask = uint32_t(1) << i;
					if (getBit(x + i, y) == 1)
						_firstPlayerBoardDiagonals[y - 1] |= mask;
					else if (getBit(x + i, y) == 2)
						_secondPlayerBoardDiagonals[y - 1] |= mask;
				}
			}
		}
	}
} */

void	rotate(int nbRotations, uint32_t& bitboard) {
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

int	getBit2(int x, int y, std::array<uint32_t, 19> bitboard) {
	uint32_t	mask;

	mask = uint32_t(1) << x;
	if (bitboard[y] & mask)
		return (1);
		
	return (0);
}

void	printBoard2(std::array<uint32_t, 19> copy1, std::array<uint32_t, 19> copy2) {
	for (int y = 0; y < 19; ++y) {
		for (int x = 0; x < 19; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (copy1[y] & mask) {
				std::cout << "1 ";
			} else if (copy2[y] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
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

void	Bitboard::printBoard(){
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoardAntiDiagonals[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoardAntiDiagonals[y] & mask) {
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/25 16:28:07 by hsebille         ###   ########.fr       */
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
		std::cout << "Capture by player " << player << " detected" << std::endl;

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

int	Bitboard::isCapturingMove(int x, int y, int player) {
	int			nbCaptures = 0;
	uint32_t	linesBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	linesMask = uint32_t(1) << x;
	
	linesBitboard |= linesMask;
	// Lines
	if (x <= 15) {
		uint32_t rightSelection = getSelection(linesBitboard, 4, x); // according to board direction
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (x >= 3) {
		uint32_t leftSelection = getSelection(linesBitboard, 4, x - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}

	// Columns
	uint32_t	columnsBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	columnsMask = uint32_t(1) << y;
	
	columnsBitboard |= columnsMask;
	if (y <= 15) {
		uint32_t rightSelection = getSelection(columnsBitboard, 4, y); // according to board direction
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (y >= 3) {
		uint32_t leftSelection = getSelection(columnsBitboard, 4, y - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}

	//Diagonals
	uint32_t	diagonalsBitboard = (player == 1) ? _firstPlayerBoardDiagonals[x] : _secondPlayerBoardDiagonals[x];
	uint32_t	diagonalsMask = uint32_t(1) << y;
	
	diagonalsBitboard |= diagonalsMask;
	return nbCaptures;
}

uint32_t	Bitboard::getSelection(uint32_t bitboard, int nbBits, int bitsPos) {
	bitboard >>= bitsPos;

	uint32_t mask = (1 << nbBits) - 1;
	uint32_t selection = bitboard & mask;

	return (selection);
}

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

int	Bitboard::getBit(int x, int y) const {
	uint32_t	mask;

	mask = uint32_t(1) << x;
	if (_firstPlayerBoardLines[y] & mask)
		return (1);
	else if (_secondPlayerBoardLines[y] & mask)
		return (2);
		
	return (0);
}

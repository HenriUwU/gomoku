/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:57:17 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/09 20:00:42 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

int Bitboard::hash() {
	int hash = 0;

	// Iterate over each line in all directions
	for (int i = 0; i < BOARD_SIZE; ++i) {
		// Mix first player data
		hash ^= _firstPlayerBoardLines[i] * (i + 1);
		hash ^= _firstPlayerBoardColumns[i] * (i + 2);
		hash ^= _firstPlayerBoardDiagonals[i] * (i + 3);
		hash ^= _firstPlayerBoardAntiDiagonals[i] * (i + 4);

		// Mix second player data
		hash ^= _secondPlayerBoardLines[i] * (i + 5);
		hash ^= _secondPlayerBoardColumns[i] * (i + 6);
		hash ^= _secondPlayerBoardDiagonals[i] * (i + 7);
		hash ^= _secondPlayerBoardAntiDiagonals[i] * (i + 8);
	}

	// Apply bit shifts and XOR to mix the bits more
	hash ^= (hash << 13); // Left shift and XOR for bit mixing
	hash ^= (hash >> 17); // Right shift and XOR for further mixing
	hash ^= (hash << 5);  // Another left shift and XOR to finalize mixing

	// Ensure the hash is non-negative (optional, but good practice)
	if (hash < 0) {
		hash = -hash;
	}

	return hash;
}

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

int Bitboard::reverseRotate45(int x, int y) {
	if (x + y < BOARD_SIZE)
		return (y - x);
	else
		return (y + (BOARD_SIZE - x));
}

int Bitboard::reverseRotate315(int x, int y) {
	if (x < y + 1)
		return (y + x);
	else
		return (y - (BOARD_SIZE + x));
}

int	Bitboard::rotateY45(int x, int y) {
	if (x + y < BOARD_SIZE)
		return (x + y);
	else
		return (y - (BOARD_SIZE - x));
}

int	Bitboard::rotateY315(int x, int y) {
	if (x < y + 1)
		return (y - x);
	else
		return (y + (BOARD_SIZE - x));
}

void Bitboard::update(int x, int y, int player, bool add) {
	uint32_t mask = uint32_t(1) << x;

	if (player == 1) {
		if (add) {
			_firstPlayerBoardLines[y] |= mask;
		} else {
			_firstPlayerBoardLines[y] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardLines[y] |= mask;
		} else {
			_secondPlayerBoardLines[y] &= ~mask;
		}
	}

	uint32_t columnMask = uint32_t(1) << y;
	if (player == 1) {
		if (add) {
			_firstPlayerBoardColumns[x] |= columnMask;
		} else {
			_firstPlayerBoardColumns[x] &= ~columnMask;
		}
	} else {
		if (add) {
			_secondPlayerBoardColumns[x] |= columnMask;
		} else {
			_secondPlayerBoardColumns[x] &= ~columnMask;
		}
	}

	int diagIndex = rotateY45(x, y);
	if (player == 1) {
		if (add) {
			_firstPlayerBoardDiagonals[diagIndex] |= mask;
		} else {
			_firstPlayerBoardDiagonals[diagIndex] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardDiagonals[diagIndex] |= mask;
		} else {
			_secondPlayerBoardDiagonals[diagIndex] &= ~mask;
		}
	}

	int antiDiagIndex = rotateY315(x, y);
	if (player == 1) {
		if (add) {
			_firstPlayerBoardAntiDiagonals[antiDiagIndex] |= mask;
		} else {
			_firstPlayerBoardAntiDiagonals[antiDiagIndex] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardAntiDiagonals[antiDiagIndex] |= mask;
		} else {
			_secondPlayerBoardAntiDiagonals[antiDiagIndex] &= ~mask;
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

void	Bitboard::clear() {
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
	_firstPlayerBoardDiagonals.fill(0);
	_secondPlayerBoardDiagonals.fill(0);
	_firstPlayerBoardAntiDiagonals.fill(0);
	_secondPlayerBoardAntiDiagonals.fill(0);
}
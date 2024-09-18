/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:57:17 by hsebille          #+#    #+#             */
/*   Updated: 2024/09/18 12:03:59 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_double-three.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:21:52 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 14:35:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

uint32_t pPatterns[3]   = { 0b01110,  0b010110, 0b011010 };
uint32_t o5Patterns[3]  = { 0b10000,  0b00001,  0b10001  };
uint32_t o6Patterns[6]  = { 0b100000, 0b000001,
                            0b001000, 0b101001,
                            0b000100, 0b100101           };

bool	Bitboard::isDoubleThree(int x, int y, int player) {
	int	nbFreeThree = 0;

	verifyFreeThreeHorizontal(nbFreeThree, x, y, player);
	if (nbFreeThree >= 2) {
		return (true);
	}
	verifyFreeThreeVertical(nbFreeThree, x, y, player);
	if (nbFreeThree >= 2) {
		return (true);
	}
	verifyFreeThreeDiagonal(nbFreeThree, x, y, player);
	if (nbFreeThree >= 2) {
		return (true);
	}
	verifyFreeThreeAntiDiagonal(nbFreeThree, x, y, player);
	if (nbFreeThree >= 2) {
		return (true);
	}

	return (false);
}

static bool verifyPlayerPattern(uint32_t selection, int nbBits) {
    if (nbBits == 5) {
        if (pPatterns[0] == selection)
            return true;
    } else {
        for (int i = 1; i < 3; i++)
            if (pPatterns[i] == selection)
                return true;
    }
    return false;
}

static bool verifyOpponentPattern(uint32_t selection, int nbBits) {
    if (nbBits == 5) {
        for (int i = 0; i < 3; i++)
            if (o5Patterns[i] == selection)
                return true;
    } else {
        for (int i = 0; i < 6; i++)
            if (o6Patterns[i] == selection)
                return true;
    }
    return false;
}

void Bitboard::verifyFreeThree(int &nbFreeThree, int x, int y, int player, bool isVertical, bool isDiagonal, bool isAntiDiagonal) {
    uint32_t pBitboard, oBitboard;
    uint32_t pSelection = 0, oSelection = 0;
    uint32_t pBitboardMask = uint32_t(1) << (isVertical ? y : x);
    int nbBits = 0;

    if (isVertical) {
        pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
        oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
    } else if (isDiagonal) {
        y = rotateY45(x, y);
        pBitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
        oBitboard = (player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];
    } else if (isAntiDiagonal) {
        y = rotateY315(x, y);
        pBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
        oBitboard = (player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];
    } else {
        pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
        oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
    }

    pBitboard |= pBitboardMask;

    // Determine nbBits based on the position
    if ((isVertical && y - 4 < 0) || (isDiagonal && !isAntiDiagonal && y >= 4)) {
        nbBits = 5 + (isVertical ? y : x);
        pSelection = getSelection(pBitboard, nbBits, 0);
        oSelection = getSelection(oBitboard, nbBits, 0);
    } else if ((isVertical && y + 4 > BOARD_SIZE - 1) || (isDiagonal && isAntiDiagonal && y < 14)) {
        nbBits = (isVertical ? BOARD_SIZE - (y - 4) : (BOARD_SIZE - y) - (x - 4));
        pSelection = getSelection(pBitboard, nbBits, (isVertical ? y - 4 : x - 4));
        oSelection = getSelection(oBitboard, nbBits, (isVertical ? y - 4 : x - 4));
    } else {
        nbBits = 9;
        pSelection = getSelection(pBitboard, nbBits, (isVertical ? y - 4 : x - 4));
        oSelection = getSelection(oBitboard, nbBits, (isVertical ? y - 4 : x - 4));
    }

    // Check for free three patterns
    for (int i = 0; i < nbBits; i++) {
        if (i + 5 <= nbBits) {
            uint32_t pFive = getSelection(pSelection, 5, i);
            uint32_t oFive = getSelection(oSelection, 5, i);
            if (verifyPlayerPattern(pFive, 5) && !verifyOpponentPattern(oFive, 5))
                nbFreeThree++;
        }
        if (i + 6 <= nbBits) {
            uint32_t pSix = getSelection(pSelection, 6, i);
            uint32_t oSix = getSelection(oSelection, 6, i);
            if (verifyPlayerPattern(pSix, 6) && !verifyOpponentPattern(oSix, 6))
                nbFreeThree++;
        }
    }
}

// Specific functions for each direction
void Bitboard::verifyFreeThreeHorizontal(int &nbFreeThree, int x, int y, int player) {
    verifyFreeThree(nbFreeThree, x, y, player, false, false, false);
}

void Bitboard::verifyFreeThreeVertical(int &nbFreeThree, int x, int y, int player) {
    verifyFreeThree(nbFreeThree, x, y, player, true, false, false);
}

void Bitboard::verifyFreeThreeDiagonal(int &nbFreeThree, int x, int y, int player) {
    verifyFreeThree(nbFreeThree, x, y, player, false, true, false);
}

void Bitboard::verifyFreeThreeAntiDiagonal(int &nbFreeThree, int x, int y, int player) {
    verifyFreeThree(nbFreeThree, x, y, player, false, false, true);
}


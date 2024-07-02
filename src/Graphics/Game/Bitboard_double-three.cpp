/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_double-three.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:21:52 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/02 11:31:36 by laprieur         ###   ########.fr       */
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
	verifyFreeThreeVertical(nbFreeThree, x, y, player);
	verifyFreeThreeDiagonal(nbFreeThree, x, y, player);
	verifyFreeThreeAntiDiagonal(nbFreeThree, x, y, player);

	if (nbFreeThree >= 2)
		return (true);
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

void	Bitboard::verifyFreeThreeHorizontal(int &nbFreeThree, int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	uint32_t	pBitboardMask = uint32_t(1) << x;
	int			nbBits = 0;

	pBitboard |= pBitboardMask;
	
	if (x - 4 < 0) {
		nbBits = 9 - x;
		pSelection = getSelection(pBitboard, nbBits, 0);
		oSelection = getSelection(oBitboard, nbBits, 0);
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 4);
		pSelection = getSelection(pBitboard, nbBits, x - 4);
		oSelection = getSelection(oBitboard, nbBits, x - 4);
	} else {
		nbBits = 9;
		pSelection = getSelection(pBitboard, nbBits, x - 4);
		oSelection = getSelection(oBitboard, nbBits, x - 4);
	}
		
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

void	Bitboard::verifyFreeThreeVertical(int &nbFreeThree, int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	uint32_t	pBitboardMask = uint32_t(1) << y;
	int			nbBits = 0;

	pBitboard |= pBitboardMask;
	
	if (y - 4 < 0) {
		nbBits = 9 - y;
		pSelection = getSelection(pBitboard, nbBits, 0);
		oSelection = getSelection(oBitboard, nbBits, 0);
	} else if (y + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (y - 4);
		pSelection = getSelection(pBitboard, nbBits, y - 4);
		oSelection = getSelection(oBitboard, nbBits, y - 4);
	} else {
		nbBits = 9;
		pSelection = getSelection(pBitboard, nbBits, y - 4);
		oSelection = getSelection(oBitboard, nbBits, y - 4);
	}
		
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

void	Bitboard::verifyFreeThreeDiagonal(int &nbFreeThree, int x, int y, int player) {
	int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
	y = rotateY45(x, y);

	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	uint32_t	pBitboardMask = uint32_t(1) << x;
	int			nbBits = 0;
	int			bitPos = 0;

	pBitboard |= pBitboardMask;
	
	if (boardSide == 1 && y >= 4) {
		bitPos = (x - 4 <= 0) ? 0 : x - 4;
		nbBits = 9 - ((bitPos + 9) - (y + 1));
		pSelection = getSelection(pBitboard, nbBits, bitPos);
		oSelection = getSelection(oBitboard, nbBits, bitPos);
	} else if (boardSide == 2 && y <= 14) {
		bitPos = (x - 4 < y + 1) ? y + 1 : x - 4;
		nbBits = 9 - ((bitPos + 9) - BOARD_SIZE);
		pSelection = getSelection(pBitboard, nbBits, bitPos);
		oSelection = getSelection(oBitboard, nbBits, bitPos);
	}
		
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

void	Bitboard::verifyFreeThreeAntiDiagonal(int &nbFreeThree, int x, int y, int player) {
	int boardSide = (x < y + 1) ? 1 : 2;
	y = rotateY315(x, y);

	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	uint32_t	pBitboardMask = uint32_t(1) << x;
	int			nbBits = 0;
	int			bitPos = 0;

	pBitboard |= pBitboardMask;
	
	if (boardSide == 1 && y <= 14) {
		bitPos = (x - 4 <= 0) ? 0 : x - 4;
		nbBits = 9 - ((bitPos + 9) - (BOARD_SIZE - y));
		pSelection = getSelection(pBitboard, nbBits, bitPos);
		oSelection = getSelection(oBitboard, nbBits, bitPos);
	} else if (boardSide == 2 && y >= 4) {
		bitPos = (x - 4 < BOARD_SIZE - y) ? BOARD_SIZE - y : x - 4;
		nbBits = 9 - ((bitPos + 9) - BOARD_SIZE);
		pSelection = getSelection(pBitboard, nbBits, bitPos);
		oSelection = getSelection(oBitboard, nbBits, bitPos);
	}
		
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

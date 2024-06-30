/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_double-three.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:41:03 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/30 16:13:06 by laprieur         ###   ########.fr       */
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
	(void)x;
	(void)y;
	(void)player;

	verifyFreeThreeHorizontal(nbFreeThree, x, y, player);

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

	pBitboard |= pBitboardMask;
	
	if (x - 4 < 0) {
		pSelection = getSelection(pBitboard, 9 - x, 0);
		oSelection = getSelection(oBitboard, 9 - x, 0);
	}
	else if (x + 4 > BOARD_SIZE - 1) {
		pSelection = getSelection(pBitboard, BOARD_SIZE - (x - 4), x - 4);
		oSelection = getSelection(oBitboard, BOARD_SIZE - (x - 4), x - 4);
	}
	else {
		pSelection = getSelection(pBitboard, 9, x - 4);
		oSelection = getSelection(oBitboard, 9, x - 4);
	}
		
	for (int i = 0; i < 9; i++) {
		if (i + 5 <= 9) {
			uint32_t pFive = getSelection(pSelection, 5, i);
			uint32_t oFive = getSelection(oSelection, 5, i);
			std::cout << "Checking 5 bits at position " << i << ": Player " << std::bitset<5>(pFive) << ", Opponent " << std::bitset<5>(oFive) << std::endl;
			if (verifyPlayerPattern(pFive, 5) && !verifyOpponentPattern(oFive, 5)) {
				nbFreeThree++;
				std::cout << "Free-three detected!" << std::endl;
			}
		}
		if (i + 6 <= 9) {
			uint32_t pSix = getSelection(pSelection, 6, i);
			uint32_t oSix = getSelection(oSelection, 6, i);
			std::cout << "Checking 6 bits at position " << i << ": Player " << std::bitset<6>(pSix) << ", Opponent " << std::bitset<6>(oSix) << std::endl;
			if (verifyPlayerPattern(pSix, 6) && !verifyOpponentPattern(oSix, 6)) {
				nbFreeThree++;
				std::cout << "Free-three detected!" << std::endl;
			}
		}
	}
		
}

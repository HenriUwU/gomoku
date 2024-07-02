/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/02 22:18:24 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool    Bitboard::fiveInARow(int x, int y, int player) {
	if (fiveInARowHorizontal(x, y, player) || fiveInARowVertical(x, y, player))
		return (true);
	return (false);
}

bool	Bitboard::isBreakableHorizontal(int x, int y, int player) {
	uint32_t	pBitboardVertical = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	oBitboardVertical = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];	
	uint32_t	pSelectionVertical = 0;
	uint32_t	oSelectionVertical = 0;
	uint32_t	pSelectionDiagonal = 0;
	uint32_t	oSelectionDiagonal = 0;
	int			bitPos;
	int			nbBits;
	
	for (int i = 0; i < 5; i++) {
		if (y - 2 < 0) {
			nbBits = 5 - y;
			pSelectionVertical = getSelection(pBitboardVertical, nbBits, 0);
			oSelectionVertical = getSelection(oBitboardVertical, nbBits, 0);
		} else if (y + 2 > BOARD_SIZE - 1) {
			nbBits = BOARD_SIZE - (y - 2);
			pSelectionVertical = getSelection(pBitboardVertical, nbBits, y - 2);
			oSelectionVertical = getSelection(oBitboardVertical, nbBits, y - 2);
		} else {
			nbBits = 5;
			pSelectionVertical = getSelection(pBitboardVertical, nbBits, y - 2);
			oSelectionVertical = getSelection(oBitboardVertical, nbBits, y - 2);
		}
		
		if (pSelectionVertical == 0b10110 && (oSelectionVertical == 0b00001 || oSelectionVertical == 0b01000))
			return (true);
		if (pSelectionVertical == 0b01101 && (oSelectionVertical == 0b10000 || oSelectionVertical == 0b00010))
			return (true);
		if (pSelectionVertical == 0b01100 && (oSelectionVertical == 0b10001 || oSelectionVertical == 0b00011 || oSelectionVertical == 0b10000 || oSelectionVertical == 0b00010))
			return (true);
		if (pSelectionVertical == 0b00110 && (oSelectionVertical == 0b11000 || oSelectionVertical == 0b10001 || oSelectionVertical == 0b00001 || oSelectionVertical == 0b01000))
			return (true);
		
		int 	yDiagonal = rotateY45(x, y);
		int 	boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
		
		uint32_t	pBitboardDiagonal = (player == 1) ? _firstPlayerBoardDiagonals[yDiagonal] : _secondPlayerBoardDiagonals[yDiagonal];
		uint32_t	oBitboardDiagonal = (player == 1) ? _secondPlayerBoardDiagonals[yDiagonal] : _firstPlayerBoardDiagonals[yDiagonal];
		
		if (boardSide == 1 && yDiagonal >= 3) {
			std::cout << "Je ne rentre pas dedans" << std::endl;
			bitPos = (x - 2 <= 0) ? 0 : x - 2;
			nbBits = 5 - ((bitPos + 5) - (yDiagonal + 1));
			pSelectionDiagonal = getSelection(pBitboardDiagonal, nbBits, bitPos);
			oSelectionDiagonal = getSelection(oBitboardDiagonal, nbBits, bitPos);
		} else if (boardSide == 2 && yDiagonal <= 15) {
			bitPos = (x - 2 < yDiagonal + 1) ? yDiagonal + 1 : x - 2;
			nbBits = 5 - ((bitPos + 5) - BOARD_SIZE);
			pSelectionDiagonal = getSelection(pBitboardDiagonal, nbBits, bitPos);
			oSelectionDiagonal = getSelection(oBitboardDiagonal, nbBits, bitPos);
		}
		
		std::cout << "for i = " << i << " selection is : " << std::bitset<5>(pSelectionDiagonal) << std::endl;
		
		if (pSelectionDiagonal == 0b10110 && (oSelectionDiagonal == 0b00001 || oSelectionDiagonal == 0b01000))
			return (true);
		if (pSelectionDiagonal == 0b01101 && (oSelectionDiagonal == 0b10000 || oSelectionDiagonal == 0b00010))
			return (true);
		if (pSelectionDiagonal == 0b01100 && (oSelectionDiagonal == 0b10001 || oSelectionDiagonal == 0b00011 || oSelectionDiagonal == 0b10000 || oSelectionDiagonal == 0b00010))
			return (true);
		if (pSelectionDiagonal == 0b00110 && (oSelectionDiagonal == 0b11000 || oSelectionDiagonal == 0b10001 || oSelectionDiagonal == 0b00001 || oSelectionDiagonal == 0b01000))
			return (true);
		x++;
	}
	return (false);
}

bool    Bitboard::fiveInARowHorizontal(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
    uint32_t    selection = 0;
	int			bitPos = 0;
	int			nbBits = 0;

	if (x - 4 < 0) {
		nbBits = 9 - x;
		selection = getSelection(bitboard, nbBits, bitPos);
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 4);
		bitPos = x - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
	} else {
		nbBits = 9;
		bitPos = x - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 && !isBreakableHorizontal(bitPos + i, y, player))
				return true;
		}
	}
    return false;
}

bool	Bitboard::fiveInARowVertical(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
    uint32_t    selection = 0;
	int			bitPos = 0;
	int			nbBits = 0;

	if (y - 4 < 0) {
		nbBits = 9 - y;
		selection = getSelection(bitboard, nbBits, bitPos);
	} else if (y + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (y - 4);
		bitPos = y - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
	} else {
		nbBits = 9;
		bitPos = y - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111) {
				std::cout << "bitPos + i : " << bitPos + i << " x : " << x << std::endl;
				return true;
			}
		}
	}
    return false;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/02 16:35:30 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"


bool    Bitboard::fiveInARow(int x, int y, int player) {
	if (fiveInARowHorizontal(x, y, player))
		return (true);
	return (false);
}

bool    Bitboard::isBreakable(int x, int y, int player) {
    for (int i = 0; i < 5; i++) {
		uint32_t	pBitboardVertical = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
		uint32_t	oBitboardVertical = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
		uint32_t	pSelectionVertical = 0;
		uint32_t	oSelectionVertical = 0;
		int			nbBits;

		if (y - 4 < 0) {
			nbBits = 5 - y;
			pSelectionVertical = getSelection(pBitboardVertical, nbBits, 0);
			oSelectionVertical = getSelection(oBitboardVertical, nbBits, 0);
		} else if (y + 4 > BOARD_SIZE - 1) {
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
		bitPos = x -4;
		selection = getSelection(bitboard, nbBits, bitPos);
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 && !isBreakable(bitPos + i, y, player))
				return true;
		}
	}
    return false;
}
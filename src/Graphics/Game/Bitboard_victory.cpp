/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/02 20:27:58 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool    Bitboard::fiveInARow(int x, int y, int player) {
	if (fiveInARowHorizontal(x, y, player) || fiveInARowVertical(x, y, player))
		return (true);
	return (false);
}

bool	Bitboard::isBreakableHorizontal(int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			nbBits;

	if (x - 4 < 0) {
		nbBits = 5 - x;
		pSelection = getSelection(pBitboard, nbBits, 0);
		oSelection = getSelection(oBitboard, nbBits, 0);
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 2);
		pSelection = getSelection(pBitboard, nbBits, x - 2);
		oSelection = getSelection(oBitboard, nbBits, x - 2);
	} else {
		nbBits = 5;
		pSelection = getSelection(pBitboard, nbBits, x - 2);
		oSelection = getSelection(oBitboard, nbBits, x - 2);
	}

	if (pSelection == 0b10110 && (oSelection == 0b00001 || oSelection == 0b01000))
		return (true);
	if (pSelection == 0b01101 && (oSelection == 0b10000 || oSelection == 0b00010))
		return (true);
	if (pSelection == 0b01100 && (oSelection == 0b10001 || oSelection == 0b00011 || oSelection == 0b10000 || oSelection == 0b00010))
		return (true);
	if (pSelection == 0b00110 && (oSelection == 0b11000 || oSelection == 0b10001 || oSelection == 0b00001 || oSelection == 0b01000))
		return (true);
	return (false);
}

bool	Bitboard::isBreakableVertical(int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			nbBits;

	if (y - 4 < 0) {
		nbBits = 5 - y;
		pSelection = getSelection(pBitboard, nbBits, 0);
		oSelection = getSelection(oBitboard, nbBits, 0);
	} else if (y + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (y - 2);
		pSelection = getSelection(pBitboard, nbBits, y - 2);
		oSelection = getSelection(oBitboard, nbBits, y - 2);
	} else {
		nbBits = 5;
		pSelection = getSelection(pBitboard, nbBits, y - 2);
		oSelection = getSelection(oBitboard, nbBits, y - 2);
	}

	if (pSelection == 0b10110 && (oSelection == 0b00001 || oSelection == 0b01000))
		return (true);
	if (pSelection == 0b01101 && (oSelection == 0b10000 || oSelection == 0b00010))
		return (true);
	if (pSelection == 0b01100 && (oSelection == 0b10001 || oSelection == 0b00011 || oSelection == 0b10000 || oSelection == 0b00010))
		return (true);
	if (pSelection == 0b00110 && (oSelection == 0b11000 || oSelection == 0b10001 || oSelection == 0b00001 || oSelection == 0b01000))
		return (true);
	return (false);
}

bool    Bitboard::isBreakable(int x, int y, int player, int direction) {
    for (int i = 0; i < 5; i++) {
		if (isBreakableHorizontal(x, y, player) || isBreakableVertical(x, y, player))
			return true;
		if (direction == HORIZONTAL)
			x++;
		if (direction == VERTICAL)
			y++;
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
			if (five == 0b11111 && !isBreakable(bitPos + i, y, player, HORIZONTAL))
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
			if (five == 0b11111 && !isBreakable(x, bitPos + i, player, VERTICAL)) {
				std::cout << "bitPos + i : " << bitPos + i << " x : " << x << std::endl;
				return true;
			}
		}
	}
    return false;
}
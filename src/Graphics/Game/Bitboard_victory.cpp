/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/08/15 18:09:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool    Bitboard::fiveInARow(int x, int y, int player) {
	if (fiveInARowHorizontal(x, y, player))
		return (true);
	if (fiveInARowVertical(x, y, player))
		return (true);
	if (fiveInARowDiagonal(x, y, player))
		return (true);
	if (fiveInARowAntiDiagonal(x, y, player))
		return (true);
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
			if (five == 0b11111)
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
			if (five == 0b11111)
				return true;
		}
	}
    return false;
}

bool	Bitboard::fiveInARowDiagonal(int x, int y, int player) {
	int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
	y = rotateY45(x, y);

	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
	uint32_t	selection = 0;
	int			nbBits = 0;
	
	if (boardSide == 1 && y >= 4) {
		if (x - 4 <= 0) {
			nbBits = (5 + x < y + 1) ? 5 + x : y + 1;
			selection = getSelection(bitboard, nbBits, 0);
		} else if (x + 4 >= y + 1 || x + 4 > BOARD_SIZE - 1) {
			nbBits = (y + 1) - (x - 4);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	} else if (boardSide == 2 && y < 14) {
		if (x - 4 < y + 1) {
			nbBits = x - (y + 1);
			if (x + 4 > BOARD_SIZE - 1)
				nbBits += BOARD_SIZE - x;
			else
				nbBits += 5;
			selection = getSelection(bitboard, nbBits, y + 1);
		} else if (x + 4 > BOARD_SIZE - 1) {
			nbBits = 5 + ((BOARD_SIZE - 1) - x);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	}

    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111) {
				return true;
			}
		}
	}
	return (false);
}

bool	Bitboard::fiveInARowAntiDiagonal(int x, int y, int player) {
	int	boardSide = (x < y + 1) ? 1 : 2;
	y = rotateY315(x, y);

	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
	uint32_t	selection = 0;
	int			nbBits = 0;
	
	if (boardSide == 1 && y <= 14) {
		if (x - 4 <= 0) {
			nbBits = (5 + x < BOARD_SIZE - y) ? 5 + x : BOARD_SIZE - y;
			selection = getSelection(bitboard, nbBits, 0);
		} else if (x + 4 >= BOARD_SIZE - y) {
			nbBits = (BOARD_SIZE - y) - (x - 4);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	} else if (boardSide == 2 && y > 4) {
		if (x - 4 < BOARD_SIZE - y) {
			nbBits = x - (BOARD_SIZE - y);
			if (x + 4 > BOARD_SIZE - 1)
				nbBits += BOARD_SIZE - x;
			else
				nbBits += 5;
			selection = getSelection(bitboard, nbBits, BOARD_SIZE - y);
		} else if (x + 4 > BOARD_SIZE - 1) {
			nbBits = 5 + ((BOARD_SIZE - 1) - x);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	}
		
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111)
				return true;
		}
	}
	return (false);
}
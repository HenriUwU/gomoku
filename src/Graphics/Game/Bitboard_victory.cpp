/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/02 13:44:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool    Bitboard::isBreakable() {
    for (int )
}

bool    Bitboard::fiveInARow(int x, int y, int player) {
    if (fiveInARowHorizontal(x, y, player))
        return (true);
    
}

bool    Bitboard::fiveInARowHorizontal(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
    uint32_t    selection = 0;

	if (x - 4 < 0) {
		nbBits = 9 - x;
		selection = getSelection(bitboard, nbBits, 0);
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 4);
		selection = getSelection(bitboard, nbBits, x - 4);
	} else {
		nbBits = 9;
		selection = getSelection(bitboard, nbBits, x - 4);
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 && !isBreakable(selection))
				return true;
		}
	}
    return false;
}
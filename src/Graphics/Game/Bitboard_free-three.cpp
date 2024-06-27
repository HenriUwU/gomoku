/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_free-three.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:41:03 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/27 13:23:00 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool	Bitboard::isDoubleThree(int x, int y, int player) {
	int	nbFreeThree = 0;
	(void)x;
	(void)y;
	(void)player;
	
	
	if (nbFreeThree >= 2)
		return (true);
	return (false);
}

/* bool	Bitboard::verifyDoubleThreeHorizontal() {
	uint32_t	linesBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	linesMask = uint32_t(1) << x;
	
	linesBitboard |= linesMask;

	if (x <= 15) { 
		uint32_t rightSelection = getSelection(linesBitboard, 4, x);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (x >= 3) {
		uint32_t leftSelection = getSelection(linesBitboard, 4, x - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
} */
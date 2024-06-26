/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_rules.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:47:40 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/26 12:06:47 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int	Bitboard::isCapturingMove(int x, int y, int player) {
	int			nbCaptures = 0;

	verifyHorizontalCapture(nbCaptures, x, y, player);
	verifyVerticalCapture(nbCaptures, x, y, player);
	verifyDiagonalCapture(nbCaptures, x, y, player);
	return nbCaptures;
}

void	Bitboard::verifyHorizontalCapture(int &nbCaptures, int x, int y, int player) {
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
}

void	Bitboard::verifyVerticalCapture(int &nbCaptures, int x, int y, int player) {
	uint32_t	columnsBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	columnsMask = uint32_t(1) << y;
	
	columnsBitboard |= columnsMask;
	if (y <= 15) {
		uint32_t rightSelection = getSelection(columnsBitboard, 4, y);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (y >= 3) {
		uint32_t leftSelection = getSelection(columnsBitboard, 4, y - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
}

void	Bitboard::verifyDiagonalCapture(int &nbCaptures, int x, int y, int player) {
	int boardSide;

	if (x + y < BOARD_SIZE)
		boardSide = 1;
	else
		boardSide = 2;

	y = rotateY45(x, y);

	uint32_t	diagonalsBitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
	uint32_t	diagonalsMask = uint32_t(1) << x;

	diagonalsBitboard |= diagonalsMask;

	if (boardSide == 1 && y >= 3) {
		if (x + 3 <= y + 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x - 3 >= 0) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
	else if (boardSide == 2 && y <= 15) {
		if (x - 3 >= y + 1) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x + 3 <= BOARD_SIZE - 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
}
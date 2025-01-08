/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardPatterns.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/07 22:34:54 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard/Bitboard.hpp"

int evaluateLine(PatternInfo pattern, uint32_t playerBoardLine, uint32_t opponentBoardLine, int direction, int y) {
	int diagonalCut = 0;
	int score = 0;
	int x = 0;

	if (playerBoardLine == 0 && opponentBoardLine == 0)
		return (0);

	if (direction == DIAGONAL) {
		diagonalCut = y + 1;
	} else if (direction == ANTIDIAGONAL) {
		diagonalCut = 19 - y;
	}
 
	while (x <= (19 - pattern.patternSize)) {
		if ((direction == DIAGONAL || direction == ANTIDIAGONAL) && (x + pattern.patternSize >= diagonalCut && x < diagonalCut)) {
			x++;
			continue;
		}
		uint32_t playerSelection = (playerBoardLine >> x) & ((1 << pattern.patternSize) - 1);
		uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << pattern.patternSize) - 1);

		if (playerSelection == pattern.pattern && opponentSelection == pattern.opponentPattern) {
			score += pattern.multiplier;
			x += pattern.patternSize - 1;
		} else
			x++;
	}
	return (score);
}

int Bitboard::evaluatePatterns(PatternInfo patterns[], int nbPattern) {
	int score = 0;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int i = 0; i < nbPattern; i++) {

			uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
			uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
			score += evaluateLine(patterns[i], playerBoardLine, opponentBoardLine, HORIZONTAL, y);

			uint32_t playerBoardColumn = (patterns[i].playerType == 1) ? _firstPlayerBoardColumns[y] : _secondPlayerBoardColumns[y];
			uint32_t opponentBoardColumn = (patterns[i].playerType == 1) ? _secondPlayerBoardColumns[y] : _firstPlayerBoardColumns[y];
			score += evaluateLine(patterns[i], playerBoardColumn, opponentBoardColumn, VERTICAL, y);

			uint32_t playerBoardDiagonal = (patterns[i].playerType == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
			uint32_t opponentBoardDiagonal = (patterns[i].playerType == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];
			score += evaluateLine(patterns[i], playerBoardDiagonal, opponentBoardDiagonal, DIAGONAL, y);

			uint32_t playerBoardAntiDiagonal = (patterns[i].playerType == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
			uint32_t opponentBoardAntiDiagonal = (patterns[i].playerType == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];
			score += evaluateLine(patterns[i], playerBoardAntiDiagonal, opponentBoardAntiDiagonal, ANTIDIAGONAL, y);
			
		}
	}
	return score;
}

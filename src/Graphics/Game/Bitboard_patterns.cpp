/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_patterns.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/08 17:28:20 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int     Bitboard::checkPattern(PatternInfo patterns[]) {
	int	score = 0;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			for (int i = 0; i < 22; i++) {
				if (x + patterns[i].patternSize <= BOARD_SIZE) {
					uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
					uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
					uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);
					uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);
					
					if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
						score += (1 * patterns[i].multiplier);
				}

				if (x + patterns[i].patternSize <= BOARD_SIZE) {
					uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardColumns[y] : _secondPlayerBoardColumns[y];
					uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardColumns[y] : _firstPlayerBoardColumns[y];
					uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);
					uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);

					if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
						score += (1 * patterns[i].multiplier);
				}
				
				int boardSide = (x < y + 1) ? 1 : 2;
				if ((boardSide == 1 && x + patterns[i].patternSize <= y + 1) || (boardSide == 2 && x + patterns[i].patternSize <= BOARD_SIZE)) {
					uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
					uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];
					uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);
					uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);

					if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
						score += (1 * patterns[i].multiplier);
				}
				
				boardSide = (x < BOARD_SIZE - y) ? 1 : 2;
				if ((boardSide == 1 && x + patterns[i].patternSize <= BOARD_SIZE - y) || (boardSide == 2 && x + patterns[i].patternSize <= BOARD_SIZE - 1)) {
					uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
					uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];

					uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);
					uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patterns[i].patternSize) - 1);

					if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
						score += (1 * patterns[i].multiplier);
				}
			}
		}
	}
	return (score);
}

void Bitboard::checkPatternHorizontal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	if (x + patternSize <= BOARD_SIZE) {
		uint32_t playerBoardLine = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
		uint32_t opponentBoardLine = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];

		uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patternSize) - 1);
		uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patternSize) - 1);

		if (playerSelection == pattern && opponentSelection == opponentPattern)
			nbPattern++;
	}
}

void Bitboard::checkPatternVertical(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	if (x + patternSize <= BOARD_SIZE) {
		uint32_t playerBoardLine = (player == 1) ? _firstPlayerBoardColumns[y] : _secondPlayerBoardColumns[y];
		uint32_t opponentBoardLine = (player == 1) ? _secondPlayerBoardColumns[y] : _firstPlayerBoardColumns[y];

		uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patternSize) - 1);
		uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patternSize) - 1);

		if (playerSelection == pattern && opponentSelection == opponentPattern)
			nbPattern++;
	}
}

void Bitboard::checkPatternDiagonal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	int boardSide = (x < y + 1) ? 1 : 2;
	
	if ((boardSide == 1 && x + patternSize <= y + 1) || (boardSide == 2 && x + patternSize <= BOARD_SIZE)) {
		uint32_t playerBoardLine = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
		uint32_t opponentBoardLine = (player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];

		uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patternSize) - 1);
		uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patternSize) - 1);

		if (playerSelection == pattern && opponentSelection == opponentPattern)
			nbPattern++;
	}
}

void Bitboard::checkPatternAntiDiagonal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	int boardSide = (x < BOARD_SIZE - y) ? 1 : 2;
	
	if ((boardSide == 1 && x + patternSize <= BOARD_SIZE - y) || (boardSide == 2 && x + patternSize <= BOARD_SIZE - 1)) {
		uint32_t playerBoardLine = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
		uint32_t opponentBoardLine = (player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];

		uint32_t playerSelection = (playerBoardLine >> x) & ((1 << patternSize) - 1);
		uint32_t opponentSelection = (opponentBoardLine >> x) & ((1 << patternSize) - 1);

		if (playerSelection == pattern && opponentSelection == opponentPattern)
			nbPattern++;
	}
}
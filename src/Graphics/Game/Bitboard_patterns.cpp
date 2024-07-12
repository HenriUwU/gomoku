/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_patterns.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/12 11:26:16 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int     Bitboard::checkPattern(PatternInfo patterns[]) {
	int	score = 0;
	
	std::unordered_set<std::pair<int, int>, pair_hash>	plate = getAllStones();

	for (auto& stone : plate) {
		for (int i = 0; i < 22; i++) {
			if (stone.first + patterns[i].patternSize <= BOARD_SIZE) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardLines[stone.second] : _secondPlayerBoardLines[stone.second];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardLines[stone.second] : _firstPlayerBoardLines[stone.second];
				uint32_t playerSelection = (playerBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);
				
				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
					score += (1 * patterns[i].multiplier);
			}

			if (stone.first + patterns[i].patternSize <= BOARD_SIZE) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardColumns[stone.second] : _secondPlayerBoardColumns[stone.second];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardColumns[stone.second] : _firstPlayerBoardColumns[stone.second];
				uint32_t playerSelection = (playerBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
					score += (1 * patterns[i].multiplier);
			}
			
			int boardSide = (stone.first < stone.second + 1) ? 1 : 2;
			if ((boardSide == 1 && stone.first + patterns[i].patternSize <= stone.second + 1) || (boardSide == 2 && stone.first + patterns[i].patternSize <= BOARD_SIZE)) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardDiagonals[stone.second] : _secondPlayerBoardDiagonals[stone.second];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardDiagonals[stone.second] : _firstPlayerBoardDiagonals[stone.second];
				uint32_t playerSelection = (playerBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
					score += (1 * patterns[i].multiplier);
			}
			
			boardSide = (stone.first < BOARD_SIZE - stone.second) ? 1 : 2;
			if ((boardSide == 1 && stone.first + patterns[i].patternSize <= BOARD_SIZE - stone.second) || (boardSide == 2 && stone.first + patterns[i].patternSize <= BOARD_SIZE - 1)) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardAntiDiagonals[stone.second] : _secondPlayerBoardAntiDiagonals[stone.second];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardAntiDiagonals[stone.second] : _firstPlayerBoardAntiDiagonals[stone.second];

				uint32_t playerSelection = (playerBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> stone.first) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern)
					score += (1 * patterns[i].multiplier);
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
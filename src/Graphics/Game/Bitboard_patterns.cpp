/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_patterns.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/26 15:42:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

int     Bitboard::checkPattern(PatternInfo patterns[], int nbPattern) {
	int	score = 0;
	int x;
	int y;

	std::unordered_set<std::pair<int, int>, pair_hash>	plate = getAllStones();

	for (auto& stone : plate) {
		for (int i = 0; i < nbPattern; i++) {
			x = stone.first;
			y = stone.second;
			if (x + patterns[i].patternSize <= BOARD_SIZE) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
				uint32_t playerSelection = (playerBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);
				
				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern) {
					score += (1 * patterns[i].multiplier);
				}
			}

			x = stone.second;
			y = stone.first;
			if (x + patterns[i].patternSize <= BOARD_SIZE) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardColumns[y] : _secondPlayerBoardColumns[y];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardColumns[y] : _firstPlayerBoardColumns[y];
				uint32_t playerSelection = (playerBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern) {
					score += (1 * patterns[i].multiplier);
				}
			}
			
			x = stone.first;
			int boardSide = (x < stone.second + 1) ? 1 : 2;
			y = rotateY45(x, stone.second);
			if ((boardSide == 1 && x + patterns[i].patternSize <= y + 1) || (boardSide == 2 && x + patterns[i].patternSize <= BOARD_SIZE)) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y];
				uint32_t playerSelection = (playerBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern) {
					score += (1 * patterns[i].multiplier);
				}
			}
			
			boardSide = (x < BOARD_SIZE - stone.second) ? 1 : 2;
			y = rotateY315(x, stone.second);
			if ((boardSide == 1 && x + patterns[i].patternSize <= BOARD_SIZE - y) || (boardSide == 2 && x + patterns[i].patternSize <= BOARD_SIZE - 1)) {
				uint32_t playerBoardLine = (patterns[i].playerType == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
				uint32_t opponentBoardLine = (patterns[i].playerType == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y];
				uint32_t playerSelection = (playerBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);
				uint32_t opponentSelection = (opponentBoardLine >> (x - 1)) & ((1 << patterns[i].patternSize) - 1);

				if (playerSelection == patterns[i].pattern && opponentSelection == patterns[i].opponentPattern) {
					score += (1 * patterns[i].multiplier);
				}
			}
		}
	}
	return (score);
}

int Bitboard::findSinglePattern(PatternInfo pattern, int x, int y) {
	int nbTimesPatternFound = 0;
	int player = (pattern.playerType == 1) ? 1 : 2;
	
	if (horizontalPattern(pattern, x, y, player))
		nbTimesPatternFound++;
	if (verticalPattern(pattern, x, y, player))
		nbTimesPatternFound++;
	if (diagonalPattern(pattern, x, y, player))
		nbTimesPatternFound++;
	if (antiDiagonalPattern(pattern, x, y, player))
		nbTimesPatternFound++;
	
	return (nbTimesPatternFound);
}

bool Bitboard::horizontalPattern(PatternInfo pattern, int x, int y, int player) {
	uint32_t pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];	
	uint32_t oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
	uint32_t pSelection = getSelection(pBitboard, pattern.patternSize, x);
	uint32_t oSelection = getSelection(oBitboard, pattern.patternSize, x);
	
	return (pSelection == pattern.pattern && oSelection == pattern.opponentPattern);
}

bool Bitboard::verticalPattern(PatternInfo pattern, int x, int y, int player) {
	uint32_t pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];	
	uint32_t oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
	uint32_t pSelection = getSelection(pBitboard, pattern.patternSize, y);
	uint32_t oSelection = getSelection(oBitboard, pattern.patternSize, y);
	
	return (pSelection == pattern.pattern && oSelection == pattern.opponentPattern);
}

bool Bitboard::diagonalPattern(PatternInfo pattern, int x, int y, int player) {
	// int boardSide = (x < y + 1) ? 1 : 2;
	int yRotated = rotateY45(x, y);
	uint32_t pBitboard = (player == 1) ? _firstPlayerBoardDiagonals[yRotated] : _secondPlayerBoardDiagonals[yRotated];	
	uint32_t oBitboard = (player == 1) ? _secondPlayerBoardDiagonals[yRotated] : _firstPlayerBoardDiagonals[yRotated];
	uint32_t pSelection = getSelection(pBitboard, pattern.patternSize, x);
	uint32_t oSelection = getSelection(oBitboard, pattern.patternSize, x);
	
	return (pSelection == pattern.pattern && oSelection == pattern.opponentPattern);
}

bool Bitboard::antiDiagonalPattern(PatternInfo pattern, int x, int y, int player) {
	// int boardSide = (x < BOARD_SIZE - y) ? 1 : 2;
	int yRotated = rotateY315(x, y);
	uint32_t pBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[yRotated] : _secondPlayerBoardAntiDiagonals[yRotated];	
	uint32_t oBitboard = (player == 1) ? _secondPlayerBoardAntiDiagonals[yRotated] : _firstPlayerBoardAntiDiagonals[yRotated];
	uint32_t pSelection = getSelection(pBitboard, pattern.patternSize, x);
	uint32_t oSelection = getSelection(oBitboard, pattern.patternSize, x);
	
	return (pSelection == pattern.pattern && oSelection == pattern.opponentPattern);
}
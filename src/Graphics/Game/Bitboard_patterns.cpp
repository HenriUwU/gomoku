/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_patterns.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/16 18:34:45 by hsebille         ###   ########.fr       */
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
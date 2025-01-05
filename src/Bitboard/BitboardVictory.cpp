/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardVictory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:41 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:45 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int	Bitboard::fiveInARow() {
	PatternInfo playerOneFiveInARow[] = {0b11111, 0b00000, 5, 1, 1};
	PatternInfo playerTwoFiveInARow[] = {0b11111, 0b00000, 5, 2, 1};
	int win = 0;
	
	if (evaluatePatterns(playerOneFiveInARow, 1) && !isAlignmentBreakable(playerOneFiveInARow, 1, 2))
		win = 1;
	
	if (evaluatePatterns(playerTwoFiveInARow, 1) && !isAlignmentBreakable(playerTwoFiveInARow, 2, 1))
		win = 2;

	return (win);
}

bool Bitboard::isAlignmentBreakable(PatternInfo alignment[], int player, int opponent) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			std::vector<std::pair<int, int>> removedStones = {};
			if (isLegalMoveForAI(x, y, opponent)) {
				removedStones = placeStoneAI(x, y, opponent, true);
			} else {
				continue;
			}
			
			if (removedStones.size() > 0 && !evaluatePatterns(alignment, 1)) {
				for (auto& stone : removedStones) {
					placeStoneAI(stone.first, stone.second, player, false);
				}
				removeStone(x, y, opponent);
				return (true);
			}
			for (auto& stone : removedStones) {
				placeStoneAI(stone.first, stone.second, player, false);
			}
			removeStone(x, y, opponent);
		}
	}
	return (false);
}

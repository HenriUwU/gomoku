/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardVictory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:41 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 22:00:27 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool Bitboard::isDoubleThree(int x, int y, int player) {
	PatternInfo pattern[] = {
		{0b01110, 0b00000, 5, player, 2},
		{0b010110, 0b000000, 6, player, 2},
		{0b011010, 0b000000, 6, player, 2},
	};
	int currentDoubleThree = 0;
	int createdDoubleThree = 0;
	Bitboard tmp = *this;

	currentDoubleThree = tmp.evaluatePatterns(pattern, 3) / 2;
	std::vector<std::pair<int, int>> capturedStones = tmp.placeStoneAI(x, y, player, true);
	createdDoubleThree = tmp.evaluatePatterns(pattern, 3) / 2;

	if (createdDoubleThree - currentDoubleThree >= 2 && capturedStones.size() == 0)
		return true;
	return false;
}

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
	Bitboard tmp = *this;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			std::vector<std::pair<int, int>> removedStones = {};
			if (tmp.isLegalMoveForAI(x, y, opponent)) {
				removedStones = tmp.placeStoneAI(x, y, opponent, true);
			} else {
				continue;
			}
			
			if (removedStones.size() > 0 && !tmp.evaluatePatterns(alignment, 1)) {
				for (auto& stone : removedStones) {
					tmp.placeStoneAI(stone.first, stone.second, player, false);
				}
				tmp.removeStone(x, y, opponent);
				return (true);
			}
			for (auto& stone : removedStones) {
				tmp.placeStoneAI(stone.first, stone.second, player, false);
			}
			tmp.removeStone(x, y, opponent);
		}
	}
	return (false);
}

bool	Bitboard::isLegalMove(int x, int y, int player) {
	if (getBit(x, y))
		return (false);

	if (isDoubleThree(x, y, player) && !isCapturingMove(x, y, player)) {
		if (!aiPlaying)
			forbiddenMoves = DOUBLE_THREE;
		return (false);
	}
	return (true);
}

bool    Bitboard::isLegalMoveForAI(int x, int y, int player) {
	if (getBit(x, y))
		return (false);

	if (isDoubleThree(x, y, player) && !isCapturingMove(x, y, player)) {
		return (false);
	}
	return (true);
}

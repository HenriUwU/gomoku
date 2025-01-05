/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardVictory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:41 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 18:30:16 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool	Bitboard::fiveInARow() {
	PatternInfo playerOneFiveInARow[] = {0b11111, 0b00000, 5, 1, 1};
	PatternInfo playerTwoFiveInARow[] = {0b11111, 0b00000, 5, 2, 1};
	
	if (evaluatePatterns(playerOneFiveInARow, 1)) {
		
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int x = 0; x < BOARD_SIZE; x++) {
				std::vector<std::pair<int, int>>	removedStones;
				if (isLegalMoveForAI(x, y, 1)) {
					removedStones = placeStoneAI(x, y, 1, false);
				} else {
					continue;
				}
				
				if (removedStones.size() > 0 && !evaluatePatterns(playerTwoFiveInARow, 1)) {
					for (auto& stone : removedStones) {
						placeStoneAI(stone.first, stone.second, playerOneFiveInARow[0].playerType, false);
					}
					continue;
				} else {
					return (true);
				}
			}
		}

	}
	return (true);
}

// bool	Bitboard::madeCapture() {

// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/11 19:40:54 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

int	AI::heuristic(Bitboard &bitboard) {
	int	evaluation = 0;
	
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (bitboard.getBit(x, y) == 1) {
				if (bitboard.fiveInARow(x, y, 1))
					return (-1000000000);
				evaluation -= 100;
			}
			if (bitboard.getBit(x, y) == 2) {
				if (bitboard.fiveInARow(x, y, 2))
					return (1000000000);
				evaluation += 100;
			}
		}
	}

	if (playersCaptures[0] == 4) {
		PatternInfo pattern[] = {0b0110, 0b0000, 4, 1, 100};

		if (bitboard.checkPattern(pattern, 1) > 0)
			return (-1000000000);
	}
	if (playersCaptures[1] == 4) {
		PatternInfo pattern[] = {0b0110, 0b0000, 4, 2, 100};

		if (bitboard.checkPattern(pattern, 1) > 0)
			return (1000000000);
	}

	return (evaluation);
}

int	AI::checkPatterns(Bitboard &bitboard, int player, int opponent) {
	int score = 0;
	
	PatternInfo patterns[NB_HEURISTIC_PATTERNS] = {
		// Two in a row
		{0b0110, 0b0000, 4, player, 100},
		{0b0110, 0b0000, 4, opponent, -100},
		
		// Three in a row
		{0b01110, 0b10000, 5, player, 1000},
		{0b01110, 0b00001, 5, player, 1000},
		{0b01110, 0b00000, 5, player, 10000},
		{0b0101010, 0b0000000, 7, player, 1000},
		{0b011010, 0b000000, 6, player, 10000},
		{0b01110, 0b10000, 5, opponent, -1000},
		{0b01110, 0b00001, 5, opponent, -1000},
		{0b01110, 0b00000, 5, opponent, -10000},
		{0b0101010, 0b0000000, 7, opponent, -1000},
		{0b011010, 0b000000, 6, opponent, -10000},
		
		// Four in a row
		{0b011110, 0b100000, 6, player, 10000},
		{0b011110, 0b000001, 6, player, 10000},
		{0b011110, 0b000000, 6, player, 100000},
		{0b011110, 0b000001, 6, opponent, -10000},
		{0b011110, 0b100000, 6, opponent, -10000},
		{0b011110, 0b000000, 6, opponent, -100000},
		
		// Possible captures
		{0b0110, 0b1000, 4, player, (1000 * (-playersCaptures[0]))},
		{0b0110, 0b0001, 4, player, (1000 * (-playersCaptures[0]))},
		{0b0110, 0b1000, 4, opponent, (1000 * playersCaptures[1])},
		{0b0110, 0b0001, 4, opponent, (1000 * playersCaptures[1])},
	};
	
	score += bitboard.checkPattern(patterns, NB_HEURISTIC_PATTERNS);
	
	return (score);
}

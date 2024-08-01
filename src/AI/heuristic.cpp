/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:20:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/31 14:17:18 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

int	AI::heuristic(Bitboard &bitboard, int depth) {
	int	evaluation = 0;
	
	PatternInfo fiveInARowAI[1] = {0b11111, 0b00000, 5, 2, 10};
	PatternInfo fiveInARowOpponent[1] = {0b11111, 0b00000, 5, 1, 10};
	
	if (bitboard.checkPattern(fiveInARowOpponent, 1))
		return (-100000 - depth);

	if (bitboard.checkPattern(fiveInARowAI, 1))
		return (100000 + depth);
	
	evaluation += checkCenterControl(bitboard, 2, 1);
	evaluation += checkPatterns(bitboard, 2, 1);

	return (evaluation);
}

int	AI::fastHeuristic(Bitboard &bitboard, int depth) {
	int evaluation = 0;
	
	PatternInfo fiveInARowAI[1] = {0b11111, 0b00000, 5, 2, 10};
	PatternInfo fiveInARowOpponent[1] = {0b11111, 0b00000, 5, 1, 10};

	PatternInfo patterns[] {
		{0b01110, 0b00000, 5, 2, 1500},
		{0b011110, 0b000000, 6, 2, 2000},
		{0b1001, 0b0110, 4, 2, 800},
	};

	if (bitboard.checkPattern(fiveInARowOpponent, 1))
		return (-100000 - depth);

	if (bitboard.checkPattern(fiveInARowAI, 1))
		return (100000 + depth);

	evaluation += bitboard.checkPattern(patterns, 3);

	return (evaluation);
}

int AI::checkCenterControl(Bitboard &bitboard, int player, int opponent) {
	int score = 0;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			int stone = bitboard.getBit(x, y);
			if (stone == player) {
				score += _centerScores[x][y];
			} else if (stone == opponent) {
				score -= _centerScores[x][y];
			}
		}
	}
	return score;
}

int	AI::checkPatterns(Bitboard &bitboard, int player, int opponent) {
	int score = 0;
	
	PatternInfo offensivePatterns[20] = {
		// Two in a row
		{0b0110, 0b0000, 4, player, 200},
		{0b0110, 0b0000, 4, opponent, -200},
		
		// Three in a row
		{0b01110, 0b10000, 5, player, 750},
		{0b01110, 0b00001, 5, player, 750},
		{0b01110, 0b00000, 5, player, 1500},
		{0b01110, 0b10000, 5, opponent, -750},
		{0b01110, 0b00001, 5, opponent, -750},
		{0b01110, 0b00000, 5, opponent, -1500},
		
		// Four in a row
		{0b011110, 0b100000, 6, player, 900},
		{0b011110, 0b000001, 6, player, 900},
		{0b011110, 0b000000, 6, player, 2000},
		{0b011110, 0b000001, 6, opponent, -900},
		{0b011110, 0b100000, 6, opponent, -900},
		{0b011110, 0b000000, 6, opponent, -2000},
		
		// Player Capture
		{0b1000, 0b0110, 4, player, 500},
		{0b0001, 0b0110, 4, player, 500},
		{0b1001, 0b0110, 4, player, 800},
		
		// opponent capture
		{0b1000, 0b0110, 4, opponent, -500},
		{0b0001, 0b0110, 4, opponent, -500},
		{0b1001, 0b0110, 4, opponent, -800},
	};
	
	PatternInfo defensivePatterns[12] = {
		// Three in a row defense
		{0b10000, 0b01110, 5, player, 1500},
		{0b00001, 0b01110, 5, player, 1500},
		{0b10001, 0b01110, 5, player, 1600},
		{0b10000, 0b01110, 5, opponent, -1500},
		{0b00001, 0b01110, 5, opponent, -1500},
		{0b10001, 0b01110, 5, opponent, -1600},

		
		// four in a row defense
		{0b000001, 0b011110, 6, player, 4000},
		{0b100000, 0b011110, 6, player, 4000},
		{0b100001, 0b011110, 6, player, 8000},
		{0b000001, 0b011110, 6, opponent, -4000},
		{0b100000, 0b011110, 6, opponent, -4000},
		{0b100001, 0b011110, 6, opponent, -8000},
	};
	
	score += bitboard.checkPattern(offensivePatterns, 20);
	score += bitboard.checkPattern(defensivePatterns, 12);
	
	return (score);
}

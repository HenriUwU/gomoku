/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:20:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/09/12 14:17:48 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

int	AI::heuristic(Bitboard &bitboard, int depth) {
	int	evaluation = 0;
	
	PatternInfo fiveInARowAI[1] = {0b11111, 0b00000, 5, 2, 10};
	PatternInfo fiveInARowOpponent[1] = {0b11111, 0b00000, 5, 1, 10};
	
	if (bitboard.checkPattern(fiveInARowOpponent, 1))
		return (-1000000 + depth);

	if (bitboard.checkPattern(fiveInARowAI, 1))
		return (1000000 + depth);
	
	//evaluation += checkCenterControl(bitboard, 2, 1);
	evaluation += checkPatterns(bitboard, 2, 1);

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
	
	PatternInfo patterns[22] = {
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
		
		// Captures
		{0b1000, 0b0110, 4, player, 1000},
		{0b0001, 0b0110, 4, player, 1000},
		{0b1000, 0b0110, 4, opponent, -1000},
		{0b0001, 0b0110, 4, opponent, -1000},
	};
	
	score += bitboard.checkPattern(patterns, 22);
	
	return (score);
}

int AI::quickHeuristic(Bitboard &bitboard) {
	int evaluation = 0;
	
	PatternInfo quickPatterns[6] = {
		{0b0110, 0b0000, 4, 2, 100},
		{0b01110, 0b00000, 5, 2, 10000},
		{0b011110, 0b000000, 6, 2, 100000},
		{0b0110, 0b0000, 4, 1, -100},
		{0b01110, 0b00000, 5, 1, -10000},
		{0b011110, 0b000000, 6, 1, -100000},
	};

	evaluation += bitboard.checkPattern(quickPatterns, 6);
	evaluation += checkCenterControl(bitboard, 2, 1);

	return evaluation;
}

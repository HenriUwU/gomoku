/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:20:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/09 18:01:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

int	AI::heuristic(Bitboard &bitboard, bool maximizingPlayer) {
	int	evaluation = 0;
	
	int player = (maximizingPlayer) ? 2 : 1;
	int opponent = (maximizingPlayer) ? 1 : 2;

	evaluation += checkCenterControl(bitboard, player, opponent);
	evaluation += checkPatterns(bitboard, player, opponent);

	return (evaluation);
}

int AI::checkCenterControl(Bitboard &bitboard, int player, int opponent) {
	int score = 0;

	#pragma omp simd
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
		{0b0110, 0b0000, 4, player, 200},
		{0b0110, 0b0000, 4, opponent, -400},
		
		// Three in a row
		{0b01110, 0b10000, 5, player, 1000},
		{0b01110, 0b00001, 5, player, 1000},
		{0b01110, 0b00000, 5, player, 10000},
		{0b01110, 0b10000, 5, opponent, -2000},
		{0b01110, 0b00001, 5, opponent, -2000},
		{0b01110, 0b00000, 5, opponent, -20000},
		
		// Four in a row
		{0b011110, 0b100000, 6, player, 20000},
		{0b011110, 0b000001, 6, player, 20000},
		{0b011110, 0b000000, 6, player, 80000},
		{0b000001, 0b011110, 6, opponent, -20000},
		{0b100000, 0b011110, 6, opponent, -20000},
		{0b000000, 0b011110, 6, opponent, -80000},
		
		// Five in a row
		{0b11111, 0b00000, 5, player, 100000},
		{0b11111, 0b00000, 5, opponent, -100000},
		
		// Player Capture
		{0b1000, 0b0110, 4, player, 1000},
		{0b0001, 0b0110, 4, player, 1000},
		{0b1001, 0b0110, 4, player, 2000},
		
		// Opponent Capture
		{0b1000, 0b0110, 4, opponent, -2000},
		{0b0001, 0b0110, 4, opponent, -2000},
		{0b1001, 0b0110, 4, opponent, -4000},
	};
	
	score += bitboard.checkPattern(patterns);
	
	return (score);
}

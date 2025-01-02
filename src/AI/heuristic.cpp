/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/26 15:42:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

int	AI::heuristic(Bitboard &bitboard) {
	int	evaluation = 0;
	
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (bitboard.getBit(x, y) == 1) {
				if (bitboard.fiveInARow(x, y, 1))
					return (INT_MIN);
			}
			if (bitboard.getBit(x, y) == 2) {
				if (bitboard.fiveInARow(x, y, 2))
					return (INT_MAX);
			}
		}
	}

	if (_firstPlayerNbCaptures >= 5)
		return (INT_MIN);
	else if (_secondPlayerNbCaptures >= 5)
		return (INT_MAX);
		
	evaluation += checkPatterns(bitboard, 2, 1);

	return (evaluation);
}

int	AI::checkPatterns(Bitboard &bitboard, int player, int opponent) {
	int score = 0;
	
	PatternInfo mainPatterns[NB_HEURISTIC_PATTERNS] = {
		{0b0110, 0b0000, 4, player, 100},
		{0b0110, 0b0000, 4, opponent, -100},
		
		{0b01110, 0b10000, 5, player, 1000},
		{0b01110, 0b00001, 5, player, 1000},
		{0b01110, 0b00000, 5, player, 10000},
		{0b01110, 0b10000, 5, opponent, -1000},
		{0b01110, 0b00001, 5, opponent, -1000},
		{0b01110, 0b00000, 5, opponent, -10000},
		
		{0b011110, 0b100000, 6, player, 100000},
		{0b011110, 0b000001, 6, player, 100000},
		{0b011110, 0b000000, 6, player, 1000000},
		{0b011110, 0b000001, 6, opponent, -100000},
		{0b011110, 0b100000, 6, opponent, -100000},
		{0b011110, 0b000000, 6, opponent, -1000000},

		{0b11111, 0b00000, 5, player, 100000000},
		{0b11111, 0b00000, 5, opponent, 100000000},
		
		{0b0110, 0b1000, 4, player, (10000 * (-_firstPlayerNbCaptures))},
		{0b0110, 0b0001, 4, player, (10000 * (-_firstPlayerNbCaptures))},
		{0b0110, 0b1000, 4, opponent, (10000 * _secondPlayerNbCaptures)},
		{0b0110, 0b0001, 4, opponent, (10000 * _secondPlayerNbCaptures)},
	};

	PatternInfo defensivePatterns[NB_DEFENSIVE_PATTERNS] = {
		{0b10000, 0b01110, 5, player, 1000},
		{0b00001, 0b01110, 5, player, 1000},
		{0b10001, 0b01110, 5, player, 10000},

		{0b100000, 0b011110, 6, player, 100000},
		{0b000001, 0b011110, 6, player, 100000},
		{0b100001, 0b011110, 6, player, 1000000},
	};
	
	score += bitboard.checkPattern(mainPatterns, NB_HEURISTIC_PATTERNS);
	score += bitboard.checkPattern(defensivePatterns, NB_DEFENSIVE_PATTERNS);
	
	return (score);
}

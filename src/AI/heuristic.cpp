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

int AI::heuristic(Bitboard& bitboard) {
	int score = 0;

	//-- Hard checks for victories or loses --//
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

	//-- Check for alignents --//
	score += evaluateAlignments(bitboard);

	return score;
}

int AI::evaluateAlignments(Bitboard& bitboard) {
	int score = 0;

	PatternInfo mainPatterns[NB_HEURISTIC_PATTERNS] = {
		{0b0110, 0b0000, 4, 2, 50},
		{0b0110, 0b0000, 4, 1, -50},
		
		{0b01110, 0b10000, 5, 2, 250},
		{0b01110, 0b00001, 5, 2, 250},
		{0b01110, 0b00000, 5, 2, 500},
		{0b01110, 0b10000, 5, 1, -250},
		{0b01110, 0b00001, 5, 1, -250},
		{0b01110, 0b00000, 5, 1, -500},
		
		{0b011110, 0b100000, 6, 2, 5000},
		{0b011110, 0b000001, 6, 2, 5000},
		{0b011110, 0b000000, 6, 2, 10000},
		{0b011110, 0b000001, 6, 1, -5000},
		{0b011110, 0b100000, 6, 1, -5000},
		{0b011110, 0b000000, 6, 1, -10000},

		{0b11111, 0b00000, 5, 2, 1000000},
		{0b11111, 0b00000, 5, 1, -1000000},
		
		// {0b0110, 0b1000, 4, 1, 10000},
		// {0b0110, 0b0001, 4, 1, 10000},
		// {0b0110, 0b1000, 4, 2, -10000},
		// {0b0110, 0b0001, 4, 2, -10000},
	};

	PatternInfo defenses[] = {
		{0b10000, 0b01110, 5, 1, 500},
		{0b00001, 0b01110, 5, 1, 500},

		{0b100000, 0b011110, 6, 1, 5000},
		{0b000001, 0b011110, 6, 1, 5000},
	};

	score += bitboard.evaluatePatterns(defenses, NB_DEFENSIVE_PATTERNS);
	score += bitboard.evaluatePatterns(mainPatterns, 4);

	return score;
}
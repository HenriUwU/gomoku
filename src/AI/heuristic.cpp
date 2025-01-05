/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2025/01/05 22:13:58 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

int AI::heuristic(Bitboard& bitboard) {
	int score = 0;

	//-- Hard checks for victories or loses --//
	int win = bitboard.fiveInARow();

	if (win == 1)
		return (INT_MIN);
	else if (win == 2)
		return (INT_MAX);
	
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
		{0b01110, 0b10000, 5, 2, 1000},
		{0b01110, 0b00001, 5, 2, 1000},
		{0b01110, 0b00000, 5, 2, 10000},
		{0b01110, 0b10000, 5, 1, -1000},
		{0b01110, 0b00001, 5, 1, -1000},
		{0b01110, 0b00000, 5, 1, -10000},
		
		{0b011110, 0b100000, 6, 2, 100000},
		{0b011110, 0b000001, 6, 2, 100000},
		{0b011110, 0b000000, 6, 2, 1000000},
		{0b011110, 0b000001, 6, 1, -100000},
		{0b011110, 0b100000, 6, 1, -100000},
		{0b011110, 0b000000, 6, 1, -1000000},

		{0b11111, 0b00000, 5, 2, 100000000},
		{0b11111, 0b00000, 5, 1, 100000000},
		
		{0b0110, 0b1000, 4, 2, (10000 * ((-_firstPlayerNbCaptures) - 1))},
		{0b0110, 0b0001, 4, 2, (10000 * ((-_firstPlayerNbCaptures) - 1))},
		{0b0110, 0b1000, 4, 1, (10000 * (_secondPlayerNbCaptures) + 1)},
		{0b0110, 0b0001, 4, 1, (10000 * (_secondPlayerNbCaptures) + 1)},
	};

	score += bitboard.evaluatePatterns(mainPatterns, NB_HEURISTIC_PATTERNS);

	return score;
}
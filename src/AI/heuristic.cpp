/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/21 11:51:02 by hsebille         ###   ########.fr       */
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
			}
			if (bitboard.getBit(x, y) == 2) {
				if (bitboard.fiveInARow(x, y, 2))
					return (1000000000);
			}
		}
	}

	if (_firstPlayerNbCaptures == 5)
		return (-1000000000);
	else if (_secondPlayerNbCaptures == 5)
		return (1000000000);
		
	evaluation += checkPatterns(bitboard, 2, 1);

	return (evaluation);
}

int	AI::checkPatterns(Bitboard &bitboard, int player, int opponent) {
	int score = 0;
	
	PatternInfo patterns[NB_HEURISTIC_PATTERNS] = {
		// Two in a row
		{0b0110, 0b0000, 4, player, 49},
		{0b0110, 0b0000, 4, opponent, -50},
		
		// Three in a row
		{0b01110, 0b10000, 5, player, 490},
		{0b01110, 0b00001, 5, player, 490},
		{0b01110, 0b00000, 5, player, 4900},
		{0b01110, 0b10000, 5, opponent, -500},
		{0b01110, 0b00001, 5, opponent, -500},
		{0b01110, 0b00000, 5, opponent, -5000},
		
		// Four in a row
		{0b011110, 0b100000, 6, player, 9000},
		{0b011110, 0b000001, 6, player, 9000},
		{0b011110, 0b000000, 6, player, 99000},
		{0b011110, 0b000001, 6, opponent, -10000},
		{0b011110, 0b100000, 6, opponent, -10000},
		{0b011110, 0b000000, 6, opponent, -100000},
		
		// Possible captures
		{0b0110, 0b1000, 4, player, (2000 * (-_firstPlayerNbCaptures))},
		{0b0110, 0b0001, 4, player, (2000 * (-_firstPlayerNbCaptures))},
		{0b0110, 0b1000, 4, opponent, (2000 * _secondPlayerNbCaptures)},
		{0b0110, 0b0001, 4, opponent, (2000 * _secondPlayerNbCaptures)},
	};
	
	score += bitboard.checkPattern(patterns, NB_HEURISTIC_PATTERNS);
	
	return (score);
}

int AI::evaluatePosition(int x, int y, Bitboard &bitboard) {
	
}
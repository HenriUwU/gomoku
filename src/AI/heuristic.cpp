/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/16 22:56:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

int	AI::heuristic(Bitboard &bitboard) {
	int	evaluation = 0;
	
	std::unordered_set<std::pair<int, int>, pair_hash>	plate = bitboard.getAllStones();

	for (auto& stone : plate) {
		int x = stone.first;
		int y = stone.second;

		if (bitboard.fiveInARow(x, y, 1))
			return (INT_MIN);
		if (bitboard.fiveInARow(x, y, 2))
			return (INT_MAX);
	}
	
	evaluation += countStones(bitboard);
	evaluation += checkPatterns(bitboard, 2, 1);

	return (evaluation);
}

int	AI::countStones(Bitboard &bitboard) {
	int score = 0;
	
	std::unordered_set<std::pair<int, int>, pair_hash>	plate = bitboard.getAllStones();
	
	for (auto& stone : plate) {
		int x = stone.first;
		int y = stone.second;
		int stonePlaced = bitboard.getBit(x, y);
		if (stonePlaced == 1)
			score -= 100;
		else if (stonePlaced == 2)
			score += 100;
	}
	
	return (score);
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
		{0b0110, 0b1000, 4, player, (playersCaptures[0] == 4 ? INT_MIN : 1000 * (-playersCaptures[0]))},
		{0b0110, 0b0001, 4, player, (playersCaptures[0] == 4 ? INT_MIN : 1000 * (-playersCaptures[0]))},
		{0b0110, 0b1000, 4, opponent, (playersCaptures[1] == 4 ? INT_MAX : 1000 * playersCaptures[1])},
		{0b0110, 0b0001, 4, opponent, (playersCaptures[1] == 4 ? INT_MAX : 1000 * playersCaptures[1])},
	};
	
	score += bitboard.checkPattern(patterns, NB_HEURISTIC_PATTERNS);
	
	return (score);
}

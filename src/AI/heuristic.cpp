/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/09/19 14:53:23 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

int	AI::heuristic(Bitboard &bitboard, int depth) {
	int	evaluation = 0;
	(void)depth;
	
	std::unordered_set<std::pair<int, int>, pair_hash>	plate = bitboard.getAllStones();

	for (auto& stone : plate) {
		int x = stone.first;
		int y = stone.second;
		int stonePlaced = bitboard.getBit(x, y);
		if (stonePlaced == 1) {
			evaluation -= 100;
		} else if (stonePlaced == 2) {
			evaluation += 100;
		}
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
	
	PatternInfo patterns[20] = {
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
		
		// Five in a row
		{0b11111, 0b00000, 5, player, INT_MAX},
		{0b00000, 0b11111, 5, opponent, INT_MIN},
	};
	
	score += bitboard.checkPattern(patterns, 20);
	
	return (score);
}

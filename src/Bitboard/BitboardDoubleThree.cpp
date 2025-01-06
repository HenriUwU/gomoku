/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_double-three.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:21:52 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 14:35:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool Bitboard::isDoubleThree(int x, int y, int player) {
	PatternInfo pattern[] = {
		{0b01110, 0b00000, 5, player, 2},
		{0b010110, 0b000000, 6, player, 2},
		{0b011010, 0b000000, 6, player, 2},
	};
	int currentDoubleThree = 0;
	int createdDoubleThree = 0;
	Bitboard tmp = *this;

	currentDoubleThree = tmp.evaluatePatterns(pattern, 3) / 2;
	std::vector<std::pair<int, int>> capturedStones = tmp.placeStoneAI(x, y, player, true);
	createdDoubleThree = tmp.evaluatePatterns(pattern, 3) / 2;

	if (createdDoubleThree - currentDoubleThree >= 2 && capturedStones.size() == 0)
		return true;
	return false;
}

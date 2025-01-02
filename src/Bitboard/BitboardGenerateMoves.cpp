/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_generate_moves.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:04:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 17:05:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generatePossibleMoves(int player) {
	std::unordered_set<std::pair<int, int>, pair_hash>		uniqueMoves;
	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	int														margin = 1;

	for (auto& stone : currentStones) {
		int startX = std::max(0, stone.first - margin);
		int endX = std::min(BOARD_SIZE - 1, stone.first + margin);
		int startY = std::max(0, stone.second - margin);
		int endY = std::min(BOARD_SIZE - 1, stone.second + margin);

		for (int x = startX; x <= endX; ++x) {
			for (int y = startY; y <= endY; ++y) {
				if (!getBit(x, y)) {
					if (isLegalMoveForAI(x, y, player))
						uniqueMoves.emplace(x, y);
				}
			}
		}
	}
	return (uniqueMoves);
}

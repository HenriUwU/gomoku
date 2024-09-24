/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:29:01 by hsebille          #+#    #+#             */
/*   Updated: 2024/09/19 15:10:50 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

std::vector<std::pair<int, int>> AI::sortMoves(const std::unordered_set<std::pair<int, int>, pair_hash> &possibleMoves, Bitboard &bitboard, bool maximizingPlayer) {
    std::unordered_map<std::pair<int, int>, int, pair_hash>	moveScores;
    std::vector<std::pair<int, int>>						sortedMoves(possibleMoves.begin(), possibleMoves.end());

    for (const auto& move : possibleMoves) {
        std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(move.first, move.second, maximizingPlayer ? 2 : 1, true);
        moveScores[move] = heuristic(bitboard, 0);
		for (const auto& stone : removedStones) {
			bitboard.placeStoneAI(stone.first, stone.second, maximizingPlayer ? 1 : 2, false);
		}
        bitboard.removeStone(move.first, move.second, maximizingPlayer ? 2 : 1);
    }

    std::sort(sortedMoves.begin(), sortedMoves.end(), [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return (maximizingPlayer ? moveScores[a] > moveScores[b] : moveScores[a] < moveScores[b]);
    });

    return sortedMoves;
}
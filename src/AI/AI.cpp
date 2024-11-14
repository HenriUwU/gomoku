/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:42:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/11 19:30:00 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

AI::AI() {}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	Bitboard tmp = bitboard;
	std::pair<int, int> move = negamax(tmp, MINIMAX_DEPTH, true, INT_MIN, INT_MAX).position;
	bitboard.placeStone(move.first, move.second, 2);
}

Move AI::negamax(Bitboard &bitboard, int depth, bool playerTwoTurn, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver()) {
		if (playerTwoTurn)
			return {std::pair<int, int>(-1, -1), heuristic(bitboard)};
		else
			return {std::pair<int, int>(-1, -1), -heuristic(bitboard)};
	}
	
	int myId = playerTwoTurn ? 2 : 1;
	int opponentId = playerTwoTurn ? 1 : 2;
	
	std::unordered_set<std::pair<int, int>, pair_hash> possibleMoves = bitboard.generatePossibleMoves(myId);
	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, myId);
	
	Move bestMove = {std::pair<int, int>(9, 9), INT_MIN};
	
	for (size_t i = 0; i < MAX_TESTED_MOVES && i < sortedMoves.size() ; i++) {
		auto& possibleMove = sortedMoves[i];
		Move tmp;

		std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, myId, true);

		if (i == 0)
			tmp = negamax(bitboard, depth - 1, !playerTwoTurn, -beta, -alpha);
		else {
			tmp = negamax(bitboard, depth - 1, !playerTwoTurn, -alpha - 1, -alpha);
			if (alpha < tmp.score && tmp.score < beta)
				tmp = negamax(bitboard, depth - 1, !playerTwoTurn, -beta, -tmp.score);
		}

		tmp.score = -tmp.score;

		for (const auto& stone : removedStones) {
			bitboard.placeStoneAI(stone.first, stone.second, opponentId, false);
		}
		bitboard.removeStone(possibleMove.first, possibleMove.second, myId);

		if (tmp.score > bestMove.score) {
			bestMove.score = tmp.score;
			bestMove.position = possibleMove;
		}
		
		alpha = std::max(alpha, tmp.score);
		if (alpha >= beta)
			break;
	}
	return bestMove;
}
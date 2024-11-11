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
	int hash = bitboard.hash();
	if (depth == 0 || bitboard.isGameOver()) {
		int value = 0;
		std::unordered_map<int, int>::iterator it = _heuristicValuesOfBoards.find(hash);

		if (it != _heuristicValuesOfBoards.end()) {
			value = it->second;
		} else {
			value = heuristic(bitboard);
			_heuristicValuesOfBoards.insert({hash, value});
		}
		
		if (playerTwoTurn)
			return {std::pair<int, int>(9, 9), value};
		else
			return {std::pair<int, int>(9, 9), -value};
	}
	
	int myId = playerTwoTurn ? 2 : 1;
	int opponentId = playerTwoTurn ? 1 : 2;
	
	std::unordered_set<std::pair<int, int>, pair_hash> possibleMoves = bitboard.generatePossibleMoves(myId);
	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, myId);
	
	Move bestMove = {std::pair<int, int>(9, 9), INT_MIN};
	
	for (size_t i = 0; i < MAX_TESTED_MOVES && i < sortedMoves.size() ; i++) {
		auto& possibleMove = sortedMoves[i];
		
		std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, myId, true);
		Move tmp = negamax(bitboard, depth - 1, !playerTwoTurn, -beta, -alpha);
		tmp.score = -tmp.score;
		for (const auto& stone : removedStones) {
			bitboard.placeStoneAI(stone.first, stone.second, opponentId, false);
		}
		bitboard.removeStone(possibleMove.first, possibleMove.second, myId);
		if (tmp.score > bestMove.score) {
			bestMove.score = tmp.score;
			bestMove.position = possibleMove;
		}
		
		alpha = std::max(alpha, bestMove.score);
		if (alpha >= beta)
			break;
	}
	return bestMove;
}
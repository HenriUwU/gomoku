/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:42:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/21 16:12:36 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

AI::AI() {}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	Bitboard tmp = bitboard;
	_firstPlayerNbCaptures = playersCaptures[0];
	_secondPlayerNbCaptures = playersCaptures[1];
	std::pair<int, int> move = negamax(tmp, MINIMAX_DEPTH, true, INT_MIN, INT_MAX).position;
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int> AI::moveSuggestion(Bitboard &bitboard, int player) {
    Bitboard tmp = bitboard;
	_firstPlayerNbCaptures = playersCaptures[0];
	_secondPlayerNbCaptures = playersCaptures[1];
	std::pair<int, int> move = negamax(tmp, MOVE_SUGGESTION_DEPTH, (player == 1) ? false : true, INT_MIN, INT_MAX).position;
	return move;
}

Move AI::negamax(Bitboard &bitboard, int depth, bool playerTwoTurn, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver() || _firstPlayerNbCaptures == 5 || _secondPlayerNbCaptures == 5) {
		int heuristic = 0;
		int hash = bitboard.hash();
		
		std::unordered_map<int, int>::iterator it = _heuristicValuesOfBoards.find(hash);
		if (it != _heuristicValuesOfBoards.end()) {
			heuristic = it->second;
		}
		else {
			heuristic = this->heuristic(bitboard);
			_heuristicValuesOfBoards[hash] = heuristic;
		}
		
		if (playerTwoTurn)
			return {std::pair<int, int>(-1, -1), heuristic};
		else
			return {std::pair<int, int>(-1, -1), -heuristic};
	}
	
	int myId = playerTwoTurn ? 2 : 1;
	int opponentId = playerTwoTurn ? 1 : 2;
	
	std::unordered_set<std::pair<int, int>, pair_hash> possibleMoves = bitboard.generatePossibleMoves(myId);
	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, playerTwoTurn);
	
	Move bestMove = {std::pair<int, int>(9, 9), INT_MIN};
	
	for (size_t i = 0; i < MAX_TESTED_MOVES && i < sortedMoves.size() ; i++) {
		auto& possibleMove = sortedMoves[i];
		Move tmp;

		std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, myId, true);
		if (playerTwoTurn)
			_firstPlayerNbCaptures += removedStones.size() / 2;
		else
			_secondPlayerNbCaptures += removedStones.size() / 2;

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
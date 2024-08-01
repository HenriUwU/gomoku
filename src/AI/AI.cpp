/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/08/01 17:24:41 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {
	initializeCenterScores();
}

AI::~AI() {}

void AI::initializeCenterScores() {
	int centerX = BOARD_SIZE / 2;
	int centerY = BOARD_SIZE / 2;
		
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			int distance = abs(x - centerX) + abs(y - centerY);
			_centerScores[x][y] = BOARD_SIZE - distance;
		}
	}
}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove(bitboard);
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int> AI::findBestMove(Bitboard &bitboard) {
	std::vector<std::future<std::pair<std::pair<int, int> , int>>>	futureMoves;
	std::unordered_set<std::pair<int, int>, pair_hash>				possibleMoves = bitboard.generatePossibleMoves(2);
	std::pair<int, int>												bestMove = {-1, -1};
	double															bestValue = -INFINITY;

	auto evaluateMove = [&](std::pair<int, int> move) {
		Bitboard tempBoard = bitboard;
		tempBoard.placeStoneAI(move.first, move.second, 2);
		int moveValue = minimax(tempBoard, 4, true, INT_MIN, INT_MAX);
		tempBoard.removeStone(move.first, move.second, 2);
		return std::make_pair(move, moveValue);
	};

	for (const auto& move : possibleMoves) {
		futureMoves.push_back(std::async(std::launch::async, evaluateMove, move));
	}

	for (auto& futureMove : futureMoves) {
		std::pair<std::pair<int, int> , int> result = futureMove.get();
		std::pair<int, int> move = result.first;
		int moveValue = result.second;
		
		if (moveValue > bestValue) {
			bestValue = moveValue;
			bestMove = move;
		}
	}

	return bestMove;
}

int	AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver())
		return heuristic(bitboard, depth);
	
	std::unordered_set<std::pair<int, int>, pair_hash>	possibleMoves = bitboard.generatePossibleMoves(maximizingPlayer ? 2 : 1);
	int 												bestValue;

	if (maximizingPlayer) {
		bestValue = INT_MIN;
		
		for (auto& possibleMove : possibleMoves) {
			bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2);
			int value = minimax(bitboard, depth - 1, false, alpha, beta);
			bitboard.removeStone(possibleMove.first, possibleMove.second, 2);

			bestValue = std::max(bestValue, value);
			alpha = std::max(alpha, bestValue);
			if (beta <= alpha)
				break;
		}
	}
	else {
		bestValue = INT_MAX;

		for (auto& possibleMove : possibleMoves) {
			bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 1);
			int value = minimax(bitboard, depth - 1, true, alpha, beta);
			bitboard.removeStone(possibleMove.first, possibleMove.second, 1);

			bestValue = std::min(bestValue, value);
			beta = std::min(beta, bestValue);
			if (beta <= alpha)
				break;
		}
	}
	return bestValue;
}
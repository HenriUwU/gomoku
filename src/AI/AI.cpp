/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:42:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/10 13:44:33 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

AI::AI() {}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove(bitboard);
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int> AI::findBestMove(Bitboard &bitboard) {
	std::unordered_set<std::pair<int, int>, pair_hash>				possibleMoves = bitboard.generateMoves(2);
	std::pair<int, int>												bestMove = {9, 9};
	double															bestValue = -INFINITY;
	
	if (possibleMoves.empty())
		possibleMoves = bitboard.generatePossibleMoves(2);
	if (possibleMoves.empty())
		return bestMove;

	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, true);
	std::cout << "Sorted Moves : " << std::endl;
	for (size_t i = 0; i < sortedMoves.size(); i++) {
		std::cout << "Move: " << sortedMoves[i].first << " " << sortedMoves[i].second << std::endl;
	}
	std::cout << std::endl;

	//unsigned int maxThreads = std::thread::hardware_concurrency();
	ThreadPool pool(64);

	for (size_t i = 0; i < MAX_TESTED_MOVES && i < sortedMoves.size(); i++) {
		std::pair<int, int> move = sortedMoves[i];

		pool.enqueue([&, move] {
			Bitboard tempBoard = bitboard;

			std::vector<std::pair<int, int>> removedStones = tempBoard.placeStoneAI(move.first, move.second, 2, true);
			int moveValue = minimax(tempBoard, MINIMAX_DEPTH, false, INT_MIN, INT_MAX);
			for (const auto& stone : removedStones)
				tempBoard.placeStoneAI(stone.first, stone.second, 1, false);
			tempBoard.removeStone(move.first, move.second, 2);

			std::lock_guard<std::mutex> lock(bestMoveMutex);
			std::cout << "Tested move : " << move.first << " | " << move.second << std::endl;
			if (moveValue > bestValue) {
				bestValue = moveValue;
				bestMove = move;
			}
		});
	}

	pool.waitForAll(); 

	std::cout << std::endl;
	std::cout << "final move : " << bestMove.first << " | " << bestMove.second << std::endl;
	std::cout << std::endl;

	return (bestMove);
}

int AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver()) {
		return heuristic(bitboard);
	}

	std::unordered_set<std::pair<int, int>, pair_hash> possibleMoves = bitboard.generateMoves(maximizingPlayer ? 2 : 1);
	if (possibleMoves.empty())
		possibleMoves = bitboard.generatePossibleMoves(maximizingPlayer ? 2 : 1);
	
	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, maximizingPlayer);

	int bestValue = maximizingPlayer ? INT_MIN : INT_MAX;

	for (size_t i = 0; i < MAX_TESTED_MOVES; ++i) {
		int value = 0;
		
		if (i >= sortedMoves.size())
			break;
		auto& possibleMove = sortedMoves[i];
		
		if (maximizingPlayer) {
			std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2, true);
			value += (removedStones.size() * 500) / 2;
			value += minimax(bitboard, depth - 1, false, alpha, beta);
			for (const auto& stone : removedStones) {
				bitboard.placeStoneAI(stone.first, stone.second, 1, false);
			}
			bitboard.removeStone(possibleMove.first, possibleMove.second, 2);

			bestValue = std::max(bestValue, value);
			alpha = std::max(alpha, bestValue);
			if (beta <= alpha)
				break;
		} else {
			std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 1, true);
			value -= (removedStones.size() * 500) / 2;
			value += minimax(bitboard, depth - 1, true, alpha, beta);
			for (const auto& stone : removedStones) {
				bitboard.placeStoneAI(stone.first, stone.second, 2, false);
			}
			bitboard.removeStone(possibleMove.first, possibleMove.second, 1);

			bestValue = std::min(bestValue, value);
			beta = std::min(beta, bestValue);
			if (beta <= alpha)
				break;
		}
	}
	return bestValue;
}
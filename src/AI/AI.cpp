/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:39 by laprieur          #+#    #+#             */
/*   Updated: 2024/09/13 15:14:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/AI.hpp"

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
	std::pair<int, int>												bestMove = {9, 9};
	double															bestValue = -INFINITY;
	
	if (possibleMoves.empty())
		return bestMove;

	auto evaluateMove = [&](std::pair<int, int> move) {
		Bitboard tempBoard = bitboard;
		std::vector<std::pair<int, int>> removedStones = tempBoard.placeStoneAI(move.first, move.second, 2, true);
		int moveValue = minimax(tempBoard, 6, true, INT_MIN, INT_MAX);
		for (const auto& stone : removedStones) {
			tempBoard.placeStoneAI(stone.first, stone.second, 1, false);
		}
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

int AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver()) {
		return heuristic(bitboard, depth);
	}

	std::unordered_set<std::pair<int, int>, pair_hash> possibleMoves = bitboard.generatePossibleMoves(maximizingPlayer ? 2 : 1);
	std::vector<std::pair<int, int>> sortedMoves = sortMoves(possibleMoves, bitboard, maximizingPlayer);

	int bestValue = maximizingPlayer ? INT_MIN : INT_MAX;

	int reductionDepth = (depth > 2) ? depth - 2 : 0;

	for (size_t i = 0; i < sortedMoves.size(); ++i) {
		int value = 0;
		auto& possibleMove = sortedMoves[i];
		
		if (maximizingPlayer) {
			std::vector<std::pair<int, int>> removedStones = bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2, true);
			value += (removedStones.size() * 500) / 2;
			// capture stones in placStoneAI and keep in memory the stones to replace after
			if (i > 3) {
				value += minimax(bitboard, reductionDepth, false, alpha, beta);
			} else {
				value += minimax(bitboard, depth - 1, false, alpha, beta);
			}
			// replace captured stones here
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
			if (i > 3) {
				value += minimax(bitboard, reductionDepth, true, alpha, beta);
			} else {
				value += minimax(bitboard, depth - 1, true, alpha, beta);
			}
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
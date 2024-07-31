/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/31 11:12:55 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {
	initializeCenterScores();
	initializeZobrist();
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

void AI::initializeZobrist() {
	std::srand(static_cast<uint32_t>(std::time(0)));

	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int player = 0; player < 2; player++) {
				_zobristTable[x][y][player] = (static_cast<uint64_t>(std::rand()) << 32) | std::rand();
			}
		}
	}
}

uint64_t AI::generateZobristKey(Bitboard &bitboard) {
	uint64_t key = 0;
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			int stone = bitboard.getBit(x, y);
			if (stone != 0) {
				key ^= _zobristTable[x][y][stone - 1];
			}
		}
	}
	return key;
}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove(bitboard);
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int>	AI::findBestMove(Bitboard &bitboard) {
	std::unordered_set<std::pair<int, int>, pair_hash>	possibleMoves = bitboard.generatePossibleMoves(2);
	std::pair<int, int>									bestMove = {-1, -1};
	double												bestValue = -INFINITY;
	int													moveValue;

	for (auto& possibleMove : possibleMoves) {
		bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2);
		moveValue = minimax(bitboard, 4, true, INT_MIN, INT_MAX);
		bitboard.removeStone(possibleMove.first, possibleMove.second, 2);
		if (moveValue > bestValue) {
			bestValue = moveValue;
			bestMove = possibleMove;
		}
	}
	return (bestMove);
}

int	AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	//-- Verify transposition table to check if evaluation already exists --//
/* 	uint64_t key = generateZobristKey(bitboard);

	if (_transpositionTable.find(key) != _transpositionTable.end()) {
		TTEntry entry = _transpositionTable[key];
		if (entry.depth >= depth) {
			if (entry.type == EXACT) {
				return entry.value;
			} else if (entry.type == LOWERBOUND) {
				alpha = std::max(alpha, entry.value);
			} else if (entry.type == UPPERBOUND) {
				beta = std::min(beta, entry.value);
			}
			if (alpha >= beta) {
				return entry.value;
			}
		}
	} */

	//-- Actual minimax algorithm with alpha-beta pruning --//
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
			if (beta <= alpha) {
				break;
			}
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
			if (beta <= alpha) {
				break;
			}
		}
	}
	
	//-- Stock the current node in the transposition table --//
	/* NodeType type;
	if (bestValue <= alpha) {
		type = UPPERBOUND;
	} else if (bestValue >= beta) {
		type = LOWERBOUND;
	} else {
		type = EXACT;
	}
	_transpositionTable[key] = { key, bestValue, depth, type }; */

	return bestValue;
}

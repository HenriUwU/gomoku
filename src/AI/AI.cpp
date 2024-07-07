/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/07 16:41:06 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {
	int centerX = BOARD_SIZE / 2;
	int centerY = BOARD_SIZE / 2;
		
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			// Calcul de la distance de Manhattan au centre
			int distance = abs(x - centerX) + abs(y - centerY);

			// Conversion de la distance en score (plus la distance est courte, plus le score est élevé)
			_centerScores[x][y] = BOARD_SIZE - distance;
		}
	}
}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove(bitboard);
	std::cout << "AI played at " << move.first << " " << move.second << std::endl;
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int>	AI::findBestMove(Bitboard &bitboard) {
	std::vector<std::pair<int, int>>	possibleMoves = bitboard.generatePossibleMoves(2);
	std::pair<int, int>					bestMove = {-1, -1};
	double								bestValue = -INFINITY;
	int									moveValue;

	for (auto& possibleMove : possibleMoves) {
		bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2);
		moveValue = minimax(bitboard, 2, true, INT_MIN, INT_MAX);
		bitboard.removeStone(possibleMove.first, possibleMove.second, 2);
		if (moveValue > bestValue) {
			bestValue = moveValue;
			bestMove = possibleMove;
		}
	}

	return (bestMove);
}

int	AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver()) {
		return heuristic(bitboard, maximizingPlayer);
	}
	
	std::vector<std::pair<int, int>>	possibleMoves = bitboard.generatePossibleMoves(maximizingPlayer ? 2 : 1);

	if (maximizingPlayer) {
		int bestValue = INT_MIN;
			
		for (auto& possibleMove : possibleMoves) {
			bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 2);
			bestValue = std::max(bestValue, minimax(bitboard, depth - 1, false, alpha, beta));
			bitboard.removeStone(possibleMove.first, possibleMove.second, 2);
			
			alpha = std::max(alpha, bestValue);
			if (beta <= alpha)
				break;
		}
		return (bestValue);
	}
	else {
		int bestValue = INT_MAX;

		for (auto& possibleMove : possibleMoves) {
			bitboard.placeStoneAI(possibleMove.first, possibleMove.second, 1);
			bestValue = std::min(bestValue, minimax(bitboard, depth - 1, true, alpha, beta));
			bitboard.removeStone(possibleMove.first, possibleMove.second, 1);
			
			beta = std::min(beta, bestValue);
			if (beta <= alpha)
				break;
		}
		return (bestValue);
	}
}

int	AI::heuristic(Bitboard &bitboard, bool maximizingPlayer) {
	int	evaluation = 0;

	int ai = maximizingPlayer ? 2 : 1;
    int opponent = maximizingPlayer ? 1 : 2;

    evaluation += checkCenterControl(bitboard, ai, opponent);
	evaluation += checkPatterns(bitboard, ai);
	evaluation -= checkPatterns(bitboard, opponent);

	return (evaluation);
}

int AI::checkCenterControl(Bitboard &bitboard, int ai, int opponent) {
	int score = 0;

	for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int stone = bitboard.getBit(x, y);
            if (stone == ai) {
                score += _centerScores[x][y];
            } else if (stone == opponent) {
                score -= _centerScores[x][y];
            }
        }
    }
	return score;
}

int	AI::checkPatterns(Bitboard &bitboard, int player) {
	int score = 0;

	//-- Two in a row --//
	score += bitboard.checkPattern(0b0110, 0b0000, 4, player) * 100;

	//-- Three in a row --//
	score += bitboard.checkPattern(0b01110, 0b10000, 5, player) * 250;
	score += bitboard.checkPattern(0b01110, 0b00001, 5, player) * 250;
	score += bitboard.checkPattern(0b01110, 0b00000, 5, player) * 300;

	//-- Four in a row --//
	score += bitboard.checkPattern(0b011110, 0b100000, 6, player) * 750;
	score += bitboard.checkPattern(0b011110, 0b000001, 6, player) * 750;
	score += bitboard.checkPattern(0b011110, 0b000000, 6, player) * 1000;

	//-- Five in a row --//
	score += bitboard.checkPattern(0b11111, 0b00000, 5, player) * 10000;

	//-- Player Capture --//
	score += bitboard.checkPattern(0b1000, 0b0110, 4, player) * 200;
	score += bitboard.checkPattern(0b0001, 0b0110, 4, player) * 200;
	score += bitboard.checkPattern(0b1001, 0b0110, 4, player) * 400;

	//-- Opponent Capture --//
	score -= bitboard.checkPattern(0b0110, 0b1000, 4, player) * 200;
	score -= bitboard.checkPattern(0b0110, 0b0001, 4, player) * 200;
	score -= bitboard.checkPattern(0b0110, 0b1001, 4, player) * 400;

	return (score);
}
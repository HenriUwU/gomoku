/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/06 17:28:07 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {
	int centerX = BOARD_SIZE / 2;
	int centerY = BOARD_SIZE / 2;
		
	// Définition de la matrice de scores
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			// Calcul de la distance de Manhattan au centre
			int distance = abs(x - centerX) + abs(y - centerY);

			// Conversion de la distance en score (plus la distance est courte, plus le score est élevé)
			_centerScores[x][y] = BOARD_SIZE - distance;
			std::cout << "Score for : [" << x << "][" << y << "] is : " << BOARD_SIZE - distance << std::endl;
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
	std::vector<std::pair<int, int>>	possibleMoves = generatePossibleMoves(bitboard, 2);
	std::pair<int, int>					bestMove = {-1, -1};
	double								bestValue = -INFINITY;
	int									moveValue;

	for (auto& possibleMove : possibleMoves) {
		std::cout << "Possible move : x = " << possibleMove.first << " y = " << possibleMove.second << std::endl;
		bitboard.placeStone(possibleMove.first, possibleMove.second, 2);
		moveValue = minimax(bitboard, 1, true, INT_MIN, INT_MAX);
		bitboard.removeStone(possibleMove.first, possibleMove.second, 2);
		if (moveValue > bestValue) {
			bestValue = moveValue;
			bestMove = possibleMove;
		}
	}

	return (bestMove);
}

std::vector<std::pair<int, int>> AI::generatePossibleMoves(Bitboard &bitboard, int player) {
	std::vector<std::pair<int, int>> possibleMoves;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (!bitboard.getBit(x, y) && bitboard.isLegalMove(x, y, player)) {
				possibleMoves.push_back({x, y});
			}
		}
	}
	return (possibleMoves);
}

int	AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) {
	if (depth == 0 || bitboard.isGameOver()) {
		return heuristic(bitboard, maximizingPlayer);
	}
	
	std::vector<std::pair<int, int>>	possibleMoves = generatePossibleMoves(bitboard, maximizingPlayer ? 2 : 1);

	if (maximizingPlayer) {
		int bestValue = INT_MIN;
			
		for (auto& possibleMove : possibleMoves) {
			bitboard.placeStone(possibleMove.first, possibleMove.second, 2);
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
			bitboard.placeStone(possibleMove.first, possibleMove.second, 1);
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

	int player = maximizingPlayer ? 2 : 1;
    int opponent = maximizingPlayer ? 1 : 2;

    // Parcourir le plateau pour évaluer les pierres
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int stone = bitboard.getBit(x, y);
            if (stone == player) {
                evaluation += _centerScores[x][y];
            } else if (stone == opponent) {
                evaluation -= _centerScores[x][y];
            }
        }
    }
	
	return (-evaluation);
}

/* int AI::centerControl() {

} */
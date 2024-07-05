/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/05 16:38:35 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove(bitboard);
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int>	AI::findBestMove(Bitboard &bitboard) {
	std::vector<std::pair<int, int>>	possibleMoves = generatePossibleMoves(bitboard);
	std::pair<int, int>					bestMove = {-1, -1};
	double								bestValue = -INFINITY;
	int									moveValue;

	for (auto& possibleMove : possibleMoves) {
		bitboard.placeStone(possibleMove.first, possibleMove.second, 2);
		moveValue = minimax(bitboard, 10, 2);
		bitboard.removeStone(possibleMove.first, possibleMove.second, 2);
		if (moveValue > bestValue) {
			bestValue = moveValue;
			bestMove = possibleMove;
		}
	}

	return (bestMove);
}

std::vector<std::pair<int, int>> AI::generatePossibleMoves(Bitboard &bitboard) {
	std::vector<std::pair<int, int>> possibleMoves;

	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (!bitboard.getBit(x, y) && bitboard.isLegalMove(x, y, 2)) {
				possibleMoves.push_back({x, y});
			}
		}
	}
	return (possibleMoves);
}

int	AI::minimax(Bitboard &bitboard, int depth, bool maximizingPlayer) {
	(void)bitboard;
	(void)depth;
	(void)maximizingPlayer;
	
	if (depth == 0) {
		return heuristic(bitboard, maximizingPlayer ? 2 : 1); // maximizing player is always AI
	}
	return (0);
}

int	AI::heuristic(Bitboard &bitboard, int maximizingPlayer) {
	(void)maximizingPlayer;
	return (bitboard.getBit(0, 0));
}
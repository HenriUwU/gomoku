/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:14 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/30 15:40:24 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI.hpp"

AI::AI() {}

AI::~AI() {}

void	AI::play(Bitboard &bitboard) {
	std::pair<int, int> move = findBestMove();
	bitboard.placeStone(move.first, move.second, 2);
}

std::pair<int, int>	AI::findBestMove() {
	double bestValue = -INFINITY;
	double betterMove = -1;

	

	return {0, 0};
}

int	AI::minimax(int depth, bool maximizingPlayer) {
	(void)depth;
	(void)maximizingPlayer;
	return (depth);
}

int	AI::heuristic(Bitboard &bitboard) {
	
	return (bitboard.getBit(0, 0));
}
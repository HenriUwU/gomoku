/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:23:02 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/10 14:50:16 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
	
class Bitboard;

#define MINIMAX_DEPTH 6
#define MAX_TESTED_MOVES 15
#define NB_HEURISTIC_PATTERNS 22

struct Move {
	std::pair<int, int> position;
	int score;
};

class AI {
	private:
		static const int	BOARD_SIZE = 19;
		std::mutex			bestMoveMutex;
		std::unordered_map<int, int>	_heuristicValuesOfBoards;

	public:
		AI();
		~AI();
		
		int		minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) __attribute__((hot));
		Move	negamax(Bitboard &bitboard, int depth, bool aiTurn, int alpha, int beta) __attribute__((hot));
		int		heuristic(Bitboard &bitboard) __attribute__((hot));
		int		countStones(Bitboard &bitboard);
		int		checkPatterns(Bitboard &bitboard, int player, int opponent);

		void	play(Bitboard &bitboard);
		void	quicksort(std::vector<std::pair<std::pair<int, int>, int>> &vec, int low, int high);
		
		std::pair<int, int>					findBestMove(Bitboard& bitboard) __attribute__((hot));
		std::vector<std::pair<int, int>>	sortMoves(const std::unordered_set<std::pair<int, int>, pair_hash> &possibleMoves, Bitboard &bitboard, bool maximizingPlayer);
};
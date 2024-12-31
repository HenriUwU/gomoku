/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:23:02 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 15:15:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
	
class Bitboard;

#define MINIMAX_DEPTH 10
#define MAX_TESTED_MOVES 6
#define MOVE_SUGGESTION_DEPTH 4
#define NB_HEURISTIC_PATTERNS 18

struct Move {
	std::pair<int, int> position;
	int score;
};

class AI {
	private:
		static const int	BOARD_SIZE = 19;
		std::unordered_map<int, int>	_heuristicValuesOfBoards;
		
		int								_firstPlayerNbCaptures;
		int								_secondPlayerNbCaptures;

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
		
        std::pair<int, int>                 moveSuggestion(Bitboard &bitboard, int player);
		std::pair<int, int>					findBestMove(Bitboard& bitboard) __attribute__((hot));
		std::vector<std::pair<int, int>>	sortMoves(const std::unordered_set<std::pair<int, int>, pair_hash> &possibleMoves, Bitboard &bitboard, bool maximizingPlayer);
};
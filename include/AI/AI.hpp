/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:34:05 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/09 14:35:19 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
	
class Bitboard;

#define MINIMAX_DEPTH 6
#define MAX_TESTED_MOVES 15

class AI {
	private:
		static const int						BOARD_SIZE = 19;

	public:
		AI();
		~AI();
		
		int		minimax(Bitboard &bitboard, int depth, bool maximizingPlayer, int alpha, int beta) __attribute__((hot));
		int		heuristic(Bitboard &bitboard, int depth) __attribute__((hot));
		int		countStones(Bitboard &bitboard);
		int		checkPatterns(Bitboard &bitboard, int player, int opponent);

		void	play(Bitboard &bitboard);
		void	quicksort(std::vector<std::pair<std::pair<int, int>, int>> &vec, int low, int high);
		
		std::pair<int, int>					findBestMove(Bitboard& bitboard);
		std::vector<std::pair<int, int>>	sortMoves(const std::unordered_set<std::pair<int, int>, pair_hash> &possibleMoves, Bitboard &bitboard, bool maximizingPlayer);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:01:02 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/05 15:42:52 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
	
class Bitboard;

class AI {
	private:
		static const int					BOARD_SIZE = 19;

	public:
		AI();
		~AI();
		
		int									minimax(Bitboard& bitboard, int depth, bool maximizingPlayer);
		int									heuristic(Bitboard &bitboard, int maximizingPlayer);

		void								play(Bitboard &bitboard);

		std::pair<int, int>					findBestMove(Bitboard& bitboard);
		std::vector<std::pair<int, int>>	generatePossibleMoves(Bitboard &bitboard);
};
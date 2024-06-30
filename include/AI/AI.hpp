/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:01:02 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/30 14:58:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Bitboard;

class AI {
	private:

	public:
		AI();
		~AI();

		std::pair<int, int>	findBestMove();
		void				play(Bitboard &bitboard);

		int					heuristic(Bitboard &bitboard);
		int					minimax(int depth, bool maximizingPlayer);
};
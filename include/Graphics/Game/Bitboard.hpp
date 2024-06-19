/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 13:06:35 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

class Bitboard {
	private:
		static const int					BOARD_SIZE = 19;
		static const int					BITBOARD_SIZE = 6;

		//--- Create 2 arrays of 64 * 6 bits to store the bitboards ---//
		std::array<uint64_t, BITBOARD_SIZE>	_firstPlayerBoard;
		std::array<uint64_t, BITBOARD_SIZE>	_secondPlayerBoard;
	
	public:
		Bitboard();
		~Bitboard();

		void	placeStone(int x, int y, int player);
		void	getBitPosition(int x, int y, int &bitboardIndex, int &bitboardPosition);
		void	printBoard();

		bool	isCellEmpty(int x, int y);
};
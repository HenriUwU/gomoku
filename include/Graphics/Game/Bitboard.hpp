/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 15:11:52 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

class Bitboard {
	private:
		static const int					BOARD_SIZE = 19;

		//--- Create 2 arrays of 64 * 19 bits to store the bitboards ---//
		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoard;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoard;
	
	public:
		Bitboard();
		~Bitboard();

		void	placeStone(int x, int y, int player);
		void	printBoard();
};
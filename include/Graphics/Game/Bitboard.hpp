/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/20 10:42:48 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

class Bitboard {
	private:
		static const int					BOARD_SIZE = 19;

		//--- Create 2 arrays of 64 * 19 bits to store the bitboards for horizontal lines ---//
		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardLines;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardLines;

		//--- Create 2 arrays of 64 * 19 bits to store the bitboards for vertical lines ---//
		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardColumns;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardColumns;
		
		// rotated bitboard for diagonals
	
	public:
		Bitboard();
		~Bitboard();

		bool	placeStone(int x, int y, int player);
		bool	isCellEmpty(int x, int y);
		void	printBoard();
		int		getBit(int x, int y) const;
};
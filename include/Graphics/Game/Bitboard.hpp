/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/20 13:15:44 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

class Bitboard {
	private:
		static const int					BOARD_SIZE = 19;

		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardLines;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardLines;

		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardColumns;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardColumns;
		
		std::array<uint32_t, BOARD_SIZE * 2 -1>	_firstPlayerBoardDiagonals;
		std::array<uint32_t, BOARD_SIZE * 2 -1>	_secondPlayerBoardDiagonals;

		std::array<uint32_t, BOARD_SIZE * 2 -1>	_firstPlayerBoardAntiDiagonals;
		std::array<uint32_t, BOARD_SIZE * 2 -1>	_secondPlayerBoardAntiDiagonals;		
	
	public:
		Bitboard();
		~Bitboard();

		int			getBit(int x, int y) const;

		bool		placeStone(int x, int y, int player);
		bool		isCellEmpty(int x, int y);

		void		printBoard();
		void		createColumns();
		void		createDiagonals();
		void 		createAntiDiagonals();
};
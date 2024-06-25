/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/25 15:07:35 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

typedef enum {
	//-- Five in a row --//
	FIVE_IN_A_ROW = 0b11111,
	
	//-- Captures --//
	PAIR = 0b0110,
	CAPTURE = 0b1001,
	
	//-- Free-Three --//
	FIRST_FREE_THREE = 0b01110,
} Patterns;

class Bitboard {
	private:
		static const int					BOARD_SIZE = 19;

		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardLines;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardLines;

		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardColumns;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardColumns;
		
		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardDiagonals;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardDiagonals;

		std::array<uint32_t, BOARD_SIZE>	_firstPlayerBoardAntiDiagonals;
		std::array<uint32_t, BOARD_SIZE>	_secondPlayerBoardAntiDiagonals;		

	public:
		Bitboard();
		~Bitboard();

		int			getBit(int x, int y) const;
		int			isCapturingMove(int x, int y, int player);

		bool		placeStone(int x, int y, int player);
		bool		isCellEmpty(int x, int y);

		void		printBoard();
		void		createColumns();
		void		createDiagonals();
		void		createAntiDiagonals();

		uint32_t	getSelection(uint32_t bitboard, int nbBits, int bitsPos);
};
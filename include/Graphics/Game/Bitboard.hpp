/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/30 17:35:18 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include <array>

typedef enum {
	FIVE_IN_A_ROW = 0b11111,
	
	PAIR = 0b0110,
	CAPTURE = 0b1001,
	
	FIRST_FREE_THREE = 0b01110,
	SECOND_FREE_THREE = 0b010110,
	THIRD_FREE_THREE = 0b011010,
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
		int			rotateY45(int x, int y);
		int			rotateY315(int x, int y);

		bool		isCellEmpty(int x, int y);
		bool		placeStone(int x, int y, int player);
		void		removeStone(int x, int y, int player);
		bool		isLegalMove(int x, int y, int player);
		bool		isDoubleThree(int x, int y, int player);

		void		printBoard();
		void		createColumns();
		void		createDiagonals();
		void		createAntiDiagonals();

		void		verifyHorizontalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyVerticalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyDiagonalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyAntiDiagonalCapture(int &nbCaptures, int x, int y, int player);

		void		verifyFreeThreeHorizontal(int &nbFreeThree, int x, int y, int player);
		void		verifyFreeThreeVertical(int &nbFreeThree, int x, int y, int player);

		void		makeCapture(int x, int y, int player);
		void		makeHorizontalCapture(int x, int y, int player);
		void		makeVerticalCapture(int x, int y, int player);
		void		makeDiagonalCapture(int x, int y, int player);
		void		makeAntiDiagonalCapture(int x, int y, int player);

		uint32_t	getSelection(uint32_t bitboard, int nbBits, int bitsPos);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:32:43 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/07 18:38:14 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

typedef enum {
	FIVE_IN_A_ROW = 0b11111,
	
	PAIR = 0b0110,
	CAPTURE = 0b1001,
	
	FIRST_FREE_THREE = 0b01110,
	SECOND_FREE_THREE = 0b010110,
	THIRD_FREE_THREE = 0b011010,
} Patterns;

typedef enum {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL,
	ANTIDIAGONAL,
}	Directions;

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
		int			checkPattern(uint32_t pattern, uint32_t opponentPattern, int patternSize, int player);

		bool		placeStone(int x, int y, int player);
		bool		isLegalMove(int x, int y, int player);
		bool		isDoubleThree(int x, int y, int player);
		bool		fiveInARow(int x, int y, int player);
		bool		fiveInARowHorizontal(int x, int y, int player);
		bool		fiveInARowVertical(int x, int y, int player);
		bool		fiveInARowDiagonal(int x, int y, int player);
		bool		fiveInARowAntiDiagonal(int x, int y, int player);
		bool		isGameOver();

		void		printBoard();
		void		update(int x, int y, int player, bool add);
		void		removeStone(int x, int y, int player);
		void		placeStoneAI(int x, int y, int player);

		void		verifyHorizontalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyVerticalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyDiagonalCapture(int &nbCaptures, int x, int y, int player);
		void		verifyAntiDiagonalCapture(int &nbCaptures, int x, int y, int player);

		void		verifyFreeThreeHorizontal(int &nbFreeThree, int x, int y, int player);
		void		verifyFreeThreeVertical(int &nbFreeThree, int x, int y, int player);
		void		verifyFreeThreeDiagonal(int &nbFreeThree, int x, int y, int player);
		void		verifyFreeThreeAntiDiagonal(int &nbFreeThree, int x, int y, int player);

		void		checkPatternHorizontal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player);
		void		checkPatternVertical(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player);
		void		checkPatternDiagonal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player);
		void		checkPatternAntiDiagonal(int x, int y, int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player);

		void		makeCapture(int x, int y, int player);
		void		makeHorizontalCapture(int x, int y, int player);
		void		makeVerticalCapture(int x, int y, int player);
		void		makeDiagonalCapture(int x, int y, int player);
		void		makeAntiDiagonalCapture(int x, int y, int player);
		
		uint32_t	getSelection(uint32_t bitboard, int nbBits, int bitsPos);

		std::unordered_set<std::pair<int, int>, pair_hash>	getAllStones();
		std::unordered_set<std::pair<int, int>, pair_hash>	generatePossibleMoves(int player);
};
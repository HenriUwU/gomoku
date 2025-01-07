/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:40:43 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 21:28:43 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

enum Patterns {
	FIVE_IN_A_ROW		= 0b11111,
	PAIR				= 0b0110,
	CAPTURE				= 0b1001,
	FIRST_FREE_THREE	= 0b01110,
	SECOND_FREE_THREE	= 0b010110,
	THIRD_FREE_THREE	= 0b011010
};

enum Directions {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL,
	ANTIDIAGONAL
};

#define PATTERNS_OF_FOUR 10

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
		
		size_t								_firstHash[BOARD_SIZE];
		size_t								_secondHash[BOARD_SIZE];

		int		rotateY45(int x, int y);
		int		rotateY315(int x, int y);
		int		makeCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int		makeHorizontalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int		makeVerticalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int		makeDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int		makeAntiDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);

		bool	isDoubleThree(int x, int y, int player);
		bool	draw() const;

		void	update(int x, int y, int player, bool add);
		void	verifyHorizontalCapture(int &nbCaptures, int x, int y, int player);
		void	verifyVerticalCapture(int &nbCaptures, int x, int y, int player);
		void	verifyDiagonalCapture(int &nbCaptures, int x, int y, int player);
		void	verifyAntiDiagonalCapture(int &nbCaptures, int x, int y, int player);

		std::unordered_set<std::pair<int, int>, pair_hash>	getAllStones();
		uint32_t											getSelection(uint32_t bitboard, int nbBits, int bitsPos);

	public:
		Bitboard();
		~Bitboard();

		int		hash() const;
		int		getBit(int x, int y) const;
		int		evaluatePatterns(PatternInfo patterns[], int nbPattern);
		int		fiveInARow();

		bool	placeStone(int x, int y, int player);
		bool	isLegalMove(int x, int y, int player);
        bool	isLegalMoveForAI(int x, int y, int player);
		bool	isAlignmentBreakable(PatternInfo alignment[], int player, int opponent);
	
		void	clear();
		void	printBoard();
		void	removeStone(int x, int y, int player);		
		void	printBoardWithPossibleMoves(std::vector<std::pair<int, int>> sortedMoves);

		std::vector<std::pair<int, int>>					placeStoneAI(int x, int y, int player, bool mode);
		std::unordered_set<std::pair<int, int>, pair_hash>	generatePossibleMoves(int player);
};

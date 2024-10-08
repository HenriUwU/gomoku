/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:37:58 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/08 10:33:55 by laprieur         ###   ########.fr       */
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
		int			reverseRotate45(int x, int y);
		int			reverseRotate315(int x, int y);
		int			checkPattern(PatternInfo patterns[], int nbPattern) __attribute__((hot));
		int			countAdjacentStones(int x, int y) const;

		bool		placeStone(int x, int y, int player);
		bool		isLegalMove(int x, int y, int player);
		bool		isDoubleThree(int x, int y, int player);
		bool		fiveInARow(int x, int y, int player);
		bool		fiveInARowHorizontal(int x, int y, int player);
		bool		fiveInARowVertical(int x, int y, int player);
		bool		fiveInARowDiagonal(int x, int y, int player);
		bool		fiveInARowAntiDiagonal(int x, int y, int player);
		bool		isHorizontalAlignmentBreakable(int x, int y, int bitsInAlignment, int player);
		bool		isVerticalAlignmentBreakable(int x, int y, int bitsInAlignment, int player);
		bool		isDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player);
		bool		isAntiDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player);
		bool		isGameOver();
		bool		horizontalCaptureInAlignment(int x, int y, int player);
		bool		verticalCaptureInAlignment(int x, int y, int player);
		bool		diagonalCaptureInAlignment(int x, int y, int player);
		bool		antiDiagonalCaptureInAlignment(int x, int y, int player);
		bool		fifthCaptureAvailable();

		void		printBoard();
		void		update(int x, int y, int player, bool add);
		void		removeStone(int x, int y, int player);
		void		clear();

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

		int			makeCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int			makeHorizontalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int			makeVerticalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int			makeDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		int			makeAntiDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones);
		
		uint32_t	getSelection(uint32_t bitboard, int nbBits, int bitsPos);

		std::vector<std::pair<int, int>>					placeStoneAI(int x, int y, int player, bool mode);
		std::unordered_set<std::pair<int, int>, pair_hash>	getAllStones();
		std::unordered_set<std::pair<int, int>, pair_hash>	generatePossibleMoves(int player);
		std::unordered_set<std::pair<int, int>, pair_hash>	generateMoves(int player);
};

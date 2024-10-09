/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_generate_moves.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:04:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/09 17:22:01 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generateMoves(int player) {
	uint32_t patterns[NB_INTERESTING_PATTERNS] = {
		0b1100, 0b0011, 0b1110, 0b0111, 0b1111,
		0b1001, 0b1010, 0b0101, 0b1011, 0b1101
	};
	
	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	std::unordered_set<std::pair<int, int>, pair_hash>		possibleMoves;

	for (auto& stone : currentStones) {
		for (int i = 0; i < 10; i++) {
			generateMovesHorizontal(possibleMoves, stone, patterns, i);
		}
	}
}

void	Bitboard::generateMovesHorizontal(std::unordered_set& possibleMoves, std::pair<int, int>, uint32_t patterns[], int patternIndex) {
	int x = stone.first;
	int y = stone.second;

	uint32_t firstPlayerBitboard = _firstPlayerBoardLines[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardLines[y];

	if (x + 3 < BOARD_SIZE) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 1 > 0) ? x - 1 : x;
			xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(xMin, y, player))
					possibleMoves.emplace(xMin, y);
				xMin++;
			} 
		}
	}
	
	if (x - 3 > 0) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 4 > 0) ? x - 4 : 0;
			xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(xMin, y, player))
					possibleMoves.emplace(xMin, y);
				xMin++;
			}
		}
	}
}

void	Bitboard::generateMovesVertical(std::unordered_set& possibleMoves, std::pair<int, int>, uint32_t patterns[], int patternIndex) {
	int x = stone.second;
	int y = stone.first;

	uint32_t firstPlayerBitboard = _firstPlayerBoardColumns[y];
	uint32_t secondPlayerBitboard = _secondPlayerBoardColumns[y];

	if (x + 3 < BOARD_SIZE) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 1 > 0) ? x - 1 : x;
			xMax = (x + 4 < BOARD_SIZE) ? x + 4 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(y, xMin, player))
					possibleMoves.emplace(y, xMin);
				xMin++;
			} 
		}
	}
	
	if (x - 3 > 0) {
		int xMin = 0;
		int xMax = 0;
		uint32_t firstPlayerSelection = getSelection(firstPlayerBitboard, 4, x - 3);
		uint32_t secondPlayerSelection = getSelection(secondPlayerBitboard, 4, x - 3);

		if ((firstPlayerSelection == patterns[patternIndex] && secondPlayerSelection == 0b0000)
		|| (secondPlayerSelection == patterns[patternIndex] && firstPlayerSelection == 0b0000)) {
			xMin = (x - 4 > 0) ? x - 4 : 0;
			xMax = (x + 1 < BOARD_SIZE) ? x + 1 : BOARD_SIZE - 1;

			while (xMin < xMax) {
				if (isLegalMove(y, xMin, player))
					possibleMoves.emplace(y, xMin);
				xMin++;
			}
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_patterns.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:41:12 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/07 16:09:38 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int     Bitboard::checkPattern(uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
    int    nbPattern = 0;

    checkPatternHorizontal(nbPattern, pattern, opponentPattern, patternSize, player);
	checkPatternVertical(nbPattern, pattern, opponentPattern, patternSize, player);
	checkPatternDiagonal(nbPattern, pattern, opponentPattern, patternSize, player);
	checkPatternAntiDiagonal(nbPattern, pattern, opponentPattern, patternSize, player);

    return (nbPattern);
}

void    Bitboard::checkPatternHorizontal(int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (x + patternSize <= BOARD_SIZE) {
                uint32_t playerSelection = getSelection((player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y], patternSize, x);
                uint32_t opponentSelection = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], patternSize, x);

                if (playerSelection == pattern && opponentSelection == opponentPattern)
					nbPattern++;
            }
        }
    }
}

void    Bitboard::checkPatternVertical(int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (x + patternSize <= BOARD_SIZE) {
                uint32_t playerSelection = getSelection((player == 1) ? _firstPlayerBoardColumns[y] : _secondPlayerBoardColumns[y], patternSize, x);
                uint32_t opponentSelection = getSelection((player == 1) ? _secondPlayerBoardColumns[y] : _firstPlayerBoardColumns[y], patternSize, x);

                if (playerSelection == pattern && opponentSelection == opponentPattern)
					nbPattern++;
            }
        }
    }
}

void	Bitboard::checkPatternDiagonal(int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			int boardSide = (x < y + 1) ? 1 : 2;

			if ((boardSide == 1 && x + patternSize <= y + 1) || (boardSide == 2 && x + patternSize <= BOARD_SIZE)) {
				uint32_t playerSelection = getSelection((player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y], patternSize, x);
				uint32_t opponentSelection = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], patternSize, x);

				if (playerSelection == pattern && opponentSelection == opponentPattern)
					nbPattern++;
			}
		}
	}
}

void	Bitboard::checkPatternAntiDiagonal(int &nbPattern, uint32_t pattern, uint32_t opponentPattern, int patternSize, int player) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			int boardSide = (x < BOARD_SIZE - y) ? 1 : 2;
			
			if ((boardSide == 1 && x + patternSize <= BOARD_SIZE - y) || (boardSide == 2 && x + patternSize <= BOARD_SIZE - 1)) {
				uint32_t playerSelection = getSelection((player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y], patternSize, x);
				uint32_t opponentSelection = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y], patternSize, x);

				if (playerSelection == pattern && opponentSelection == opponentPattern)
					nbPattern++;
			}
		}
	}
}
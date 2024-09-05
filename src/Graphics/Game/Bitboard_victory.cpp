/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:39:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/09/05 13:33:10 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool    Bitboard::fiveInARow(int x, int y, int player) {
	if (fiveInARowHorizontal(x, y, player))
		return (true);
	if (fiveInARowVertical(x, y, player))
		return (true);
	if (fiveInARowDiagonal(x, y, player))
		return (true);
	if (fiveInARowAntiDiagonal(x, y, player))
		return (true);
	return (false);
}

bool	Bitboard::horizontalCaptureInAlignment(int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			bitPos = 0;
	int			nbBits = 0;
	
	if (x - 2 < 0)
		nbBits = 4;
	else if (x + 2 > BOARD_SIZE - 1) {
		nbBits = 4;
		bitPos = x - 2;
	} else {
		nbBits = 5;
		bitPos = x - 2;
	}
	
	pSelection = getSelection(pBitboard, nbBits, bitPos);
	oSelection = getSelection(oBitboard, nbBits, bitPos);
	
	for (int i = 0; i < 2; i++) {
		uint32_t pFour = getSelection(pSelection, 4, i);
		uint32_t oFour = getSelection(oSelection, 4, i);
		
		if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001))
			return true;
	}
	return false;
}

bool	Bitboard::verticalCaptureInAlignment(int x, int y, int player) {
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			bitPos = 0;
	int			nbBits = 0;
	
	if (y - 2 < 0)
		nbBits = 4;
	else if (y + 2 > BOARD_SIZE - 1) {
		nbBits = 4;
		bitPos = y - 2;
	} else {
		nbBits = 5;
		bitPos = y - 2;
	}
	
	pSelection = getSelection(pBitboard, nbBits, bitPos);
	oSelection = getSelection(oBitboard, nbBits, bitPos);
	
	for (int i = 0; i < 2; i++) {
		uint32_t pFour = getSelection(pSelection, 4, i);
		uint32_t oFour = getSelection(oSelection, 4, i);
		
		if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001))
			return true;
	}
	return false;
}

bool	Bitboard::diagonalCaptureInAlignment(int x, int y, int player) {
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			nbBits = 0;
	int			boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
	int			yDiagonal = rotateY45(x, y);
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardDiagonals[yDiagonal] : _secondPlayerBoardDiagonals[yDiagonal];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardDiagonals[yDiagonal] : _firstPlayerBoardDiagonals[yDiagonal];

	if (x != 0 && x != yDiagonal && boardSide == 1 && yDiagonal >= 4) {
		if (x - 2 < 0) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, 0);
			oSelection = getSelection(oBitboard, nbBits, 0);
		} else if (x + 2 > yDiagonal + 1) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		} else {
			nbBits = 5;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		}
	} else if (x != BOARD_SIZE - 1 && x != yDiagonal && boardSide == 2 && yDiagonal <= 14) {
		if (x - 2 < yDiagonal + 1) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, yDiagonal + 1);
			oSelection = getSelection(oBitboard, nbBits, yDiagonal + 1);
		} else if (x + 2 > BOARD_SIZE) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		} else {
			nbBits = 5;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		}
	}
	
	for (int i = 0; i < 2; i++) {
		uint32_t pFour = getSelection(pSelection, 4, i);
		uint32_t oFour = getSelection(oSelection, 4, i);
		
		if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001)) {
			return true;
		}
	}
	return false;
}

bool	Bitboard::antiDiagonalCaptureInAlignment(int x, int y, int player) {
	uint32_t	pSelection = 0;
	uint32_t	oSelection = 0;
	int			nbBits = 0;
	int			boardSide = (x < y + 1) ? 1 : 2;
	int			yAntiDiagonal = rotateY315(x, y);
	uint32_t	pBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[yAntiDiagonal] : _secondPlayerBoardAntiDiagonals[yAntiDiagonal];
	uint32_t	oBitboard = (player == 1) ? _secondPlayerBoardAntiDiagonals[yAntiDiagonal] : _firstPlayerBoardAntiDiagonals[yAntiDiagonal];

	if (x != 0 && x != yAntiDiagonal && boardSide == 1 && yAntiDiagonal <= 14) {
		if (x - 2 < 0) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, 0);
			oSelection = getSelection(oBitboard, nbBits, 0);
		} else if (x + 2 > BOARD_SIZE - yAntiDiagonal) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		} else {
			nbBits = 5;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		}
	} else if (x != BOARD_SIZE - 1 && x != yAntiDiagonal && boardSide == 2 && yAntiDiagonal >= 4) {
		if (x - 2 < BOARD_SIZE - yAntiDiagonal) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, BOARD_SIZE - yAntiDiagonal);
			oSelection = getSelection(oBitboard, nbBits, BOARD_SIZE - yAntiDiagonal);
		} else if (x + 2 > BOARD_SIZE - 1) {
			nbBits = 4;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		} else {
			nbBits = 5;
			pSelection = getSelection(pBitboard, nbBits, x - 2);
			oSelection = getSelection(oBitboard, nbBits, x - 2);
		}
	}

	for (int i = 0; i < 2; i++) {
		uint32_t pFour = getSelection(pSelection, 4, i);
		uint32_t oFour = getSelection(oSelection, 4, i);
		
		if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001)) {
			return true;
		}
	}
	return false;
}

bool	Bitboard::isHorizontalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	if (y == 0 || y == BOARD_SIZE - 1)
		return false;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			x++;
			continue;
		}
		if (verticalCaptureInAlignment(x, y, player) || diagonalCaptureInAlignment(x, y, player) || antiDiagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			x++;
			continue;
		}
		x++;
		nbValidStones++;
	}
	std::cout << "nb valid stones : " << nbValidStones << std::endl;
	if (nbValidStones >= 5)
		return false;
	return true;
}

bool	Bitboard::isVerticalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	if (x == 0 || x == BOARD_SIZE - 1)
		return false;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			y++;
			continue;
		}
		if (horizontalCaptureInAlignment(x, y, player) || diagonalCaptureInAlignment(x, y, player) || antiDiagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			y++;
			continue;
		}
		y++;
		nbValidStones++;
	}
	// std::cout << "nb valid stones : " << nbValidStones << std::endl;
	if (nbValidStones >= 5)
		return false;
	return true;
}

bool	Bitboard::isDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	if (x == 0 || x == BOARD_SIZE - 1)
		return false;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			y++;
			continue;
		}
		if (horizontalCaptureInAlignment(x, y, player) || verticalCaptureInAlignment(x, y, player) || antiDiagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			std::cout << "je suis la" << std::endl;
			y++;
			continue;
		}
		y++;
		nbValidStones++;
	}
	// std::cout << "nb valid stones : " << nbValidStones << std::endl;
	if (nbValidStones >= 5)
		return false;
	return true;
}

/* bool	Bitboard::isAntiDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	if (x == 0 || x == BOARD_SIZE - 1)
		return false;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			y++;
			continue;
		}
		if (horizontalCaptureInAlignment(x, y, player) || verticalCaptureInAlignment(x, y, player) || diagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			std::cout << "je suis la" << std::endl;
			y++;
			continue;
		}
		y++;
		nbValidStones++;
	}
	// std::cout << "nb valid stones : " << nbValidStones << std::endl;
	if (nbValidStones >= 5)
		return false;
	return true;
} */

/* 		std::cout << "pVerticalSelection : ";
		for (int i = 0; i < 5; i++) {
			uint32_t printMask = 1 << i;
			
			if (pVerticalSelection & printMask)
				std::cout << "1";
			else
				std::cout << "0";
		}
		std::cout << " | ";
		std::cout << "oVerticalSelection : ";
		for (int i = 0; i < 5; i++) {
			uint32_t printMask = 1 << i;
			
			if (oVerticalSelection & printMask)
				std::cout << "1";
			else
				std::cout << "0";
		}
		std::cout << std::endl; */

bool    Bitboard::fiveInARowHorizontal(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
    uint32_t    selection = 0;
	int			bitPos = 0;
	int			nbBits = 0;
	int			selectionStart = 0;

	if (x - 4 < 0) {
		nbBits = 5 + x;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = 0;
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 4);
		bitPos = x - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = x - 4;
	} else {
		nbBits = 9;
		bitPos = x - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = x - 4;
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 && !isHorizontalAlignmentBreakable(selectionStart, y, nbBits, player))
				return true;
		}
	}
    return false;
}

bool	Bitboard::fiveInARowVertical(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
    uint32_t    selection = 0;
	int			bitPos = 0;
	int			nbBits = 0;
	int			selectionStart = 0;

	if (y - 4 < 0) {
		nbBits = 5 + y;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = 0;
	} else if (y + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (y - 4);
		bitPos = y - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = y - 4;
	} else {
		nbBits = 9;
		bitPos = y - 4;
		selection = getSelection(bitboard, nbBits, bitPos);
		selectionStart = y - 4;
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 && !isVerticalAlignmentBreakable(x, selectionStart, nbBits, player))
				return true;
		}
	}
    return false;
}

bool	Bitboard::fiveInARowDiagonal(int x, int y, int player) {
	int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
	y = rotateY45(x, y);

	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
	uint32_t	selection = 0;
	int			nbBits = 0;
	
	if (boardSide == 1 && y >= 4) {
		if (x - 4 <= 0) {
			nbBits = (5 + x < y + 1) ? 5 + x : y + 1;
			selection = getSelection(bitboard, nbBits, 0);
		} else if (x + 4 >= y + 1 || x + 4 > BOARD_SIZE - 1) {
			nbBits = (y + 1) - (x - 4);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	} else if (boardSide == 2 && y < 14) {
		if (x - 4 < y + 1) {
			nbBits = x - (y + 1);
			if (x + 4 > BOARD_SIZE - 1)
				nbBits += BOARD_SIZE - x;
			else
				nbBits += 5;
			selection = getSelection(bitboard, nbBits, y + 1);
		} else if (x + 4 > BOARD_SIZE - 1) {
			nbBits = 5 + ((BOARD_SIZE - 1) - x);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	}

    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 /* && !isDiagonalAlignmentBreakable(x, selectionStart, nbBits, player) */) {
				return true;
			}
		}
	}
	return (false);
}

bool	Bitboard::fiveInARowAntiDiagonal(int x, int y, int player) {
	int	boardSide = (x < y + 1) ? 1 : 2;
	y = rotateY315(x, y);

	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
	uint32_t	selection = 0;
	int			nbBits = 0;
	
	if (boardSide == 1 && y <= 14) {
		if (x - 4 <= 0) {
			nbBits = (5 + x < BOARD_SIZE - y) ? 5 + x : BOARD_SIZE - y;
			selection = getSelection(bitboard, nbBits, 0);
		} else if (x + 4 >= BOARD_SIZE - y) {
			nbBits = (BOARD_SIZE - y) - (x - 4);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	} else if (boardSide == 2 && y > 4) {
		if (x - 4 < BOARD_SIZE - y) {
			nbBits = x - (BOARD_SIZE - y);
			if (x + 4 > BOARD_SIZE - 1)
				nbBits += BOARD_SIZE - x;
			else
				nbBits += 5;
			selection = getSelection(bitboard, nbBits, BOARD_SIZE - y);
		} else if (x + 4 > BOARD_SIZE - 1) {
			nbBits = 5 + ((BOARD_SIZE - 1) - x);
			selection = getSelection(bitboard, nbBits, x - 4);
		} else {
			nbBits = 9;
			selection = getSelection(bitboard, nbBits, x - 4);
		}
	}
		
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = getSelection(selection, 5, i);
			if (five == 0b11111 /* && !isAntiDiagonalAlignmentBreakable(x, selectionStart, nbBits, player) */)
				return true;
		}
	}
	return (false);
}
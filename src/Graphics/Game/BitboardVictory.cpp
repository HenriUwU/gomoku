/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_victory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:41 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/16 22:31:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Bitboard.hpp"

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

bool Bitboard::horizontalCaptureInAlignment(int x, int y, int player) {
    uint32_t pBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
    uint32_t oBitboard = (player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y];
    uint32_t pSelection = 0;
    uint32_t oSelection = 0;
    int bitPos = 0;
    int nbBits = 0;

    if (x - 2 < 0) {
        nbBits = 4;
        bitPos = 0; // Start from the leftmost bit
    } else if (x + 2 > BOARD_SIZE - 1) {
        nbBits = 4;
        bitPos = x - 2; // Adjust to start from x - 2
    } else {
        nbBits = 5;
        bitPos = x - 2; // Adjust to start from x - 2
    }

    // Extract the relevant bits
    pSelection = (pBitboard >> bitPos) & ((1 << nbBits) - 1);
    oSelection = (oBitboard >> bitPos) & ((1 << nbBits) - 1);

    // Now check for the patterns directly
    for (int i = 0; i <= nbBits - 4; i++) {
        uint32_t pFour = (pSelection >> i) & 0b1111; // Extract 4 bits
        uint32_t oFour = (oSelection >> i) & 0b1111; // Extract 4 bits

        if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001)) {
            return true;
        }
    }
    return false;
}


bool Bitboard::verticalCaptureInAlignment(int x, int y, int player) {
    uint32_t pBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
    uint32_t oBitboard = (player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x];
    uint32_t pSelection = 0;
    uint32_t oSelection = 0;
    int bitPos = 0;
    int nbBits = 0;

    if (y - 2 < 0) {
        nbBits = 4;
        bitPos = 0; // Start from the topmost bit
    } else if (y + 2 > BOARD_SIZE - 1) {
        nbBits = 4;
        bitPos = y - 2; // Adjust to start from y - 2
    } else {
        nbBits = 5;
        bitPos = y - 2; // Adjust to start from y - 2
    }

    // Extract the relevant bits
    pSelection = (pBitboard >> bitPos) & ((1 << nbBits) - 1);
    oSelection = (oBitboard >> bitPos) & ((1 << nbBits) - 1);

    // Now check for the patterns directly
    for (int i = 0; i <= nbBits - 4; i++) {
        uint32_t pFour = (pSelection >> i) & 0b1111; // Extract 4 bits
        uint32_t oFour = (oSelection >> i) & 0b1111; // Extract 4 bits

        if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001)) {
            return true;
        } 
    }
    return false;
}


bool Bitboard::diagonalCaptureInAlignment(int x, int y, int player) {
    uint32_t pSelection = 0;
    uint32_t oSelection = 0;
    int nbBits = 0;
    int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
    int yDiagonal = rotateY45(x, y);
    uint32_t pBitboard = (player == 1) ? _firstPlayerBoardDiagonals[yDiagonal] : _secondPlayerBoardDiagonals[yDiagonal];
    uint32_t oBitboard = (player == 1) ? _secondPlayerBoardDiagonals[yDiagonal] : _firstPlayerBoardDiagonals[yDiagonal];

    if (x != 0 && x != yDiagonal && boardSide == 1 && yDiagonal >= 4) {
        if (x - 2 < 0) {
            nbBits = 4;
            pSelection = (pBitboard >> 0) & 0b1111; // Extract 4 bits starting from the left
            oSelection = (oBitboard >> 0) & 0b1111;
        } else if (x + 2 > yDiagonal + 1) {
            nbBits = 4;
            pSelection = (pBitboard >> (x - 2)) & 0b1111;
            oSelection = (oBitboard >> (x - 2)) & 0b1111;
        } else {
            nbBits = 5;
            pSelection = (pBitboard >> (x - 2)) & 0b11111; // Extract 5 bits
            oSelection = (oBitboard >> (x - 2)) & 0b11111;
        }
    } else if (x != BOARD_SIZE - 1 && x != yDiagonal && boardSide == 2 && yDiagonal <= 14) {
        if (x - 2 < yDiagonal + 1) {
            nbBits = 4;
            pSelection = (pBitboard >> (yDiagonal + 1)) & 0b1111;
            oSelection = (oBitboard >> (yDiagonal + 1)) & 0b1111;
        } else if (x + 2 > BOARD_SIZE) {
            nbBits = 4;
            pSelection = (pBitboard >> (x - 2)) & 0b1111;
            oSelection = (oBitboard >> (x - 2)) & 0b1111;
        } else {
            nbBits = 5;
            pSelection = (pBitboard >> (x - 2)) & 0b11111;
            oSelection = (oBitboard >> (x - 2)) & 0b11111;
        }
    }

    // Now check for the patterns directly
    for (int i = 0; i <= nbBits - 4; i++) {
        uint32_t pFour = (pSelection >> i) & 0b1111; // Extract 4 bits
        uint32_t oFour = (oSelection >> i) & 0b1111; // Extract 4 bits

        if (pFour == 0b0110 && (oFour == 0b1000 || oFour == 0b0001)) {
            return true;
        }
    }
    return false;
}

bool Bitboard::antiDiagonalCaptureInAlignment(int x, int y, int player) {
    uint32_t pSelection = 0;
    uint32_t oSelection = 0;
    int nbBits = 0;
    int boardSide = (x < y + 1) ? 1 : 2;
    int yAntiDiagonal = rotateY315(x, y);
    uint32_t pBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[yAntiDiagonal] : _secondPlayerBoardAntiDiagonals[yAntiDiagonal];
    uint32_t oBitboard = (player == 1) ? _secondPlayerBoardAntiDiagonals[yAntiDiagonal] : _firstPlayerBoardAntiDiagonals[yAntiDiagonal];

    if (x != 0 && x != yAntiDiagonal && boardSide == 1 && yAntiDiagonal <= 14) {
        if (x - 2 < 0) {
            nbBits = 4;
            pSelection = (pBitboard >> 0) & 0b1111; // Extract 4 bits starting from the left
            oSelection = (oBitboard >> 0) & 0b1111;
        } else if (x + 2 > BOARD_SIZE - yAntiDiagonal) {
            nbBits = 4;
            pSelection = (pBitboard >> (x - 2)) & 0b1111;
            oSelection = (oBitboard >> (x - 2)) & 0b1111;
        } else {
            nbBits = 5;
            pSelection = (pBitboard >> (x - 2)) & 0b11111; // Extract 5 bits
            oSelection = (oBitboard >> (x - 2)) & 0b11111;
        }
    } else if (x != BOARD_SIZE - 1 && x != yAntiDiagonal && boardSide == 2 && yAntiDiagonal >= 4) {
        if (x - 2 < BOARD_SIZE - yAntiDiagonal) {
            nbBits = 4;
            pSelection = (pBitboard >> (BOARD_SIZE - yAntiDiagonal)) & 0b1111;
            oSelection = (oBitboard >> (BOARD_SIZE - yAntiDiagonal)) & 0b1111;
        } else if (x + 2 > BOARD_SIZE - 1) {
            nbBits = 4;
            pSelection = (pBitboard >> (x - 2)) & 0b1111;
            oSelection = (oBitboard >> (x - 2)) & 0b1111;
        } else {
            nbBits = 5;
            pSelection = (pBitboard >> (x - 2)) & 0b11111;
            oSelection = (oBitboard >> (x - 2)) & 0b11111;
        }
    }

    // Check for the patterns directly
    for (int i = 0; i <= nbBits - 4; i++) {
        uint32_t pFour = (pSelection >> i) & 0b1111; // Extract 4 bits
        uint32_t oFour = (oSelection >> i) & 0b1111; // Extract 4 bits

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
	if (nbValidStones >= 5)
		return false;
	return true;
}

bool	Bitboard::isDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			x++;
			y--;
			continue;
		}
		if (horizontalCaptureInAlignment(x, y, player) || verticalCaptureInAlignment(x, y, player) || antiDiagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			x++;
			y--;
			continue;
		}
		x++;
		y--;
		nbValidStones++;
	}
	if (nbValidStones >= 5)
		return false;
	return true;
}

bool	Bitboard::isAntiDiagonalAlignmentBreakable(int x, int y, int bitsInAlignment, int player) {
	int nbValidStones = 0;

	for (int i = 0; i < bitsInAlignment; i++) {
		if (!getBit(x, y)) {
			x++;
			y++;
			continue;
		}
		if (horizontalCaptureInAlignment(x, y, player) || verticalCaptureInAlignment(x, y, player) || diagonalCaptureInAlignment(x, y, player)) {
			nbValidStones = 0;
			x++;
			y++;
			continue;
		}
		x++;
		y++;
		nbValidStones++;
	}
	if (nbValidStones >= 5)
		return false;
	return true;
}

bool    Bitboard::fiveInARowHorizontal(int x, int y, int player) {
	uint32_t	bitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
    uint32_t    selection = 0;
	int			bitPos = 0;
	int			nbBits = 0;
	int			selectionStart = 0;

	if (x - 4 < 0) {
		nbBits = 5 + x;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = 0;
	} else if (x + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (x - 4);
		bitPos = x - 4;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = x - 4;
	} else {
		nbBits = 9;
		bitPos = x - 4;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = x - 4;
	}
    
    for (int i = 0; i < nbBits; i++) {
		if (i + 5 <= nbBits) {
			uint32_t five = (selection >> i) & 0b11111;
			if (five == 0b11111 && !isHorizontalAlignmentBreakable(selectionStart, y, nbBits, player))
				return true;
		}
	}
    return false;
}

bool Bitboard::fiveInARowVertical(int x, int y, int player) {
	uint32_t bitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t selection = 0;
	int bitPos = 0;
	int nbBits = 0;
	int selectionStart = 0;

	if (y - 4 < 0) {
		nbBits = 5 + y;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = 0;
	} else if (y + 4 > BOARD_SIZE - 1) {
		nbBits = BOARD_SIZE - (y - 4);
		bitPos = y - 4;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = y - 4;
	} else {
		nbBits = 9;
		bitPos = y - 4;
		selection = (bitboard >> bitPos) & ((1 << nbBits) - 1);
		selectionStart = y - 4;
	}

	for (int i = 0; i <= nbBits - 5; i++) {
		uint32_t five = (selection >> i) & 0b11111; // Extract 5 bits

		if (five == 0b11111 && !isVerticalAlignmentBreakable(x, selectionStart, nbBits, player)) {
			return true;
		}
	}
	return false;
}

bool Bitboard::fiveInARowDiagonal(int x, int y, int player) {
    int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
    int originalY = y;
    int selectionStart = 0;
    y = rotateY45(x, y);

    uint32_t bitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
    uint32_t selection = 0;
    int nbBits = 0;

    if (boardSide == 1 && y >= 4) {
        if (x - 4 <= 0) {
            nbBits = (5 + x < y + 1) ? 5 + x : y + 1;
            selection = (bitboard >> 0) & ((1 << nbBits) - 1);
            selectionStart = 0;
        } else if (x + 4 >= y + 1 || x + 4 > BOARD_SIZE - 1) {
            nbBits = (y + 1) - (x - 4);
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        } else {
            nbBits = 9;
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        }
    } else if (boardSide == 2 && y < 14) {
        if (x - 4 < y + 1) {
            nbBits = x - (y + 1);
            if (x + 4 > BOARD_SIZE - 1)
                nbBits += BOARD_SIZE - x;
            else
                nbBits += 5;
            selection = (bitboard >> (y + 1)) & ((1 << nbBits) - 1);
            selectionStart = y + 1;
        } else if (x + 4 > BOARD_SIZE - 1) {
            nbBits = 5 + ((BOARD_SIZE - 1) - x);
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        } else {
            nbBits = 9;
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        }
    }

    for (int i = 0; i <= nbBits - 5; i++) {
        uint32_t five = (selection >> i) & 0b11111; // Extract 5 bits

        if (five == 0b11111 && !isDiagonalAlignmentBreakable(selectionStart, (x < 4) ? originalY + x : originalY + 4, nbBits, player)) {
            return true;
        }
    }
    return false;
}

bool Bitboard::fiveInARowAntiDiagonal(int x, int y, int player) {
    int boardSide = (x < y + 1) ? 1 : 2;
    int originalY = y;
    int selectionStart = 0;
    y = rotateY315(x, y);

    uint32_t bitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
    uint32_t selection = 0;
    int nbBits = 0;

    if (boardSide == 1 && y <= 14) {
        if (x - 4 <= 0) {
            nbBits = (5 + x < BOARD_SIZE - y) ? 5 + x : BOARD_SIZE - y;
            selection = (bitboard >> 0) & ((1 << nbBits) - 1);
            selectionStart = 0;
        } else if (x + 4 >= BOARD_SIZE - y) {
            nbBits = (BOARD_SIZE - y) - (x - 4);
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        } else {
            nbBits = 9;
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        }
    } else if (boardSide == 2 && y > 4) {
        if (x - 4 < BOARD_SIZE - y) {
            nbBits = x - (BOARD_SIZE - y);
            if (x + 4 > BOARD_SIZE - 1)
                nbBits += BOARD_SIZE - x;
            else
                nbBits += 5;
            selection = (bitboard >> (BOARD_SIZE - y)) & ((1 << nbBits) - 1);
            selectionStart = BOARD_SIZE - y;
        } else if (x + 4 > BOARD_SIZE - 1) {
            nbBits = 5 + ((BOARD_SIZE - 1) - x);
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        } else {
            nbBits = 9;
            selection = (bitboard >> (x - 4)) & ((1 << nbBits) - 1);
            selectionStart = x - 4;
        }
    }

    for (int i = 0; i <= nbBits - 5; i++) {
        uint32_t five = (selection >> i) & 0b11111; // Extract 5 bits

        if (five == 0b11111 && !isAntiDiagonalAlignmentBreakable(selectionStart, (x < 4) ? originalY - x : originalY - 4, nbBits, player)) {
            return true;
        }
    }
    return false;
}

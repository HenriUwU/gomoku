/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_captures.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:47:40 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/10 13:30:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

int	Bitboard::makeCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones) {
	int captures = 0;
	
	captures += makeHorizontalCapture(x, y, player, removedStones);
	captures += makeVerticalCapture(x, y, player, removedStones);
	captures += makeDiagonalCapture(x, y, player, removedStones);
	captures += makeAntiDiagonalCapture(x, y, player, removedStones);
	
	return captures;
}

void	Bitboard::verifyHorizontalCapture(int &nbCaptures, int x, int y, int player) {
	uint32_t	linesBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	uint32_t	linesMask = uint32_t(1) << x;
	
	linesBitboard |= linesMask;

	if (x <= 15) {
		uint32_t rightSelection = getSelection(linesBitboard, 4, x);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (x >= 3) {
		uint32_t leftSelection = getSelection(linesBitboard, 4, x - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
}

void	Bitboard::verifyVerticalCapture(int &nbCaptures, int x, int y, int player) {
	uint32_t	columnsBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	uint32_t	columnsMask = uint32_t(1) << y;
	
	columnsBitboard |= columnsMask;
	if (y <= 15) {
		uint32_t rightSelection = getSelection(columnsBitboard, 4, y);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
	if (y >= 3) {
		uint32_t leftSelection = getSelection(columnsBitboard, 4, y - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y - 3);
			if (isPair == PAIR)
				nbCaptures++;
		}
	}
}

void	Bitboard::verifyDiagonalCapture(int &nbCaptures, int x, int y, int player) {
	int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;

	y = rotateY45(x, y);

	uint32_t	diagonalsBitboard = (player == 1) ? _firstPlayerBoardDiagonals[y] : _secondPlayerBoardDiagonals[y];
	uint32_t	diagonalsMask = uint32_t(1) << x;

	diagonalsBitboard |= diagonalsMask;

	if (boardSide == 1 && y >= 3) {
		if (x + 3 <= y + 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x - 3 >= 0) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
	else if (boardSide == 2 && y <= 15) {
		if (x + 3 <= BOARD_SIZE - 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x - 3 >= y + 1) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[y] : _firstPlayerBoardDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
}

void	Bitboard::verifyAntiDiagonalCapture(int &nbCaptures, int x, int y, int player) {
	int boardSide = (x < y + 1) ? 1 : 2;

	y = rotateY315(x, y);

	uint32_t	antiDiagonalsBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[y] : _secondPlayerBoardAntiDiagonals[y];
	uint32_t	antiDiagonalsMask = uint32_t(1) << x;

	antiDiagonalsBitboard |= antiDiagonalsMask;
	
	if (boardSide == 1 && y <= 15) {
		if (x + 3 < BOARD_SIZE - y) {
			uint32_t rightSelection = getSelection(antiDiagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x - 3 >= 0) {
			uint32_t leftSelection = getSelection(antiDiagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
	else if (boardSide == 2 && y >= 3) {
		if (x + 3 <= BOARD_SIZE - 1) {
			uint32_t rightSelection = getSelection(antiDiagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y], 4, x);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
		if (x - 3 >= BOARD_SIZE - y) {
			uint32_t leftSelection = getSelection(antiDiagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[y] : _firstPlayerBoardAntiDiagonals[y], 4, x - 3);
				if (isPair == PAIR)
					nbCaptures++;
			}
		}
	}
}

int	Bitboard::makeHorizontalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones) {
	uint32_t	linesBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
	int			captures = 0;

	if (x <= 15) {
		uint32_t rightSelection = getSelection(linesBitboard, 4, x);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x);
			if (isPair == PAIR) {			
				removeStone(x + 1, y, (player == 1) ? 2 : 1);
				removeStone(x + 2, y, (player == 1) ? 2 : 1);
				removedStones.push_back(std::make_pair(x + 1, y));
				removedStones.push_back(std::make_pair(x + 2, y));
				captures++;
			}
		}
	}
	if (x >= 3) {
		linesBitboard = (player == 1) ? _firstPlayerBoardLines[y] : _secondPlayerBoardLines[y];
		uint32_t leftSelection = getSelection(linesBitboard, 4, x - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardLines[y] : _firstPlayerBoardLines[y], 4, x - 3);
			if (isPair == PAIR) {
				removeStone(x - 1, y, (player == 1) ? 2 : 1);
				removeStone(x - 2, y, (player == 1) ? 2 : 1);
				removedStones.push_back(std::make_pair(x - 1, y));
				removedStones.push_back(std::make_pair(x - 2, y));
				captures++;
			}
		}
	}
	return captures;
}

int	Bitboard::makeVerticalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones) {
	uint32_t	columnsBitboard = (player == 1) ? _firstPlayerBoardColumns[x] : _secondPlayerBoardColumns[x];
	int			captures = 0;
	
	if (y <= 15) {
		uint32_t rightSelection = getSelection(columnsBitboard, 4, y);
		if (rightSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y);
			if (isPair == PAIR) {
				removeStone(x, y + 1, (player == 1) ? 2 : 1);
				removeStone(x, y + 2, (player == 1) ? 2 : 1);
				removedStones.push_back(std::make_pair(x, y + 1));
				removedStones.push_back(std::make_pair(x, y + 2));
				captures++;
			}
		}
	}
	if (y >= 3) {
		uint32_t leftSelection = getSelection(columnsBitboard, 4, y - 3);
		if (leftSelection == CAPTURE) {
			uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardColumns[x] : _firstPlayerBoardColumns[x], 4, y - 3);
			if (isPair == PAIR) {
				removeStone(x, y - 1, (player == 1) ? 2 : 1);
				removeStone(x, y - 2, (player == 1) ? 2 : 1);
				removedStones.push_back(std::make_pair(x, y - 1));
				removedStones.push_back(std::make_pair(x, y - 2));
				captures++;
			}
		}
	}
	return captures;
}

int	Bitboard::makeDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones) {
	int boardSide = (x + y < BOARD_SIZE) ? 1 : 2;
	int	captures = 0;
	
	int yCopy = rotateY45(x, y);
	uint32_t	diagonalsBitboard = (player == 1) ? _firstPlayerBoardDiagonals[yCopy] : _secondPlayerBoardDiagonals[yCopy];
	
	if (boardSide == 1 && yCopy >= 3) {
		if (x + 3 <= yCopy + 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[yCopy] : _firstPlayerBoardDiagonals[yCopy], 4, x);
				if (isPair == PAIR) {
					removeStone(x + 1, y - 1, (player == 1) ? 2 : 1);
					removeStone(x + 2, y - 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x + 1, y - 1));
					removedStones.push_back(std::make_pair(x + 2, y - 2));
					captures++;
				}
			}
		}
		if (x - 3 >= 0) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[yCopy] : _firstPlayerBoardDiagonals[yCopy], 4, x - 3);
				if (isPair == PAIR) {
					removeStone(x - 1, y + 1, (player == 1) ? 2 : 1);
					removeStone(x - 2, y + 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x - 1, y + 1));
					removedStones.push_back(std::make_pair(x - 2, y + 2));
					captures++;
				}
			}
		}
	} else if (boardSide == 2 && yCopy <= 15) {
		if (x + 3 <= BOARD_SIZE - 1) {
			uint32_t rightSelection = getSelection(diagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[yCopy] : _firstPlayerBoardDiagonals[yCopy], 4, x);
				if (isPair == PAIR) {
					removeStone(x + 1, y - 1, (player == 1) ? 2 : 1);
					removeStone(x + 2, y - 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x + 1, y - 1));
					removedStones.push_back(std::make_pair(x + 2, y - 2));
					captures++;
				}
			}
		}
		if (x - 3 >= yCopy + 1) {
			uint32_t leftSelection = getSelection(diagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardDiagonals[yCopy] : _firstPlayerBoardDiagonals[yCopy], 4, x - 3);
				if (isPair == PAIR) {
					removeStone(x - 1, y + 1, (player == 1) ? 2 : 1);
					removeStone(x - 2, y + 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x - 1, y + 1));
					removedStones.push_back(std::make_pair(x - 2, y + 2));
					captures++;
				}
			}
		}
	}
	return captures;
}

int	Bitboard::makeAntiDiagonalCapture(int x, int y, int player, std::vector<std::pair<int, int>>& removedStones) {
	int boardSide = (x < y + 1) ? 1 : 2;
	int	captures = 0;

	int yCopy = rotateY315(x, y);
	uint32_t	antiDiagonalsBitboard = (player == 1) ? _firstPlayerBoardAntiDiagonals[yCopy] : _secondPlayerBoardAntiDiagonals[yCopy];
	
	if (boardSide == 1 && yCopy <= 15) {
		if (x + 3 < BOARD_SIZE - yCopy) {
			uint32_t rightSelection = getSelection(antiDiagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[yCopy] : _firstPlayerBoardAntiDiagonals[yCopy], 4, x);
				if (isPair == PAIR) {
					removeStone(x + 1, y + 1, (player == 1) ? 2 : 1);
					removeStone(x + 2, y + 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x + 1, y + 1));
					removedStones.push_back(std::make_pair(x + 2, y + 2));
					captures++;
				}
			}
		}
		if (x - 3 >= 0) {
			uint32_t leftSelection = getSelection(antiDiagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[yCopy] : _firstPlayerBoardAntiDiagonals[yCopy], 4, x - 3);
				if (isPair == PAIR)  {
					removeStone(x - 1, y - 1, (player == 1) ? 2 : 1);
					removeStone(x - 2, y - 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x - 1, y - 1));
					removedStones.push_back(std::make_pair(x - 2, y - 2));
					captures++;
				}
			}
		}
	} else if (boardSide == 2 && yCopy >= 3) {
		if (x + 3 <= BOARD_SIZE - 1) {
			uint32_t rightSelection = getSelection(antiDiagonalsBitboard, 4, x);
			if (rightSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[yCopy] : _firstPlayerBoardAntiDiagonals[yCopy], 4, x);
				if (isPair == PAIR) {
					removeStone(x + 1, y + 1, (player == 1) ? 2 : 1);
					removeStone(x + 2, y + 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x + 1, y + 1));
					removedStones.push_back(std::make_pair(x + 2, y + 2));
					captures++;
				}
			}
		}
		if (x - 3 >= BOARD_SIZE - yCopy) {
			uint32_t leftSelection = getSelection(antiDiagonalsBitboard, 4, x - 3);
			if (leftSelection == CAPTURE) {
				uint32_t isPair = getSelection((player == 1) ? _secondPlayerBoardAntiDiagonals[yCopy] : _firstPlayerBoardAntiDiagonals[yCopy], 4, x - 3);
				if (isPair == PAIR) {
					removeStone(x - 1, y - 1, (player == 1) ? 2 : 1);
					removeStone(x - 2, y - 2, (player == 1) ? 2 : 1);
					removedStones.push_back(std::make_pair(x - 1, y - 1));
					removedStones.push_back(std::make_pair(x - 2, y - 2));
					captures++;
				}
			}
		}
	}
	return captures;
}

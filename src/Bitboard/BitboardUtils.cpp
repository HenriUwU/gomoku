/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:57:17 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 15:11:45 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

std::unordered_set<std::pair<int, int>, pair_hash>	Bitboard::generatePossibleMoves(int player) {
	std::unordered_set<std::pair<int, int>, pair_hash>		uniqueMoves;
	std::unordered_set<std::pair<int, int>, pair_hash>		currentStones = getAllStones();
	int														margin = 2;

	for (auto& stone : currentStones) {
		int startX = std::max(0, stone.first - margin);
		int endX = std::min(BOARD_SIZE - 1, stone.first + margin);
		int startY = std::max(0, stone.second - margin);
		int endY = std::min(BOARD_SIZE - 1, stone.second + margin);

		for (int x = startX; x <= endX; ++x) {
			for (int y = startY; y <= endY; ++y) {
				if (!getBit(x, y)) {
					if (isLegalMoveForAI(x, y, player))
						uniqueMoves.emplace(x, y);
				}
			}
		}
	}
	return (uniqueMoves);
}

int Bitboard::hash() const {
	std::size_t	res;
	std::size_t	plTmp;
	std::size_t	opTmp;

	res = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		plTmp = std::hash<int>{}(this->_firstHash[i]);
		opTmp = std::hash<int>{}(this->_secondHash[i]);
		res = plTmp + 0x9e3779b9 + (res<<6) + (res>>2);
		res = opTmp + 0x9e3779b9 + (res<<6) + (res>>2);
	}

	return (res);
}

uint32_t	Bitboard::getSelection(uint32_t bitboard, int nbBits, int bitsPos) {
	bitboard >>= bitsPos;

	uint32_t mask = (1 << nbBits) - 1;
	uint32_t selection = bitboard & mask;

	return (selection);
}

int	Bitboard::getBit(int x, int y) const {
	uint32_t	mask;

	mask = uint32_t(1) << x;
	if (_firstPlayerBoardLines[y] & mask)
		return (1);
	else if (_secondPlayerBoardLines[y] & mask)
		return (2);
		
	return (0);
}

int Bitboard::reverseRotate45(int x, int y) {
	if (x + y < BOARD_SIZE)
		return (y - x);
	else
		return (y + (BOARD_SIZE - x));
}

int Bitboard::reverseRotate315(int x, int y) {
	if (x < y + 1)
		return (y + x);
	else
		return (y - (BOARD_SIZE + x));
}

int	Bitboard::rotateY45(int x, int y) {
	if (x + y < BOARD_SIZE)
		return (x + y);
	else
		return (y - (BOARD_SIZE - x));
}

int	Bitboard::rotateY315(int x, int y) {
	if (x < y + 1)
		return (y - x);
	else
		return (y + (BOARD_SIZE - x));
}

void Bitboard::update(int x, int y, int player, bool add) {
	uint32_t mask = uint32_t(1) << x;

	if (player == 1) {
		if (add) {
			_firstPlayerBoardLines[y] |= mask;
		} else {
			_firstPlayerBoardLines[y] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardLines[y] |= mask;
		} else {
			_secondPlayerBoardLines[y] &= ~mask;
		}
	}

	uint32_t columnMask = uint32_t(1) << y;
	if (player == 1) {
		if (add) {
			_firstPlayerBoardColumns[x] |= columnMask;
		} else {
			_firstPlayerBoardColumns[x] &= ~columnMask;
		}
	} else {
		if (add) {
			_secondPlayerBoardColumns[x] |= columnMask;
		} else {
			_secondPlayerBoardColumns[x] &= ~columnMask;
		}
	}

	int diagIndex = rotateY45(x, y);
	if (player == 1) {
		if (add) {
			_firstPlayerBoardDiagonals[diagIndex] |= mask;
		} else {
			_firstPlayerBoardDiagonals[diagIndex] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardDiagonals[diagIndex] |= mask;
		} else {
			_secondPlayerBoardDiagonals[diagIndex] &= ~mask;
		}
	}

	int antiDiagIndex = rotateY315(x, y);
	if (player == 1) {
		if (add) {
			_firstPlayerBoardAntiDiagonals[antiDiagIndex] |= mask;
		} else {
			_firstPlayerBoardAntiDiagonals[antiDiagIndex] &= ~mask;
		}
	} else {
		if (add) {
			_secondPlayerBoardAntiDiagonals[antiDiagIndex] |= mask;
		} else {
			_secondPlayerBoardAntiDiagonals[antiDiagIndex] &= ~mask;
		}
	}
	
	if (player == 1)
		this->_firstHash[y] = std::hash<int>{}(this->_firstPlayerBoardLines[y]);
	else
		this->_secondHash[y] = std::hash<int>{}(this->_secondPlayerBoardLines[y]);
}

void	Bitboard::printBoard() {
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoardLines[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoardLines[y] & mask) {
				std::cout << "2 ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}

void	Bitboard::printBoardWithPossibleMoves(std::vector<std::pair<int, int>> sortedMoves) {
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			uint32_t mask = uint32_t(1) << x;

			if (_firstPlayerBoardLines[y] & mask) {
				std::cout << "1 ";
			} else if (_secondPlayerBoardLines[y] & mask) {
				std::cout << "2 ";
			} else if (std::find(sortedMoves.begin(), sortedMoves.end(), std::make_pair(x, y)) != sortedMoves.end()) {
				std::cout << "X ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << "\n";
	}
}

void	Bitboard::clear() {
	_firstPlayerBoardLines.fill(0);
	_secondPlayerBoardLines.fill(0);
	_firstPlayerBoardColumns.fill(0);
	_secondPlayerBoardColumns.fill(0);
	_firstPlayerBoardDiagonals.fill(0);
	_secondPlayerBoardDiagonals.fill(0);
	_firstPlayerBoardAntiDiagonals.fill(0);
	_secondPlayerBoardAntiDiagonals.fill(0);
}
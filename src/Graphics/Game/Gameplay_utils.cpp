/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:54:34 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/11 14:13:24 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

void	Gameplay::findHorizontalLine(int nbStones, string position, vector<pair<string, int>> &horizontalLine) {
	for (int i = 1; i <= nbStones; i++) {
		stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << position.substr(1);
		ssMinus << char(position[0] - i) << position.substr(1);
		string newPosPlus = ssPlus.str();
		string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			horizontalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			horizontalLine.insert(horizontalLine.begin(), pair);
		}
	}
}

void	Gameplay::findVerticalLine(int nbStones, string position, vector<pair<string, int>> &verticalLine) {
	for (int i = 1; i <= nbStones; i++) {
		stringstream ssPlus, ssMinus;

		ssPlus << position[0] << to_string(stoi(position.substr(1)) + i);
		ssMinus << position[0] << to_string(stoi(position.substr(1)) - i);
		string newPosPlus = ssPlus.str();
		string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			verticalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			verticalLine.insert(verticalLine.begin(), pair);
		}
	}
}

void	Gameplay::findDiagonalLine(int nbStones, string position, vector<pair<string, int>> &diagonalLine) {
	for (int i = 1; i <= nbStones; i++) {
		stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << to_string(stoi(position.substr(1)) + i);
		ssMinus << char(position[0] - i) << to_string(stoi(position.substr(1)) - i);
		string newPosPlus = ssPlus.str();
		string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			diagonalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			diagonalLine.insert(diagonalLine.begin(), pair);
		}
	}
}

void	Gameplay::findAntiDiagonalLine(int nbStones, string position, vector<pair<string, int>> &antiDiagonalLine) {
	for (int i = 1; i <= nbStones; i++) {
		stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << to_string(stoi(position.substr(1)) - i);
		ssMinus << char(position[0] - i) << to_string(stoi(position.substr(1)) + i);
		string newPosPlus = ssPlus.str();
		string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			antiDiagonalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			pair<string, int> pair = make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			antiDiagonalLine.insert(antiDiagonalLine.begin(), pair);
		}
	}
}

bool	Gameplay::isAlignmentBreakable(vector<pair<string, int>> &line, int alignmentIndex) {
	int 	opponent = (_currentPlayer == 1) ? 2 : 1;
	
	for (unsigned int i = 0; i < line.size(); i++) {
		vector<pair<string, int>>	nearbyLines[4];
		
		for (int i = 0; i < 4; i++) {
			pair<string, int> pair = make_pair(line[i].first, line[i].second);
			nearbyLines[i].push_back(pair);
		}

		findHorizontalLine(2, line[i].first, nearbyLines[0]);
		findVerticalLine(2, line[i].first, nearbyLines[1]);
		findDiagonalLine(2, line[i].first, nearbyLines[2]);
		findAntiDiagonalLine(2, line[i].first, nearbyLines[3]);

		for (int j = 0; j < 4; j++) {
			if (j != alignmentIndex) {
				for (unsigned int k = 0; k < nearbyLines[j].size(); k++) {
					if (k < nearbyLines[j].size() - 3 && nearbyLines[j][k].second == 0) {
						if (nearbyLines[j][k + 1].second == _currentPlayer
						&& nearbyLines[j][k + 2].second == _currentPlayer
						&& nearbyLines[j][k + 3].second == opponent)
							return true;
					}
					if (k < nearbyLines[j].size() - 3 && nearbyLines[j][k].second == opponent) {
						if (nearbyLines[j][k + 1].second == _currentPlayer
						&& nearbyLines[j][k + 2].second == _currentPlayer
						&& nearbyLines[j][k + 3].second == 0)
							return true;
					} 
				}
			}
		}
	}
	return false;
}
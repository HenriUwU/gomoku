/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/11 11:12:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Gameplay::Gameplay(sf::RenderWindow& window) : Graphics(window) {
	for (int i = 0; i < 19; i++) {
		int character = 'A' + i;
		for (int j = 1; j < 20; j++) {
			std::string position = std::string(1, character) + std::to_string(j);
			_playerPositions.insert(std::pair<std::string, int>(position, 0));
		}
	}

	_currentPlayer = 1;
}

Gameplay::~Gameplay() {}

void Gameplay::circleFollowMouse(sf::RenderWindow& window, sf::Event& event) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	float xIndex = std::round((mousePosition.x - _gridStartPoint.first) / _cellSize);
	float yIndex = std::round((mousePosition.y - _gridStartPoint.second) / _cellSize);

	window.clear();
	Goban goban(window);
	goban.display(window);
	Debug::init(window);
	
	// Draw the circle following the mouse if the mouse is on the grid
	if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
		sf::Vector2f nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
		sf::CircleShape circle(13.f);

		sf::Color circleOutlineColor(182, 143, 64);
		sf::Color firstPlayerColor(138, 203, 136);
		sf::Color secondPlayerColor(254, 74, 73);

		circle.setOutlineColor(circleOutlineColor);
		circle.setOutlineThickness(2);
		
		if (_currentPlayer == 1) {
			circle.setFillColor(firstPlayerColor);
		}
		else {
			circle.setFillColor(secondPlayerColor);
		}
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}
	Debug::currentPlayer(window, _currentPlayer);
	char xCoord = 'A' + static_cast<int>(xIndex);
	int yCoord = 19 - static_cast<int>(yIndex);
	std::string position = std::string(1, xCoord) + std::to_string(yCoord);
	Debug::currentPos(window, position);

	// Place the stone on the grid if left mouse button is pressed
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
			// Place the stone for the current player
			placeStone(position, window);
		}
	}
	// checkStatus(_currentPlayer);
	if (displayGame) {
		goban.drawPlayerPositions(window, _playerPositions);
	}
	window.display();
}

void	Gameplay::placeStone(std::string position, sf::RenderWindow& window) {
	if (_playerPositions[position] != 0)
		return;
	if (!isMoveLegal(position))
		return;

	_playerPositions[position] = _currentPlayer;

	if (isWinningMove(position)) {
		Goban goban(window);
		displayGame = false;
		goban.scoreTable(_currentPlayer, window);
	}

	if (_currentPlayer == 1)
		_currentPlayer = 2;
	else
		_currentPlayer = 1;
}

bool	Gameplay::isMoveLegal(std::string position) {
	std::vector<std::pair<std::string, int>>	nearbyLines[4];

	for (int i = 0; i < 4; i++) {
		std::pair<std::string, int> pair = std::make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}
	findHorizontalLine(4, position, nearbyLines[0]);
	findVerticalLine(4, position, nearbyLines[1]);
	findDiagonalLine(4, position, nearbyLines[2]);
	findAntiDiagonalLine(4, position, nearbyLines[3]);

	if (!isCapturingMove(position) && isThereDoubleThree(nearbyLines)) {
		std::cout << "Illegal move : Double three detected\n";
		return false;
	}

	return true;
}

bool	Gameplay::isWinningMove(std::string position) {
	std::vector<std::pair<std::string, int>>	nearbyLines[4];

	for (int i = 0; i < 4; i++) {
		std::pair<std::string, int> pair = std::make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}
	findHorizontalLine(4, position, nearbyLines[0]);
	findVerticalLine(4, position, nearbyLines[1]);
	findDiagonalLine(4, position, nearbyLines[2]);
	findAntiDiagonalLine(4, position, nearbyLines[3]);

	for (int i = 0; i < 4; i++) {
		if (nearbyLines[i].size() < 5)
			continue;

		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
				int count = 0;
				while (j < nearbyLines[i].size() && nearbyLines[i][j].second == _currentPlayer) {
					if (nearbyLines[i][j].second == _currentPlayer)
						count++;
					j++;
				}
				if (count >= 5/*  && !isAlignmentBreakable(position) */)
					return true;
		}
	}
	return false;
}

bool	Gameplay::isThereDoubleThree(std::vector<std::pair<std::string, int>> nearbyLines[4]) {
	int 	FreeThree = 0;
	int 	opponent = (_currentPlayer == 1) ? 2 : 1;

	for (int i = 0; i < 4; i++) {
		if (nearbyLines[i].size() < 5)
			continue;
		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
			if (nearbyLines[i][j].second == 0) {
				int count = 0;
				while (j < nearbyLines[i].size() && (nearbyLines[i][j].second == _currentPlayer || nearbyLines[i][j].second == 0)) {
					if (nearbyLines[i][j].second == _currentPlayer && j + 1 < nearbyLines[i].size() && nearbyLines[i][j + 1].second != opponent)
						count++;
					j++;
				}
				if (count >= 3)
					FreeThree++;
			}
		}
	}
	if (FreeThree >= 2)
		return true;
	return false;
}

void	Gameplay::findHorizontalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &horizontalLine) {
	for (int i = 1; i <= nbStones; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << position.substr(1);
		ssMinus << char(position[0] - i) << position.substr(1);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			horizontalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			horizontalLine.insert(horizontalLine.begin(), pair);
		}
	}
}

void	Gameplay::findVerticalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &verticalLine) {
	for (int i = 1; i <= nbStones; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << position[0] << std::to_string(std::stoi(position.substr(1)) + i);
		ssMinus << position[0] << std::to_string(std::stoi(position.substr(1)) - i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			verticalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			verticalLine.insert(verticalLine.begin(), pair);
		}
	}
}

void	Gameplay::findDiagonalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &diagonalLine) {
	for (int i = 1; i <= nbStones; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << std::to_string(std::stoi(position.substr(1)) + i);
		ssMinus << char(position[0] - i) << std::to_string(std::stoi(position.substr(1)) - i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			diagonalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			diagonalLine.insert(diagonalLine.begin(), pair);
		}
	}
}

void	Gameplay::findAntiDiagonalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &antiDiagonalLine) {
	for (int i = 1; i <= nbStones; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << std::to_string(std::stoi(position.substr(1)) - i);
		ssMinus << char(position[0] - i) << std::to_string(std::stoi(position.substr(1)) + i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosPlus, _playerPositions.at(newPosPlus));
			antiDiagonalLine.push_back(pair);
		}
		if (_playerPositions.find(newPosMinus) != _playerPositions.end()) {
			std::pair<std::string, int> pair = std::make_pair(newPosMinus, _playerPositions.at(newPosMinus));
			antiDiagonalLine.insert(antiDiagonalLine.begin(), pair);
		}
	}
}

bool	Gameplay::isCapturingMove(std::string position) {
	std::vector<std::pair<std::string, int>> nearbyLines[4];
	int 	opponent = (_currentPlayer == 1) ? 2 : 1;
	int		nbCaptures = 0;
	
	for (int i = 0; i < 4; i++) {
		std::pair<std::string, int> pair = std::make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}
	findVerticalLine(3, position, nearbyLines[0]);
	findHorizontalLine(3, position, nearbyLines[1]);
	findDiagonalLine(3, position, nearbyLines[2]);
	findAntiDiagonalLine(3, position, nearbyLines[3]);
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Next Vector" << std::endl;
		for (unsigned int j = 0; j < nearbyLines[i].size(); j++)
			std::cout << "Pos : " << nearbyLines[i][j].first << " | value :" << nearbyLines[i][j].second << std::endl;
		std::cout << std::endl;
	}
	
	for (int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
			if (j < nearbyLines[i].size() - 3) {
				if (nearbyLines[i][j].second == _currentPlayer
				&& nearbyLines[i][j + 1].second == opponent
				&& nearbyLines[i][j + 2].second == opponent
				&& nearbyLines[i][j + 3].second == _currentPlayer) {
					nbCaptures++;
					_playerPositions.at(nearbyLines[i][j + 1].first) = 0;
					_playerPositions.at(nearbyLines[i][j + 2].first) = 0;
				}
			}
		}
	}
	if (nbCaptures > 0)
		return true;
	return false;
}
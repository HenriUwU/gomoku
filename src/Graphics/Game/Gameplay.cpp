/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/16 16:45:26 by laprieur         ###   ########.fr       */
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
        sf::CircleShape circle(15.f);
		if (_currentPlayer == 1) {
        	circle.setFillColor(sf::Color::Green);
		}
		else {
			circle.setFillColor(sf::Color::Red);
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
			placeStone(position, _currentPlayer);
		}
	}
	// checkStatus(_currentPlayer);
	goban.drawPlayerPositions(window, _playerPositions);
	window.display();
}

void	Gameplay::placeStone(std::string position, int player) {
	if (_playerPositions[position] != 0)
		return;
	if (!isMoveLegal(position))
		return;
	_playerPositions[position] = player;

	if (_currentPlayer == 1)
		_currentPlayer = 2;
	else
		_currentPlayer = 1;
}

bool	Gameplay::isMoveLegal(std::string position) {
	std::vector<int>	nearbyLines[4];

	for (int i = 0; i < 4; i++) {
		nearbyLines[i].push_back(_currentPlayer);
	}
	findHorizontalLine(position, nearbyLines[0]);
	findVerticalLine(position, nearbyLines[1]);
	findDiagonalLine(position, nearbyLines[2]);
	findAntiDiagonalLine(position, nearbyLines[3]);

	if (isThereDoubleThree(nearbyLines, _currentPlayer)) {
		std::cout << "Illegal move : Double three detected\n";
		return false;
	}

	return true;
}

void	Gameplay::findHorizontalLine(std::string position, std::vector<int> &horizontalLine) {
	for (int i = 1; i <= 4; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << position.substr(1);
		ssMinus << char(position[0] - i) << position.substr(1);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end())
			horizontalLine.push_back(_playerPositions.at(newPosPlus));
		if (_playerPositions.find(newPosMinus) != _playerPositions.end())
			horizontalLine.insert(horizontalLine.begin(), _playerPositions.at(newPosMinus));
	}
}

void	Gameplay::findVerticalLine(std::string position, std::vector<int> &verticalLine) {
	for (int i = 1; i <= 4; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << position[0] << std::to_string(std::stoi(position.substr(1)) + i);
		ssMinus << position[0] << std::to_string(std::stoi(position.substr(1)) - i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end())
			verticalLine.push_back(_playerPositions.at(newPosPlus));
		if (_playerPositions.find(newPosMinus) != _playerPositions.end())
			verticalLine.insert(verticalLine.begin(), _playerPositions.at(newPosMinus));
	}
}

void	Gameplay::findDiagonalLine(std::string position, std::vector<int> &diagonalLine) {
	for (int i = 1; i <= 4; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << std::to_string(std::stoi(position.substr(1)) + i);
		ssMinus << char(position[0] - i) << std::to_string(std::stoi(position.substr(1)) - i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end())
			diagonalLine.push_back(_playerPositions.at(newPosPlus));
		if (_playerPositions.find(newPosMinus) != _playerPositions.end())
			diagonalLine.insert(diagonalLine.begin(), _playerPositions.at(newPosMinus));
	}
}

void	Gameplay::findAntiDiagonalLine(std::string position, std::vector<int> &antiDiagonalLine) {
	for (int i = 1; i <= 4; i++) {
		std::stringstream ssPlus, ssMinus;

		ssPlus << char(position[0] + i) << std::to_string(std::stoi(position.substr(1)) - i);
		ssMinus << char(position[0] - i) << std::to_string(std::stoi(position.substr(1)) + i);
		std::string newPosPlus = ssPlus.str();
		std::string newPosMinus = ssMinus.str();

		if (_playerPositions.find(newPosPlus) != _playerPositions.end())
			antiDiagonalLine.push_back(_playerPositions.at(newPosPlus));
		if (_playerPositions.find(newPosMinus) != _playerPositions.end())
			antiDiagonalLine.insert(antiDiagonalLine.begin(), _playerPositions.at(newPosMinus));
	}
}

bool	Gameplay::isThereDoubleThree(std::vector<int>	nearbyLines[4], int player) {
	int 	FreeThree = 0;
	int 	opponent = (player == 1) ? 2 : 1;

	for (int i = 0; i < 4; i++) {
		if (nearbyLines[i].size() < 5)
			continue;

		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
			if (nearbyLines[i][j] == 0) {
				int count = 0;
				while (j < nearbyLines[i].size() && (nearbyLines[i][j] == player || nearbyLines[i][j] == 0)) {
					if (nearbyLines[i][j] == player && j + 1 < nearbyLines[i].size() && nearbyLines[i][j + 1] != opponent)
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
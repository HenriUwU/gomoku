/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/15 15:41:38 by hsebille         ###   ########.fr       */
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

    // Place the stone on the grid if left mouse button is pressed
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
            char xCoord = 'A' + static_cast<int>(xIndex);
            int yCoord = 19 - static_cast<int>(yIndex);
            std::string position = std::string(1, xCoord) + std::to_string(yCoord);

            // Place the stone for the current player
            placeStone(position, _currentPlayer);
        }
    }
	goban.drawPlayerPositions(window, _playerPositions);
    window.display();
}

void Gameplay::placeStone(std::string position, int player) {
	if (_playerPositions[position] != 0) {
		return;
	}
	_playerPositions[position] = player;
	if (_currentPlayer == 1) {
		_currentPlayer = 2;
	}
	else {
		_currentPlayer = 1;
	}
}
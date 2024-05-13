/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 12:03:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Goban.hpp"

Goban::Goban(sf::RenderWindow &window) {
	_gridSize = _windowHeight - 75;
	_cellSize = _gridSize / 18.0f;
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
	_gridStartPoint = std::make_pair((_windowWidth - _windowHeight) / 2 + 35, 35);
}

Goban::~Goban() {}

void	Goban::displayCheckerboard(sf::RenderWindow &window) {
	// Display the grid
	for (int i = 0; i < 19; i++) {
		sf::Vertex verticalLine[] =
		{
			sf::Vertex(sf::Vector2f((_gridSize / 18) * i + _gridStartPoint.first, _gridStartPoint.second)),
			sf::Vertex(sf::Vector2f((_gridSize / 18) * i + _gridStartPoint.first, _gridStartPoint.second + _gridSize))
		};

		sf::Vertex horizontalLine[] =
		{
			sf::Vertex(sf::Vector2f(_gridStartPoint.first, (_gridSize / 18) * i + _gridStartPoint.second)),
			sf::Vertex(sf::Vector2f(_gridStartPoint.first + _gridSize, (_gridSize / 18) * i + _gridStartPoint.second))
		};

		window.draw(verticalLine, 2, sf::Lines);
		window.draw(horizontalLine, 2, sf::Lines);
	}

	sf::Font font;
	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		return ;
	}

	for (int i = 1; i < 20; i++) {
		std::string number = std::to_string(i);
		std::string letter(1, '@' + i);
		sf::Text xIndex(letter, font, 15);
		sf::Text yIndex(number, font, 15);
		xIndex.setPosition((_windowWidth - _gridSize) / 2 + _cellSize * i - _cellSize - 7, _gridSize + 45);
		yIndex.setPosition((_windowWidth - _gridSize) / 2 - 40, _gridSize - _cellSize * i + _cellSize + 25);
		window.draw(xIndex);
		window.draw(yIndex);
	}
}

void	Goban::circleFollowMouse(sf::RenderWindow &window) {
	// Create the circle
	sf::CircleShape	circle(15.f);
	circle.setFillColor(sf::Color::Green);

	// Determine the mouse position
	sf::Vector2i	mousePosition = sf::Mouse::getPosition(window);

	// Calculate the nearest grid intersection point to the mouse cursor
	float			xIndex = std::round((mousePosition.x - _gridStartPoint.first) / _cellSize);
	float			yIndex = std::round((mousePosition.y - _gridStartPoint.second) / _cellSize);

	// Display the elements
	window.clear();
	displayCheckerboard(window);
	if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
		sf::Vector2f	nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}
	window.display();
}
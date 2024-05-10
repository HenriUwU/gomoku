/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:50:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/10 14:25:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window) {
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
	_gridStartPoint = std::make_pair((_windowWidth - (_windowHeight - 20)) / 2, 10);
}

Graphics::~Graphics() {}

void	Graphics::displayCheckerboard(sf::RenderWindow &window) {
	// Calculate the grid size
	float 	gridSize = _windowHeight - 20;

	// Display the grid
	for (int i = 0; i < 20; i++) {
		sf::Vertex verticalLine[] =
		{
			sf::Vertex(sf::Vector2f((gridSize / 19) * i + _gridStartPoint.first, _gridStartPoint.second)),
			sf::Vertex(sf::Vector2f((gridSize / 19) * i + _gridStartPoint.first, _gridStartPoint.second + gridSize))
		};

		sf::Vertex horizontalLine[] =
		{
			sf::Vertex(sf::Vector2f(_gridStartPoint.first, (gridSize / 19) * i + _gridStartPoint.second)),
			sf::Vertex(sf::Vector2f(_gridStartPoint.first + gridSize, (gridSize / 19) * i + _gridStartPoint.second))
		};

		window.draw(verticalLine, 2, sf::Lines);
		window.draw(horizontalLine, 2, sf::Lines);
	}
}

void	Graphics::circleFollowMouse(sf::RenderWindow &window) {
	// Create the circle
	sf::CircleShape	circle(25.f);
	circle.setFillColor(sf::Color::Green);

	// Calculate the cell size
	float			cellSize = (_windowHeight - 20) / 19.0f;

	// Determine the mouse position
	sf::Vector2i	mousePosition = sf::Mouse::getPosition(window);

	// Calculate the nearest grid intersection point to the mouse cursor
	float			xIndex = std::round((mousePosition.x - _gridStartPoint.first) / cellSize);
	float			yIndex = std::round((mousePosition.y - _gridStartPoint.second) / cellSize);

	// Display the elements
	window.clear();
	displayCheckerboard(window);
	if (xIndex > 0 && xIndex < 19 && yIndex > 0 && yIndex < 19) {
		sf::Vector2f	nearestIntersection(_gridStartPoint.first + xIndex * cellSize, _gridStartPoint.second + yIndex * cellSize);
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}
	window.display();
}
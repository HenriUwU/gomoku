/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 16:01:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Gameplay::Gameplay(sf::RenderWindow& window) : Graphics(window) {}

Gameplay::~Gameplay() {}

void	Gameplay::circleFollowMouse(sf::RenderWindow &window) {
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
	Goban goban(window);
	goban.display(window);
	if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
		char xCoord = 'A' + static_cast<int>(xIndex);
        int yCoord = 19 - static_cast<int>(yIndex);
        std::string position = std::string(1, xCoord) + std::to_string(yCoord);
        std::cout << "Clicked position: " << position << std::endl;
		sf::Vector2f	nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}
	window.display();
}

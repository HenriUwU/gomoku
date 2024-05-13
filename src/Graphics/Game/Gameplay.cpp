/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 13:58:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gameplay.hpp"

Gameplay::Gameplay(sf::RenderWindow &window) {}

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
		sf::Vector2f	nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}
	window.display();
}
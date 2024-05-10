/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:50:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/10 13:18:18 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window) {
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
}

Graphics::~Graphics() {}

void	Graphics::displayCheckerboard(sf::RenderWindow &window) {
	std::pair <unsigned int, unsigned int>	startPoint = std::make_pair((_windowWidth - (_windowHeight - 20)) / 2, 10);
	float 	dimensions = _windowHeight - 20;

	for (int i = 0; i < 20; i++) {
		sf::Vertex verticalLine[] =
		{
			sf::Vertex(sf::Vector2f((dimensions / 19) * i + startPoint.first, startPoint.second)),
			sf::Vertex(sf::Vector2f((dimensions / 19) * i + startPoint.first, startPoint.second + dimensions))
		};

		sf::Vertex horizontalLine[] =
		{
			sf::Vertex(sf::Vector2f(startPoint.first, (dimensions / 19) * i + startPoint.second)),
			sf::Vertex(sf::Vector2f(startPoint.first + dimensions, (dimensions / 19) * i + startPoint.second))
		};

		window.draw(verticalLine, 2, sf::Lines);
		window.draw(horizontalLine, 2, sf::Lines);
	}
}

void	Graphics::circleFollowMouse(sf::RenderWindow &window) {
	window.clear();
	sf::CircleShape	circle(25.f);
	circle.setFillColor(sf::Color::Green);
	displayCheckerboard(window);

	float cellSize = (_windowHeight - 20) / 19.0f;
	std::pair <unsigned int, unsigned int>	startPoint = std::make_pair((_windowWidth - (_windowHeight - 20)) / 2, 10);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	
	float xIndex = std::round((mousePosition.x - startPoint.first) / cellSize);
	float yIndex = std::round((mousePosition.y - startPoint.second) / cellSize);

	sf::Vector2f nearestIntersection(startPoint.first + xIndex * cellSize, startPoint.second + yIndex * cellSize);
	circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());

	if (xIndex > 0 && xIndex < 19 && yIndex > 0 && yIndex < 19) {
		// Draw the circle at the nearest grid intersection point
		sf::Vector2f nearestIntersection(startPoint.first + xIndex * cellSize, startPoint.second + yIndex * cellSize);
		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());
		window.draw(circle);
	}

	window.display();

}
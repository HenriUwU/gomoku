/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/15 13:34:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Gameplay::Gameplay(sf::RenderWindow& window) : Graphics(window) {}

Gameplay::~Gameplay() {}

void Gameplay::circleFollowMouse(sf::RenderWindow &window, sf::Event &event) {
	static sf::CircleShape circle(15.f);
	circle.setFillColor(sf::Color::Green);

	static sf::CircleShape redCircle(15.f);
	redCircle.setFillColor(sf::Color::Red);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	float xIndex = std::round((mousePosition.x - _gridStartPoint.first) / _cellSize);
	float yIndex = std::round((mousePosition.y - _gridStartPoint.second) / _cellSize);

	window.clear();
	Goban goban(window);
	goban.display(window);
	Debug::init(window);
	if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
		char xCoord = 'A' + static_cast<int>(xIndex);
		int yCoord = 19 - static_cast<int>(yIndex);
		std::string position = std::string(1, xCoord) + std::to_string(yCoord);

		Debug::actualPos(window, position);

		sf::Vector2f nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);

		circle.setPosition(nearestIntersection.x - circle.getRadius(), nearestIntersection.y - circle.getRadius());

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			redCircle.setPosition(nearestIntersection.x - redCircle.getRadius(), nearestIntersection.y - redCircle.getRadius());
			placeStone(position, 1);
		}
		else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			redCircle.setPosition(nearestIntersection.x - redCircle.getRadius(), nearestIntersection.y - redCircle.getRadius());
			window.draw(circle);
			window.draw(redCircle);
		}
	}

	window.display();
}

void Gameplay::placeStone(std::string position, int player) {
	_playerPositions.insert(_playerPositions.begin(), std::pair<std::string, int>(position, player));
}


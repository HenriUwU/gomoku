/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/20 16:29:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Goban::Goban(sf::RenderWindow &window) : Graphics(window) {}

Goban::~Goban() {}

void	Goban::display(sf::RenderWindow &window) {
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

	sf::Text player1("Player 1", font, 30);
	sf::Text player2("Player 2", font, 30);

	// Calculate player name positions
	player1.setPosition(200, 10);
	player2.setPosition(1920 - 300, 10);

	window.draw(player1);
	window.draw(player2);

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

void	Goban::drawPlayerPositions(sf::RenderWindow &window, std::map<std::string, int> playerPositions) {
	for (int i = 0; i < 19; i++) {
		char character = 'A' + i;
		for (int j = 1; j < 20; j++) {
			std::string position = std::string(1, character) + std::to_string(j);
			int playerId = playerPositions[position];
			
			// if there is no stone on this position, skip
			if (playerId == 0) {
				continue;
			}

			// convert the position to x and y indices
			char xCoord = position[0];
			int yCoord = std::stoi(position.substr(1));
			int xIndex = xCoord - 'A';
			int yIndex = 19 - yCoord;
			
			sf::Vector2f nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
			sf::CircleShape playerCircle(15.f);

			if (playerId == 1) {
				playerCircle.setFillColor(sf::Color::Green);
			}
			else {
				playerCircle.setFillColor(sf::Color::Red);
			}

			playerCircle.setPosition(nearestIntersection.x - playerCircle.getRadius(), nearestIntersection.y - playerCircle.getRadius());

			// Dessiner le cercle du joueur sur la fenêtre
			window.draw(playerCircle);
		}
	}
}

void	Goban::scoreTable(int player, sf::RenderWindow &window) {
	sf::Font font;
	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		return ;
	}

	sf::Text player1("Player 1", font, 20);
	sf::Text player2("Player 2", font, 20);
	sf::Text player1Score(std::to_string(player), font, 20);
	sf::Text player2Score(std::to_string(player), font, 20);

	player1.setPosition(_windowWidth - 200, 50);
	player2.setPosition(_windowWidth - 200, 100);
	player1Score.setPosition(_windowWidth - 100, 50);
	player2Score.setPosition(_windowWidth - 100, 100);

	window.clear();
	window.draw(player1);
	window.draw(player2);
	window.draw(player1Score);
	window.draw(player2Score);
	(void)player;
	window.clear();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/23 15:13:34 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Goban::Goban(sf::RenderWindow &window) : Graphics(window) {}

Goban::~Goban() {}

void Goban::display(sf::RenderWindow &window) {
    sf::Color gobanBackgroundColor(84, 84, 84);
	sf::Color backgroundColor(48, 1, 30);
	
	// Draw the background
	sf::RectangleShape background(sf::Vector2f(_windowWidth, _windowHeight));
	background.setFillColor(backgroundColor);
	background.setPosition(0, 0);
	window.draw(background);
	
    // Draw the goban background
    sf::RectangleShape gobanBackground(sf::Vector2f(_gridSize + 20, _gridSize + 20));
    gobanBackground.setPosition(_gridStartPoint.first - 10, _gridStartPoint.second - 10);
    gobanBackground.setFillColor(gobanBackgroundColor);
    window.draw(gobanBackground);

    // Display the grid
	sf::Color linecolor(242, 244, 243);
    for (int i = 0; i < 19; i++) {
        sf::Vertex verticalLine[] =
        {
            sf::Vertex(sf::Vector2f((_gridSize / 18) * i + _gridStartPoint.first, _gridStartPoint.second), linecolor),
            sf::Vertex(sf::Vector2f((_gridSize / 18) * i + _gridStartPoint.first, _gridStartPoint.second + _gridSize), linecolor)
        };

        sf::Vertex horizontalLine[] =
        {
            sf::Vertex(sf::Vector2f(_gridStartPoint.first, (_gridSize / 18) * i + _gridStartPoint.second), linecolor),
            sf::Vertex(sf::Vector2f(_gridStartPoint.first + _gridSize, (_gridSize / 18) * i + _gridStartPoint.second), linecolor)
        };

        window.draw(verticalLine, 2, sf::Lines);
        window.draw(horizontalLine, 2, sf::Lines);
    }

	sf::Font font;
	sf::Font playerFont;

	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		return;
	}

	if (!playerFont.loadFromFile("assets/fonts/ChunkFive-Regular.otf")) {
		return;
	}

	sf::Text	player1("Player 1", playerFont, 25);
	sf::Text	player2("Player 2", playerFont, 25);
	sf::Color	playerColor(182, 204, 161);

	player1.setPosition(200, 10);
	player2.setPosition(1920 - 300, 10);
	player1.setFillColor(playerColor);
	player2.setFillColor(playerColor);

	window.draw(player1);
	window.draw(player2);

	sf::Color coordinatesColor(182, 204, 161);

	for (int i = 1; i < 20; i++) {
		std::string number = std::to_string(i);
		std::string letter(1, '@' + i);

		sf::Text xIndexBottom(letter, font, 13);
		sf::Text yIndexLeft(number, font, 13);
		sf::Text xIndexTop(letter, font, 13);
		sf::Text yIndexRight(number, font, 13);

		xIndexBottom.setFillColor(coordinatesColor);
		yIndexLeft.setFillColor(coordinatesColor);
		xIndexTop.setFillColor(coordinatesColor);
		yIndexRight.setFillColor(coordinatesColor);

		// Bottom and left coordinates
		xIndexBottom.setPosition((_windowWidth - _gridSize) / 2 + _cellSize * i - _cellSize - 7, _gridSize + 45);
		yIndexLeft.setPosition((_windowWidth - _gridSize) / 2 - 40, _gridSize - _cellSize * i + _cellSize + 25);

		// Top and right coordinates
		xIndexTop.setPosition((_windowWidth - _gridSize) / 2 + _cellSize * i - _cellSize - 7, _gridStartPoint.second - 30);
		yIndexRight.setPosition((_windowWidth - _gridSize) / 2 + _gridSize + 10, _gridSize - _cellSize * i + _cellSize + 25);

		window.draw(xIndexBottom);
		window.draw(yIndexLeft);
		window.draw(xIndexTop);
		window.draw(yIndexRight);
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
			sf::CircleShape playerCircle(13.f);

			sf::Color firstPlayerColor(138, 203, 136);
			sf::Color secondPlayerColor(254, 74, 73);

			if (playerId == 1) {
				playerCircle.setFillColor(firstPlayerColor);
			}
			else {
				playerCircle.setFillColor(secondPlayerColor);
			}

			playerCircle.setPosition(nearestIntersection.x - playerCircle.getRadius(), nearestIntersection.y - playerCircle.getRadius());
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 19:21:31 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Goban::Goban(sf::RenderWindow &window) : Graphics(window) {}

Goban::~Goban() {}

void Goban::display(sf::RenderWindow &window) {
	sf::RectangleShape	background(sf::Vector2f(_windowWidth, _windowHeight));
	sf::Texture 		gobanTexture;
	sf::Sprite			goban;

	sf::Text			backToMenu("Back to menu", _ex02BlackItalicFont, 20);
	sf::Text			player1("Player 1", _ex02BlackItalicFont, 85);
	sf::Text			player2("Player 2", _ex02BlackItalicFont, 85);
	sf::Text			capturedStones("Captured stones:", _ex02BlackItalicFont, 22);
	sf::Text			capturedStones2("Captured stones:", _ex02BlackItalicFont, 22);
	sf::Text			totalTimer("Total play time:", _ex02BlackItalicFont, 22);
	sf::Text			totalTimer2("Total play time:", _ex02BlackItalicFont, 22);
	sf::Text			lastMoveTimer("Last move time:", _ex02BlackItalicFont, 22);
	sf::Text			lastMoveTimer2("Last move time:", _ex02BlackItalicFont, 22);

	if (!gobanTexture.loadFromFile("assets/images/icons/Goban.png")) {
		return ;
	}
	background.setFillColor(sf::Color(38, 1, 69));

	goban.setTexture(gobanTexture);

	_firstPlayerAvatar.setTexture(_lanceAvatarTexture);
	_secondPlayerAvatar.setTexture(_hericAvatarTexture);
	_returnArrow.setTexture(_returnArrowTexture);

	background.setPosition(0, 0);
	backToMenu.setPosition(114, 54);
	_returnArrow.setPosition(34, 34);
	goban.setPosition(477, 0);
	player1.setPosition(72, 445);
	player2.setPosition(1509, 445);
	capturedStones.setPosition(138, 575);
	capturedStones2.setPosition(1580, 575);
	totalTimer.setPosition(138, 605);
	totalTimer2.setPosition(1580, 605);
	lastMoveTimer.setPosition(138, 635);
	lastMoveTimer2.setPosition(1580, 635);
	_firstPlayerAvatar.setPosition(167, 278);
	_secondPlayerAvatar.setPosition(1607, 278);
	
	window.draw(background);
	window.draw(backToMenu);
	window.draw(_returnArrow);
	window.draw(goban);
	window.draw(player1);
	window.draw(player2);
	window.draw(capturedStones);
	window.draw(capturedStones2);
	window.draw(totalTimer);
	window.draw(totalTimer2);
	window.draw(lastMoveTimer);
	window.draw(lastMoveTimer2);
	window.draw(_firstPlayerAvatar);
	window.draw(_secondPlayerAvatar);
}

void	Goban::returnButton(sf::Event &event, sf::RenderWindow &window) {
	(void)window;
	if (_returnArrow.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
		_returnArrow.setTexture(_returnArrowHighlightTexture);
		if (event.type == sf::Event::MouseButtonPressed) {
			displayMenu = true;
			displayGame = false;
		}
	}
	else {
		_returnArrow.setTexture(_returnArrowTexture);
	}
}

void	Goban::drawPlayerPositions(sf::RenderWindow &window, map<string, int> playerPositions) {
	for (int i = 0; i < 19; i++) {
		char character = 'A' + i;
		for (int j = 1; j < 20; j++) {
			string position = string(1, character) + to_string(j);
			int playerId = playerPositions[position];
			
			// if there is no stone on this position, skip
			if (playerId == 0) {
				continue;
			}

			// convert the position to x and y indices
			char xCoord = position[0];
			int yCoord = stoi(position.substr(1));
			int xIndex = xCoord - 'A';
			int yIndex = 19 - yCoord;
			
			sf::Vector2f nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
			sf::CircleShape playerCircle(13.f);

			sf::Color firstPlayerColor(0, 0, 0);
			sf::Color secondPlayerColor(255, 255, 255);

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
	sf::Text player1Score(to_string(player), font, 20);
	sf::Text player2Score(to_string(player), font, 20);

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
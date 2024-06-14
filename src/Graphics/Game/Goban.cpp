/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/14 11:04:12 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Goban::Goban(sf::RenderWindow &window) : Graphics(window) {
	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		cerr << "Error while loading the 'Exo2-Black.ttf' file." << endl;
	if (!_ex02BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		cerr << "Error while loading the 'Exo2-BlackItalic.ttf' file." << endl;
	if (!_lanceAvatarTexture.loadFromFile("assets/images/avatars/lance.png"))
		cerr << "Error while loading the 'lance.png' file." << endl;
	if (!_tommyAvatarTexture.loadFromFile("assets/images/avatars/tommy.png"))
		cerr << "Error while loading the 'tommy.png' file." << endl;
	if (!_alexAvatarTexture.loadFromFile("assets/images/avatars/alex.png"))
		cerr << "Error while loading the 'alex.png' file." << endl;
	if (!_guntherAvatarTexture.loadFromFile("assets/images/avatars/gunther.png"))
		cerr << "Error while loading the 'gunther.png' file." << endl;
	if (!_hericAvatarTexture.loadFromFile("assets/images/avatars/heric.png"))
		cerr << "Error while loading the 'heric.png' file." << endl;
	if (!_laureAvatarTexture.loadFromFile("assets/images/avatars/laure.png"))
		cerr << "Error while loading the 'laure.png' file." << endl;
	if (!_returnArrowTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		cerr << "Error while loading the 'return_arrow.png' file." << endl;
	if (!_returnArrowHighlightTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		cerr << "Error while loading the 'return_arrow_highlight' file." << endl;
	if (!_gobanTexture.loadFromFile("assets/images/icons/Goban.png"))
		return ;

	_backToMenu.setString("Back to menu");
	_player1.setString("Player 1");
	_player2.setString("Player 2");
	_capturedStones.setString("Captured stones:");
	_capturedStones2.setString("Captured stones:");
	_totalTimer.setString("Total play time:");
	_totalTimer2.setString("Total play time:");
	_lastMoveTimer.setString("Last move time:");
	_lastMoveTimer2.setString("Last move time:");

	_backToMenu.setFont(_ex02BlackItalicFont);
	_player1.setFont(_ex02BlackItalicFont);
	_player2.setFont(_ex02BlackItalicFont);
	_capturedStones.setFont(_ex02BlackItalicFont);
	_capturedStones2.setFont(_ex02BlackItalicFont);
	_totalTimer.setFont(_ex02BlackItalicFont);
	_totalTimer2.setFont(_ex02BlackItalicFont);
	_lastMoveTimer.setFont(_ex02BlackItalicFont);
	_lastMoveTimer2.setFont(_ex02BlackItalicFont);

	_backToMenu.setCharacterSize(20);
	_player1.setCharacterSize(85);
	_player2.setCharacterSize(85);
	_capturedStones.setCharacterSize(22);
	_capturedStones2.setCharacterSize(22);
	_totalTimer.setCharacterSize(22);
	_totalTimer2.setCharacterSize(22);
	_lastMoveTimer.setCharacterSize(22);
	_lastMoveTimer2.setCharacterSize(22);

	_firstPlayerAvatar.setTexture(_lanceAvatarTexture);
	_secondPlayerAvatar.setTexture(_hericAvatarTexture);
	_returnArrow.setTexture(_returnArrowTexture);
	_goban.setTexture(_gobanTexture);

	_firstPlayerAvatar.setPosition(167, 278);
	_secondPlayerAvatar.setPosition(1607, 278);
	_returnArrow.setPosition(34, 34);
	_goban.setPosition(477, 0);
	_backToMenu.setPosition(114, 54);
	_player1.setPosition(72, 445);
	_player2.setPosition(1509, 445);
	_capturedStones.setPosition(138, 575);
	_capturedStones2.setPosition(1580, 575);
	_totalTimer.setPosition(138, 605);
	_totalTimer2.setPosition(1580, 605);
	_lastMoveTimer.setPosition(138, 635);
	_lastMoveTimer2.setPosition(1580, 635);
}

Goban::~Goban() {}

void Goban::display(sf::RenderWindow &window) {
	sf::RectangleShape	background(sf::Vector2f(_windowWidth, _windowHeight));
	background.setFillColor(sf::Color(38, 1, 69));

	background.setPosition(0, 0);
	
	window.draw(background);
	window.draw(_backToMenu);
	window.draw(_returnArrow);
	window.draw(_goban);
	window.draw(_player1);
	window.draw(_player2);
	window.draw(_capturedStones);
	window.draw(_capturedStones2);
	window.draw(_totalTimer);
	window.draw(_totalTimer2);
	window.draw(_lastMoveTimer);
	window.draw(_lastMoveTimer2);
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
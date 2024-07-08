/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:51:46 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/24 14:56:10 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Goban::Goban() {
	init();
}

Goban::~Goban() {}

void Goban::display(sf::Event& event, sf::RenderWindow &window, Bitboard& bitboard) {
	returnButton(event, window);
	defineStones();
	defineAvatars();
	defineBoard();

	window.clear(sf::Color(38, 1, 69));
	window.draw(_gamePageSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_gobanSprite);
	window.draw(_firstPlayerAvatarSprite);
	window.draw(_secondPlayerAvatarSprite);
	window.draw(_gridAndIndexSprite);
	drawStones(window, bitboard);
}

void Goban::returnButton(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseMoved) {
        if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            _backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
        else
            _backwardButtonSprite.setTexture(_backwardButtonTexture);
    }
    if (event.type == sf::Event::MouseButtonPressed)
        if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			gameState = MENU;
}

void	Goban::drawStones(sf::RenderWindow& window, Bitboard& bitboard) {
	sf::Vector2i gridPosition = sf::Vector2i(527, 50);
	
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {
			if (bitboard.getBit(x, y) == 1) {
				_firstPlayerStoneSprite.setPosition(gridPosition.x + x * 48 - 13, gridPosition.y + y * 48 - 13);
				window.draw(_firstPlayerStoneSprite);
			}
			else if (bitboard.getBit(x, y) == 2) {
				_secondPlayerStoneSprite.setPosition(gridPosition.x + x * 48 - 13, gridPosition.y + y * 48 - 13);
				window.draw(_secondPlayerStoneSprite);
			}
		}
	}
}

void	Goban::defineStones() {
	switch (stonesColors) {
		case NOSTONESCOLORS:
		case BLACK_WHITE:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[0]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[1]);
			break;
		case GREEN_RED:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[2]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[3]);
			break;
		case SALMON_CORAL:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[4]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[5]);
			break;
		case PINK_FLUOYELLOW:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[6]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[7]);
			break;
		case BLACK_YELLOW:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[0]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[8]);
			break;
		case ORANGE_VIOLET:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[9]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[10]);
			break;
		case DARKGREEN_LIGHTGREEN:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[11]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[12]);
			break;
		case TURQUOISEGREEN_INDIGO:
			_firstPlayerStoneSprite.setTexture(_stonesTextures[13]);
			_secondPlayerStoneSprite.setTexture(_stonesTextures[14]);
			break;
	}
}

void	Goban::defineAvatars() {
	if (playerOneAvatar == NOAVATAR) {
		_firstPlayerAvatarSprite.setTexture(_avatarsTextures[0]);
		_secondPlayerAvatarSprite.setTexture(_avatarsTextures[1]);
	} else {
		_firstPlayerAvatarSprite.setTexture(_avatarsTextures[playerOneAvatar]);
		if (playerOneAvatar + 1 < 6)
			_secondPlayerAvatarSprite.setTexture(_avatarsTextures[playerOneAvatar + 1]);
		else
			_secondPlayerAvatarSprite.setTexture(_avatarsTextures[0]);
	}
}

void	Goban::defineBoard() {
	if (boardColor == NOBOARD) {
		_gobanSprite.setTexture(_boardsTextures[0]);
	} else {
		for (int i = 0; i < 8; i++)
			if (i == boardColor)
				_gobanSprite.setTexture(_boardsTextures[i]);
	}
}

void	Goban::init() {
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/backwardButtonTexture.png"))
		cerr << "Error while loading the 'backwardButtonTexture.png' file." << endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/backwardHoveredButtonTexture.png"))
		cerr << "Error while loading the 'backwardHoveredButtonTexture' file." << endl;
	if (!_gridAndIndexTexture.loadFromFile("assets/images/game/gridAndIndexTexture.png"))
		cerr << "Error while loading the 'grid.png' file." << endl;
	if (!_gamePageTexture.loadFromFile("assets/images/game/1VS1PageTexture.png"))
		cerr << "Error while loading the 'gamePage.png' file." << endl;
	if (!_firstStoneTexture.loadFromFile("assets/images/game/stones/blackStoneTexture.png"))
		cerr << "Error while loading the 'firstStone.png' file." << endl;
	if (!_secondStoneTexture.loadFromFile("assets/images/game/stones/whiteStoneTexture.png"))
		cerr << "Error while loading the 'secondStone.png' file." << endl;

	const std::string stonesColors[] = {"black", "white", "green", "red", "salmon", "coral", "pink", "fluoYellow", "yellow", "orange", "violet", "darkGreen", "lightGreen", "turquoiseGreen", "indigo"};
	for (int i = 0; i < 15; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/game/stones/" + stonesColors[i] + "StoneTexture.png";
		if (texture.loadFromFile(filePath))
			_stonesTextures.push_back(texture);
		else
			std::cerr << "Failed to load texture: " << filePath << std::endl;
	}

	const std::string avatarsNames[] = {"tommy", "laure", "alex", "heric", "mousse", "gunther"};
	for (int i = 0; i < 6; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/game/avatars/" + avatarsNames[i] + "AvatarTexture.png";
		if (texture.loadFromFile(filePath))
			_avatarsTextures.push_back(texture);
		else
			std::cerr << "Failed to load texture: " << filePath << std::endl;
	}

	const std::string boardsColors[] = {"azure", "yellow", "red", "orange", "pink", "green", "gray", "black"};
	for (int i = 0; i < 8; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/game/boards/" + boardsColors[i] + "BoardTexture.png";
		if (texture.loadFromFile(filePath))
			_boardsTextures.push_back(texture);
		else
			std::cerr << "Failed to load texture: " << filePath << std::endl;
	}

	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_gridAndIndexSprite.setTexture(_gridAndIndexTexture);
	_gamePageSprite.setTexture(_gamePageTexture);
	_firstPlayerStoneSprite.setTexture(_firstStoneTexture);
	_secondPlayerStoneSprite.setTexture(_secondStoneTexture);

	_firstPlayerAvatarSprite.setPosition(167, 278);
	_secondPlayerAvatarSprite.setPosition(1607, 278);
	_gobanSprite.setPosition(477, 0);
	_gridAndIndexSprite.setPosition(477, 0);
	_backwardButtonSprite.setPosition(100, 100);
}
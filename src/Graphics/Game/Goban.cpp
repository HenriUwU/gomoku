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
	if (boardColor == AZURE)
		_gobanSprite.setTexture(_azureBoardTexture);
	else if (boardColor == BLACK)
		_gobanSprite.setTexture(_blackBoardTexture);
	else if (boardColor == GRAY)
		_gobanSprite.setTexture(_grayBoardTexture);
	else if (boardColor == GREEN)
		_gobanSprite.setTexture(_greenBoardTexture);
	else if (boardColor == ORANGE)
		_gobanSprite.setTexture(_orangeBoardTexture);
	else if (boardColor == PINK)
		_gobanSprite.setTexture(_pinkBoardTexture);
	else if (boardColor == RED)
		_gobanSprite.setTexture(_redBoardTexture);
	else if (boardColor == YELLOW)
		_gobanSprite.setTexture(_yellowBoardTexture);
	
	returnButton(event, window);

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

void	Goban::init() {
	if (!_mousseAvatarTexture.loadFromFile("assets/images/game/avatars/mousseAvatarTexture.png"))
		cerr << "Error while loading the 'mousseAvatarTexture.png' file." << endl;
	if (!_tommyAvatarTexture.loadFromFile("assets/images/game/avatars/tommyAvatarTexture.png"))
		cerr << "Error while loading the 'tommyAvatarTexture.png' file." << endl;
	if (!_alexAvatarTexture.loadFromFile("assets/images/game/avatars/alexAvatarTexture.png"))
		cerr << "Error while loading the 'alexAvatarTexture.png' file." << endl;
	if (!_guntherAvatarTexture.loadFromFile("assets/images/game/avatars/guntherAvatarTexture.png"))
		cerr << "Error while loading the 'guntherAvatarTexture.png' file." << endl;
	if (!_hericAvatarTexture.loadFromFile("assets/images/game/avatars/hericAvatarTexture.png"))
		cerr << "Error while loading the 'hericAvatarTexture.png' file." << endl;
	if (!_laureAvatarTexture.loadFromFile("assets/images/game/avatars/laureAvatarTexture.png"))
		cerr << "Error while loading the 'laureAvatarTexture.png' file." << endl;
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/backwardButtonTexture.png"))
		cerr << "Error while loading the 'backwardButtonTexture.png' file." << endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/backwardHoveredButtonTexture.png"))
		cerr << "Error while loading the 'backwardHoveredButtonTexture' file." << endl;
	if (!_azureBoardTexture.loadFromFile("assets/images/game/boards/azureBoardTexture.png"))
		cerr << "Error while loading the 'azureBoardTexture.png' file." << endl;
	if (!_blackBoardTexture.loadFromFile("assets/images/game/boards/blackBoardTexture.png"))
		cerr << "Error while loading the 'blackBoardTexture.png' file." << endl;
	if (!_grayBoardTexture.loadFromFile("assets/images/game/boards/grayBoardTexture.png"))
		cerr << "Error while loading the 'grayBoardTexture.png' file." << endl;
	if (!_greenBoardTexture.loadFromFile("assets/images/game/boards/greenBoardTexture.png"))
		cerr << "Error while loading the 'greenBoardTexture.png' file." << endl;
	if (!_orangeBoardTexture.loadFromFile("assets/images/game/boards/orangeBoardTexture.png"))
		cerr << "Error while loading the 'orangeBoardTexture.png' file." << endl;
	if (!_pinkBoardTexture.loadFromFile("assets/images/game/boards/pinkBoardTexture.png"))
		cerr << "Error while loading the 'pinkBoardTexture.png' file." << endl;
	if (!_redBoardTexture.loadFromFile("assets/images/game/boards/redBoardTexture.png"))
		cerr << "Error while loading the 'redBoardTexture.png' file." << endl;
	if (!_yellowBoardTexture.loadFromFile("assets/images/game/boards/yellowBoardTexture.png"))
		cerr << "Error while loading the 'yellowBoardTexture.png' file." << endl;
	if (!_gridAndIndexTexture.loadFromFile("assets/images/game/gridAndIndexTexture.png"))
		cerr << "Error while loading the 'grid.png' file." << endl;
	if (!_gamePageTexture.loadFromFile("assets/images/game/gamePageTexture.png"))
		cerr << "Error while loading the 'gamePage.png' file." << endl;
	if (!_firstStoneTexture.loadFromFile("assets/images/game/stones/blackStoneTexture.png"))
		cerr << "Error while loading the 'firstStone.png' file." << endl;
	if (!_secondStoneTexture.loadFromFile("assets/images/game/stones/whiteStoneTexture.png"))
		cerr << "Error while loading the 'secondStone.png' file." << endl;

	_firstPlayerAvatarSprite.setTexture(_mousseAvatarTexture);
	_secondPlayerAvatarSprite.setTexture(_hericAvatarTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_gobanSprite.setTexture(_azureBoardTexture);
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
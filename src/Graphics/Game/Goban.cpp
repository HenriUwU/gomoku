/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:21 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/19 10:46:34 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Goban::Goban() {
	init();
}

Goban::~Goban() {}

void Goban::display(sf::Event& event, sf::RenderWindow &window) {
	if (boardColor == AZURE)
		_goban.setTexture(_gobanAzureTexture);
	else if (boardColor == BLACK)
		_goban.setTexture(_gobanBlackTexture);
	else if (boardColor == GRAY)
		_goban.setTexture(_gobanGrayTexture);
	else if (boardColor == GREEN)
		_goban.setTexture(_gobanGreenTexture);
	else if (boardColor == ORANGE)
		_goban.setTexture(_gobanOrangeTexture);
	else if (boardColor == PINK)
		_goban.setTexture(_gobanPinkTexture);
	else if (boardColor == RED)
		_goban.setTexture(_gobanRedTexture);
	else if (boardColor == YELLOW)
		_goban.setTexture(_gobanYellowTexture);
	
	returnButton(event, window);

	window.clear(sf::Color(38, 1, 69));
	window.draw(_gamePage);
	window.draw(_returnArrow);
	window.draw(_goban);
	window.draw(_firstPlayerAvatar);
	window.draw(_secondPlayerAvatar);
	window.draw(_grid);
}

void Goban::returnButton(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseMoved) {
        if (_returnArrow.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            _returnArrow.setTexture(_returnArrowHighlightTexture);
        else
            _returnArrow.setTexture(_returnArrowTexture);
    }
    if (event.type == sf::Event::MouseButtonPressed)
        if (_returnArrow.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			gameState = MENU;
}

void	Goban::init() {
	if (!_mousseAvatarTexture.loadFromFile("assets/images/avatars/mousse.png"))
		cerr << "Error while loading the 'mousse.png' file." << endl;
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
	if (!_gobanAzureTexture.loadFromFile("assets/images/boards/gobanAzure.png"))
		cerr << "Error while loading the 'gobanYellow.png' file." << endl;
	if (!_gobanBlackTexture.loadFromFile("assets/images/boards/gobanBlack.png"))
		cerr << "Error while loading the 'gobanBlack.png' file." << endl;
	if (!_gobanGrayTexture.loadFromFile("assets/images/boards/gobanGray.png"))
		cerr << "Error while loading the 'gobanGray.png' file." << endl;
	if (!_gobanGreenTexture.loadFromFile("assets/images/boards/gobanGreen.png"))
		cerr << "Error while loading the 'gobanGreen.png' file." << endl;
	if (!_gobanOrangeTexture.loadFromFile("assets/images/boards/gobanOrange.png"))
		cerr << "Error while loading the 'gobanOrange.png' file." << endl;
	if (!_gobanPinkTexture.loadFromFile("assets/images/boards/gobanPink.png"))
		cerr << "Error while loading the 'gobanPink.png' file." << endl;
	if (!_gobanRedTexture.loadFromFile("assets/images/boards/gobanRed.png"))
		cerr << "Error while loading the 'gobanRed.png' file." << endl;
	if (!_gobanYellowTexture.loadFromFile("assets/images/boards/gobanYellow.png"))
		cerr << "Error while loading the 'gobanYellow.png' file." << endl;
	if (!_gridTexture.loadFromFile("assets/images/boards/grid.png"))
		cerr << "Error while loading the 'grid.png' file." << endl;
	if (!_gamePageTexture.loadFromFile("assets/game/Game_Gomoku.png"))
		cerr << "Error while loading the 'gamePage.png' file." << endl;

	_firstPlayerAvatar.setTexture(_mousseAvatarTexture);
	_secondPlayerAvatar.setTexture(_hericAvatarTexture);
	_returnArrow.setTexture(_returnArrowTexture);
	_goban.setTexture(_gobanAzureTexture);
	_grid.setTexture(_gridTexture);
	_gamePage.setTexture(_gamePageTexture);

	_firstPlayerAvatar.setPosition(167, 278);
	_secondPlayerAvatar.setPosition(1607, 278);
	_goban.setPosition(477, 0);
	_grid.setPosition(525, 48);
	_returnArrow.setPosition(100, 100);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:13 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/03 15:52:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomMenu.hpp"

CustomMenu::CustomMenu() {
	init();
}

CustomMenu::~CustomMenu() {}

void	CustomMenu::display(sf::RenderWindow& window) {
	if (stonesColors == NOSTONESCOLORS)
		_stoneSelectorSprite.setPosition(-100, -100);
	if (stonesColors == BLACK_WHITE)
		_stoneSelectorSprite.setPosition(691 - 8, 379 - 8);
	if (stonesColors == BLACK_YELLOW)
		_stoneSelectorSprite.setPosition(971 - 8, 379 - 8);
	if (stonesColors == DARKGREEN_LIGHTGREEN)
		_stoneSelectorSprite.setPosition(1110 - 8, 379 - 8);
	if (stonesColors == GREEN_RED)
		_stoneSelectorSprite.setPosition(761 - 8, 379 - 8);
	if (stonesColors == ORANGE_VIOLET)
		_stoneSelectorSprite.setPosition(1041 - 8, 379 - 8);
	if (stonesColors == PINK_FLUOYELLOW)
		_stoneSelectorSprite.setPosition(901 - 8, 379 - 8);
	if (stonesColors == SALMON_CORAL)
		_stoneSelectorSprite.setPosition(831 - 8, 379 - 8);
	if (stonesColors == TURQUOISEGREEN_INDIGO)
		_stoneSelectorSprite.setPosition(1179 - 8, 379 - 8);

	if (boardColor == NOBOARD)
		_boardSelectorSprite.setPosition(-100, -100);
	if (boardColor == AZURE)
		_boardSelectorSprite.setPosition(691 - 8, 776 - 8);
	if (boardColor == BLACK)
		_boardSelectorSprite.setPosition(1179 - 8, 776 - 8);
	if (boardColor == GRAY)
		_boardSelectorSprite.setPosition(1110 - 8, 776 - 8);
	if (boardColor == GREEN)
		_boardSelectorSprite.setPosition(1041 - 8, 776 - 8);
	if (boardColor == ORANGE)
		_boardSelectorSprite.setPosition(901 - 8, 776 - 8);
	if (boardColor == PINK)
		_boardSelectorSprite.setPosition(971 - 8, 776 - 8);
	if (boardColor == RED)
		_boardSelectorSprite.setPosition(831 - 8, 776 - 8);
	if (boardColor == YELLOW)
		_boardSelectorSprite.setPosition(761 - 8, 776 - 8);

	if (playerOneAvatar == NOAVATAR)
		_avatarSelectorSprite.setPosition(-100, -100);
	if (playerOneAvatar == ALEX)
		_avatarSelectorSprite.setPosition(877 - 8, 563 - 8);
	if (playerOneAvatar == GUNTHER)
		_avatarSelectorSprite.setPosition(1154 - 8, 563 - 8);
	if (playerOneAvatar == HERIC)
		_avatarSelectorSprite.setPosition(970 - 8, 563 - 8);
	if (playerOneAvatar == LAURE)
		_avatarSelectorSprite.setPosition(784 - 8, 563 - 8);
	if (playerOneAvatar == MOUSSE)
		_avatarSelectorSprite.setPosition(1063 - 8, 563 - 8);
	if (playerOneAvatar == TOMMY)
		_avatarSelectorSprite.setPosition(691 - 8, 563 - 8);

	handleStonesSelection(window);
	handleAvatarsSelection(window);
	handleBoardSelection(window);

	window.draw(_customMenuSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_stoneSelectorSprite);
	window.draw(_avatarSelectorSprite);
	window.draw(_boardSelectorSprite);

	for (int i = 0; i < 8; i++)
		window.draw(_stonesSprites[i]);

	for (int i = 0; i < 6; i++)
		window.draw(_avatarsSprites[i]);

	for (int i = 0; i < 8; i++)
		window.draw(_boardsSprites[i]);
}

void	CustomMenu::handleKeys(const sf::Event& event, const sf::RenderWindow& window) {
	if (_backwardButtonSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			gameState = MENU;
	} else
		_backwardButtonSprite.setTexture(_backwardButtonTexture);
}

void	CustomMenu::handleStonesSelection(const sf::RenderWindow& window) {
	if (_stonesSprites[BLACK_WHITE].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(691 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = BLACK_WHITE;
	} else if (_stonesSprites[BLACK_YELLOW].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(971 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = BLACK_YELLOW;
	} else if (_stonesSprites[DARKGREEN_LIGHTGREEN].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(1110 - 7, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = DARKGREEN_LIGHTGREEN;
	} else if (_stonesSprites[GREEN_RED].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(761 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = GREEN_RED;
	} else if (_stonesSprites[ORANGE_VIOLET].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(1041 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = ORANGE_VIOLET;
	} else if (_stonesSprites[PINK_FLUOYELLOW].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(901 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = PINK_FLUOYELLOW;
	} else if (_stonesSprites[SALMON_CORAL].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(831 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = SALMON_CORAL;
	} else if (_stonesSprites[TURQUOISEGREEN_INDIGO].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(1179 - 6, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColors = TURQUOISEGREEN_INDIGO;
	} else if (stonesColors == NOSTONESCOLORS)
			_stoneSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleAvatarsSelection(const sf::RenderWindow& window) {
	if (_avatarsSprites[ALEX].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(877 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = ALEX;
	} else if (_avatarsSprites[GUNTHER].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(1154 - 6, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = GUNTHER;
	} else if (_avatarsSprites[HERIC].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(970 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = HERIC;
	} else if (_avatarsSprites[LAURE].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(784 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = LAURE;
	} else if (_avatarsSprites[MOUSSE].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(1063 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = MOUSSE;
	} else if (_avatarsSprites[TOMMY].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(691 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = TOMMY;
	} else if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleBoardSelection(const sf::RenderWindow& window) {
	if (_boardsSprites[AZURE].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(691 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = AZURE;
	} else if (_boardsSprites[BLACK].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1179 - 6, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = BLACK;
	} else if (_boardsSprites[GRAY].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1110 - 7, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GRAY;
	} else if (_boardsSprites[GREEN].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1041 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GREEN;
	} else if (_boardsSprites[ORANGE].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(901 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = ORANGE;
	} else if (_boardsSprites[PINK].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(971 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = PINK;
	} else if (_boardsSprites[RED].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(831 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = RED;
	} else if (_boardsSprites[YELLOW].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(761 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = YELLOW;
	} else if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::init() {
	if (!_customMenuTexture.loadFromFile("assets/images/menu/custom/customMenuTexture.png"))
		std::cerr << "Error: could not load custom page texture" << std::endl;
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/backwardButtonTexture.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/backwardHoveredButtonTexture.png"))
		std::cerr << "Error: could not load return button highlighted texture" << std::endl;
	if (!_colorSelectorTexture.loadFromFile("assets/images/menu/custom/selectors/colorSelectorTexture.png"))
		std::cerr << "Error: could not load selection halo texture" << std::endl;
	if (!_avatarSelectorTexture.loadFromFile("assets/images/menu/custom/selectors/avatarSelectorTexture.png"))
		std::cerr << "Error: could not load avatar selector texture" << std::endl;

	_customMenuSprite.setTexture(_customMenuTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_stoneSelectorSprite.setTexture(_colorSelectorTexture);
	_avatarSelectorSprite.setTexture(_avatarSelectorTexture);
	_boardSelectorSprite.setTexture(_colorSelectorTexture);

	const string stonesColors[] = {"blackWhite", "greenRed", "salmonCoral", "pinkFYellow", "blackYellow", "orangeViolet", "dGreenLGreen", "tGreenIndigo"};
	for (int i = 0; i < 8; i++) {
		sf::Texture texture;
		string		filePath = "assets/images/menu/custom/stones/" + stonesColors[i] + "StoneTexture.png";
		if (texture.loadFromFile(filePath))
			_stonesTextures.push_back(texture);
	}

	for (int i = 0; i < 8; i++) {
		sf::Sprite sprite;
		sprite.setTexture(_stonesTextures[i]);
		_stonesSprites.push_back(sprite);
	}

	const string avatarsNames[] = {"tommy", "laure", "alex", "heric", "mousse", "gunther"};
	for (int i = 0; i < 6; i++) {
		sf::Texture texture;
		string		filePath = "assets/images/menu/custom/avatars/" + avatarsNames[i] + "AvatarTexture.png";
		if (texture.loadFromFile(filePath))
			_avatarsTextures.push_back(texture);
	}

	for (int i = 0; i < 6; i++) {
		sf::Sprite sprite;
		sprite.setTexture(_avatarsTextures[i]);
		_avatarsSprites.push_back(sprite);
	}

	const string boardsColors[] = {"azure", "yellow", "red", "orange", "pink", "green", "gray", "black"};
	for (int i = 0; i < 8; i++) {
		sf::Texture texture;
		string		filePath = "assets/images/menu/custom/boards/" + boardsColors[i] + "BoardTexture.png";
		if (texture.loadFromFile(filePath))
			_boardsTextures.push_back(texture);
	}

	for (int i = 0; i < 8; i++) {
		sf::Sprite sprite;
		sprite.setTexture(_boardsTextures[i]);
		_boardsSprites.push_back(sprite);
	}
	
	_backwardButtonSprite.setPosition(100, 100);

	for (int i = 0; i < 8; i++)
		_stonesSprites[i].setPosition(691 + (i * 70), 379);

	for (int i = 0; i < 6; i++)
		_avatarsSprites[i].setPosition(691 + (i * 93), 563);

	for (int i = 0; i < 8; i++)
		_boardsSprites[i].setPosition(691 + (i * 70), 776);
}

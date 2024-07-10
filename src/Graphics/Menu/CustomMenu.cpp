/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:13 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/10 13:38:53 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomMenu.hpp"

CustomMenu::CustomMenu() {
	init();
}

CustomMenu::~CustomMenu() {}

void	CustomMenu::display(sf::RenderWindow& window) {
	handleStonesSelection(window);
	handleAvatarSelection(window);
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
	if (gameState != CUSTOM)
		return;

	if (_backwardButtonSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			gameState = MENU;
	} else
		_backwardButtonSprite.setTexture(_backwardButtonTexture);
}

void	CustomMenu::handleStonesSelection(const sf::RenderWindow& window) {
	bool			stoneHovered = false;
	StonesColors	stoneColorsArray[8] = {BLACK_WHITE, GREEN_RED, SALMON_CORAL, PINK_FLUOYELLOW, BLACK_YELLOW, ORANGE_VIOLET, DARKGREEN_LIGHTGREEN, TURQUOISEGREEN_INDIGO};
	for (int i = 0; i < 8; i++) {
		if (_stonesSprites[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			stoneHovered = true;
			if (stonesColors == NOSTONESCOLORS)
				_stoneSelectorSprite.setPosition((690 + (i * 70)) - 6, 379 - 7);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				stonesColors = stoneColorsArray[i];
				_stoneSelectorSprite.setPosition((690 + (i * 70)) - 6, 379 - 7);
			}
			break;
		}
	}
	if (!stoneHovered && stonesColors == NOSTONESCOLORS)
		_stoneSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleAvatarSelection(const sf::RenderWindow& window) {
	bool	avatarHovered = false;
	Avatar	avatarsArray[6] = {TOMMY, LAURE, ALEX, HERIC, MOUSSE, GUNTHER};
	for (int i = 0; i < 6; i++) {
		if (_avatarsSprites[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			avatarHovered = true;
			if (playerOneAvatar == NOAVATAR)
				_avatarSelectorSprite.setPosition((690 + (i * 93)) - 6, 563 - 7);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				playerOneAvatar = avatarsArray[i];
				_avatarSelectorSprite.setPosition((690 + (i * 93)) - 6, 563 - 7);
			}
			break;
		}
	}
	if (!avatarHovered && playerOneAvatar == NOAVATAR)
		_avatarSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleBoardSelection(const sf::RenderWindow& window) {
	bool		boardHovered = false;
	BoardColor	boardsColorsArray[8] = {AZURE, YELLOW, RED, ORANGE, PINK, GREEN, GRAY, BLACK};
	for (int i = 0; i < 8; i++) {
		if (_boardsSprites[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			boardHovered = true;
			if (boardColor == NOBOARD)
				_boardSelectorSprite.setPosition((690 + (i * 70)) - 6, 776 - 7);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				boardColor = boardsColorsArray[i];
				_boardSelectorSprite.setPosition((690 + (i * 70)) - 6, 776 - 7);
			}
			break;
		}
	}
	if (!boardHovered && boardColor == NOBOARD)
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

	const std::string stonesColors[] = {"blackWhite", "greenRed", "salmonCoral", "pinkFYellow", "blackYellow", "orangeViolet", "dGreenLGreen", "tGreenIndigo"};
	for (int i = 0; i < 8; i++) {
		sf::Texture	texture;
		std::string	filePath = "assets/images/menu/custom/stones/" + stonesColors[i] + "StoneTexture.png";
		if (texture.loadFromFile(filePath))
			_stonesTextures.push_back(texture);
	}

	for (int i = 0; i < 8; i++) {
		sf::Sprite sprite;
		sprite.setTexture(_stonesTextures[i]);
		_stonesSprites.push_back(sprite);
	}

	const std::string avatarsNames[] = {"tommy", "laure", "alex", "heric", "mousse", "gunther"};
	for (int i = 0; i < 6; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/menu/custom/avatars/" + avatarsNames[i] + "AvatarTexture.png";
		if (texture.loadFromFile(filePath))
			_avatarsTextures.push_back(texture);
	}

	for (int i = 0; i < 6; i++) {
		sf::Sprite sprite;
		sprite.setTexture(_avatarsTextures[i]);
		_avatarsSprites.push_back(sprite);
	}

	const std::string boardsColors[] = {"azure", "yellow", "red", "orange", "pink", "green", "gray", "black"};
	for (int i = 0; i < 8; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/menu/custom/boards/" + boardsColors[i] + "BoardTexture.png";
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

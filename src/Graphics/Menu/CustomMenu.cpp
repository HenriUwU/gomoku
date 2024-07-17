/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:13 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/17 11:28:44 by laprieur         ###   ########.fr       */
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
		_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			gameState = MENU;
	} else
		_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDBUTTON]);
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
	const std::string customMenu[] = {"customMenu"};
	const std::string backwardButton[] = {"backwardButton", "backwardHoveredButton"};
	const std::string selectors[] = {"colorSelector", "avatarSelector"};
	const std::string stonesColors[] = {"blackWhite", "greenRed", "salmonCoral", "pinkFYellow", "blackYellow", "orangeViolet", "dGreenLGreen", "tGreenIndigo"};
	const std::string avatarsNames[] = {"tommy", "laure", "alex", "heric", "mousse", "gunther"};
	const std::string boardsColors[] = {"azure", "yellow", "red", "orange", "pink", "green", "gray", "black"};
	
	loadTextures(1, "assets/images/menu/custom/", customMenu, "Texture.png", _pageTextures);
	loadTextures(2, "assets/images/buttons/", backwardButton, "Texture.png", _pageTextures);
	loadTextures(2, "assets/images/menu/custom/selectors/", selectors, "Texture.png", _pageTextures);
	loadTextures(8, "assets/images/menu/custom/stones/", stonesColors, "StoneTexture.png", _stonesTextures);
	loadTextures(6, "assets/images/menu/custom/avatars/", avatarsNames, "AvatarTexture.png", _avatarsTextures);
	loadTextures(8, "assets/images/menu/custom/boards/", boardsColors, "BoardTexture.png", _boardsTextures);

	_customMenuSprite.setTexture(_pageTextures[T_CUSTOMMENU]);
	_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDBUTTON]);
	_stoneSelectorSprite.setTexture(_pageTextures[T_COLORSELECTOR]);
	_avatarSelectorSprite.setTexture(_pageTextures[T_AVATARSELECTOR]);
	_boardSelectorSprite.setTexture(_pageTextures[T_COLORSELECTOR]);
	
	setTextures(8, _stonesTextures, _stonesSprites);
	setTextures(6, _avatarsTextures, _avatarsSprites);
	setTextures(8, _boardsTextures, _boardsSprites);
	
	_backwardButtonSprite.setPosition(100, 100);

	for (int i = 0; i < 8; i++)
		_stonesSprites[i].setPosition(691 + (i * 70), 379);
	// setPosition(0, 8, _stonesSprites, void*, 691, 379, 70);

	for (int i = 0; i < 6; i++)
		_avatarsSprites[i].setPosition(691 + (i * 93), 563);

	for (int i = 0; i < 8; i++)
		_boardsSprites[i].setPosition(691 + (i * 70), 776);
}

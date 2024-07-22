/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/22 11:57:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelpMenu.hpp"

HelpMenu::HelpMenu() {
	init();
}

HelpMenu::~HelpMenu() {}

void	HelpMenu::display(sf::RenderWindow& window) {
	window.clear(sf::Color(38, 1, 69));

	if (helpMenuState == RULES)
		window.draw(_rulesPageSprite);
	if (helpMenuState == CAPTURES)
		window.draw(_capturesPageSprite);
	if (helpMenuState == DOUBLETHREE)
		window.draw(_doubleThreesPageSprite);

	window.draw(_backwardButtonSprite);
	if (helpMenuState != DOUBLETHREE)
		window.draw(_forwardButtonSprite);
}

void	HelpMenu::handleKeys(const sf::Event& event, const sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	
	if (gameState != HELP)
		return;
	
	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				gameState = MENU;
			else if (helpMenuState == CAPTURES)
				helpMenuState = RULES;
			else if (helpMenuState == DOUBLETHREE)
				helpMenuState = CAPTURES;
		}
	} else if (_forwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_forwardButtonSprite.setTexture(_pageTextures[T_FORWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				helpMenuState = CAPTURES;
			else if (helpMenuState == CAPTURES)
				helpMenuState = DOUBLETHREE;
		}
	} else {
		_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDBUTTON]);
		_forwardButtonSprite.setTexture(_pageTextures[T_FORWARDBUTTON]);
	}
}

void	HelpMenu::init() {	
	const std::string pages[] = {"rulesPage", "capturesPage", "doubleThreesPage"};
	const std::string buttons[] = {"backwardButton", "backwardHoveredButton", "forwardButton", "forwardHoveredButton"};

	loadTextures(3, "assets/images/menu/help/", pages, "Texture.png", _pageTextures);
	loadTextures(4, "assets/images/buttons/", buttons, "Texture.png", _pageTextures);

	_rulesPageSprite.setTexture(_pageTextures[T_RULESPAGE]);
	_capturesPageSprite.setTexture(_pageTextures[T_CAPTURESPAGE]);
	_doubleThreesPageSprite.setTexture(_pageTextures[T_DOUBLETHREESPAGE]);
	_backwardButtonSprite.setTexture(_pageTextures[T_BACKWARDBUTTON]);
	_forwardButtonSprite.setTexture(_pageTextures[T_FORWARDBUTTON]);

	_backwardButtonSprite.setPosition(100, 100);
	_forwardButtonSprite.setPosition(1756, 100);
}

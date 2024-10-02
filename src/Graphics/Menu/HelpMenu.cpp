/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/02 16:55:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Menu/HelpMenu.hpp"

HelpMenu::HelpMenu() {
	init();
}

HelpMenu::~HelpMenu() {}

void	HelpMenu::display(sf::RenderWindow& window) {
	window.clear(sf::Color(38, 1, 69));

	if (helpMenuState == RULES) {
		window.draw(_rulesPageSprite);
		_winGif.update(_winGifSprite);
		window.clear();
		window.draw(_winGifSprite);
	}
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
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				gameState = MENU;
			else if (helpMenuState == CAPTURES)
				helpMenuState = RULES;
			else if (helpMenuState == DOUBLETHREE)
				helpMenuState = CAPTURES;
		}
	} else if (_forwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_forwardButtonSprite.setTexture(_pageTextures[FORWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				helpMenuState = CAPTURES;
			else if (helpMenuState == CAPTURES)
				helpMenuState = DOUBLETHREE;
		}
	} else {
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
		_forwardButtonSprite.setTexture(_pageTextures[FORWARDBUTTON]);
	}
}

void	HelpMenu::init() {	
	const std::string	pages[] = {"rulesPage", "capturesPage", "doubleThreesPage"};
	const std::string	buttons[] = {"backwardButton", "backwardHoveredButton", "forwardButton", "forwardHoveredButton"};

	loadTextures(3, "assets/images/menu/help/", pages, _pageTextures);
	loadTextures(4, "assets/images/buttons/", buttons, _pageTextures);
	
	// _winGif.loadFile("assets/images/menu/help/win.gif");

	_rulesPageSprite.setTexture(_pageTextures[RULESPAGE]);
	_capturesPageSprite.setTexture(_pageTextures[CAPTURESPAGE]);
	_doubleThreesPageSprite.setTexture(_pageTextures[DOUBLETHREESPAGE]);
	_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	_forwardButtonSprite.setTexture(_pageTextures[FORWARDBUTTON]);

	setPosition(_backwardButtonSprite, 100, 100);
	setPosition(_forwardButtonSprite, 1756, 100);
}

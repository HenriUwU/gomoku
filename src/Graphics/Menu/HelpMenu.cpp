/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/03 15:02:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelpMenu.hpp"

HelpMenu::HelpMenu() {
	init();
}

HelpMenu::~HelpMenu() {}

void	HelpMenu::handleKeys(sf::Event &event, sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	
	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				gameState = MENU;
			else if (helpMenuState == CAPTURES)
				helpMenuState = RULES;
			else if (helpMenuState == DOUBLETHREE)
				helpMenuState = CAPTURES;
		}
	} else if (_forwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_forwardButtonSprite.setTexture(_forwardHoveredButtonTexture);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (helpMenuState == RULES)
				helpMenuState = CAPTURES;
			else if (helpMenuState == CAPTURES)
				helpMenuState = DOUBLETHREE;
		}
	} else {
		_backwardButtonSprite.setTexture(_backwardButtonTexture);
		_forwardButtonSprite.setTexture(_forwardButtonTexture);
	}
}

void	HelpMenu::display(sf::RenderWindow &window) {
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

void	HelpMenu::init() {
	if (!_rulesPageTexture.loadFromFile("assets/images/menu/help/rulesPageTexture.png"))
		std::cerr << "Error: could not load rules page texture" << std::endl;
	if (!_capturesPageTexture.loadFromFile("assets/images/menu/help/capturesPageTexture.png"))
		std::cerr << "Error: could not load captures page texture" << std::endl;
	if (!_doubleThreesPageTexture.loadFromFile("assets/images/menu/help/doubleThreesPageTexture.png"))
		std::cerr << "Error: could not load double three page texture" << std::endl;
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/backwardButtonTexture.png"))
		std::cerr << "Error: could not load arrow button texture" << std::endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/backwardHoveredButtonTexture.png"))
		std::cerr << "Error: could not load arrow button highlighted texture" << std::endl;
	if (!_forwardButtonTexture.loadFromFile("assets/images/buttons/forwardButtonTexture.png"))
		std::cerr << "Error: could not load arrow button texture" << std::endl;
	if (!_forwardHoveredButtonTexture.loadFromFile("assets/images/buttons/forwardHoveredButtonTexture.png"))
		std::cerr << "Error: could not load arrow button highlighted texture" << std::endl;

	_rulesPageSprite.setTexture(_rulesPageTexture);
	_capturesPageSprite.setTexture(_capturesPageTexture);
	_doubleThreesPageSprite.setTexture(_doubleThreesPageTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_forwardButtonSprite.setTexture(_forwardButtonTexture);

	_backwardButtonSprite.setPosition(100, 100);
	_forwardButtonSprite.setPosition(1756, 100);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 22:46:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelpMenu.hpp"

HelpMenu::HelpMenu() {
	init();
}

HelpMenu::~HelpMenu() {}

void	HelpMenu::display(sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (_leftArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_leftArrow.setTexture(_leftArrowButtonHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (helpMenuState == RULES)
				gameState = MENU;
			if (helpMenuState == CAPTURES)
				helpMenuState = RULES;
			sf::sleep(sf::milliseconds(100));
			if (helpMenuState == DOUBLETHREE)
				helpMenuState = CAPTURES;
			sf::sleep(sf::milliseconds(100));
		}
	} else if (_rightArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_rightArrow.setTexture(_rightArrowButtonHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (helpMenuState == RULES)
				helpMenuState = CAPTURES;
			sf::sleep(sf::milliseconds(100));
			if (helpMenuState == CAPTURES)
				helpMenuState = DOUBLETHREE;
			sf::sleep(sf::milliseconds(100));
		}
	} else {
		_leftArrow.setTexture(_leftArrowButtonTexture);
		_rightArrow.setTexture(_rightArrowButtonTexture);
	}

	window.clear(sf::Color(38, 1, 69));

	if (helpMenuState == RULES)
		window.draw(_rulesPage);
	if (helpMenuState == CAPTURES)
		window.draw(_capturesPage);
	if (helpMenuState == DOUBLETHREE)
		window.draw(_doubleThreePage);

	window.draw(_leftArrow);
	if (helpMenuState != DOUBLETHREE)
		window.draw(_rightArrow);
}

void	HelpMenu::init() {
	if (!_rulesPageTexture.loadFromFile("assets/helpMenu/Rules_Gomoku.png"))
		std::cerr << "Error: could not load rules page texture" << std::endl;
	if (!_capturesPageTexture.loadFromFile("assets/helpMenu/Captures_Gomoku.png"))
		std::cerr << "Error: could not load captures page texture" << std::endl;
	if (!_doubleThreePageTexture.loadFromFile("assets/helpMenu/Double-threes.png"))
		std::cerr << "Error: could not load double three page texture" << std::endl;
	if (!_leftArrowButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load arrow button texture" << std::endl;
	if (!_leftArrowButtonHighlightedTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load arrow button highlighted texture" << std::endl;
	if (!_rightArrowButtonTexture.loadFromFile("assets/images/buttons/right_arrow.png"))
		std::cerr << "Error: could not load arrow button texture" << std::endl;
	if (!_rightArrowButtonHighlightedTexture.loadFromFile("assets/images/buttons/right_arrow_highlighted.png"))
		std::cerr << "Error: could not load arrow button highlighted texture" << std::endl;

	_rulesPage.setTexture(_rulesPageTexture);
	_capturesPage.setTexture(_capturesPageTexture);
	_doubleThreePage.setTexture(_doubleThreePageTexture);
	_leftArrow.setTexture(_leftArrowButtonTexture);
	_rightArrow.setTexture(_rightArrowButtonTexture);

	_leftArrow.setPosition(100, 100);
	_rightArrow.setPosition(1756, 100);
}

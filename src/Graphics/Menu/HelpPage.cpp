/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpPage.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 18:15:36 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HelpPage.hpp"

HelpPage::HelpPage() {
	helpPageInit();
}

HelpPage::~HelpPage() {}

void	HelpPage::display(sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (_leftArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_leftArrow.setTexture(_arrowButtonHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && helpPageState == RULES) {
			gameState = MENU;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && helpPageState == CAPTURES) {
			helpPageState = RULES;
			sf::sleep(sf::milliseconds(200));
		}
	}
	else if (_rightArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_rightArrow.setTexture(_arrowButtonHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (helpPageState == RULES)
				helpPageState = CAPTURES;
		}
	}
	else {
		_leftArrow.setTexture(_arrowButtonTexture);
		_rightArrow.setTexture(_arrowButtonTexture);
	}

	window.clear(sf::Color(38, 1, 69));

	if (helpPageState == RULES)
		window.draw(_rulesPage);
	if (helpPageState == CAPTURES)
		window.draw(_capturesPage);

	window.draw(_leftArrow);
	window.draw(_rightArrow);
}

void	HelpPage::helpPageInit() {
	if (!_rulesPageTexture.loadFromFile("assets/helpPages/Rules_Gomoku.png"))
		std::cerr << "Error: could not load rules page texture" << std::endl;
	if (!_capturesPageTexture.loadFromFile("assets/helpPages/Capture_Gomoku.png"))
		std::cerr << "Error: could not load captures page texture" << std::endl;
	if (!_arrowButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load arrow button texture" << std::endl;
	if (!_arrowButtonHighlightedTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load arrow button highlighted texture" << std::endl;

	_rulesPage.setTexture(_rulesPageTexture);
	_capturesPage.setTexture(_capturesPageTexture);
	_leftArrow.setTexture(_arrowButtonTexture);
	_rightArrow.setTexture(_arrowButtonTexture);

	_rightArrow.setRotation(180);
	_leftArrow.setPosition(34, 34);
	_rightArrow.setPosition(1886, 930);
}
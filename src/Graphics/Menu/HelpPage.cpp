/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpPage.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/14 15:00:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

static void	helpPageOne(sf::Font _exo2BlackFont, sf::Font _ex02BlackItalicFont, sf::RenderWindow &window) {
	sf::Text	rules;
	sf::Text	gobanSizeExplanation;
	sf::Text	howToPlay;
	sf::Text	howToPlayExplanation;
	sf::Text	nextPage;
	sf::Text	backToMenu;

	rules.setString("Rules");
	gobanSizeExplanation.setString("The game is played on a 19x19 goban, and there is no limit to the number of stone.");
	howToPlay.setString("That's nice. But how do you play the game?");
	howToPlayExplanation.setString("Two players take turns placing stones of their\ncolor on an intersection of the board,\nand the game ends when one player manages\nto align five stones (there's actually a rule that\nyou'll see a bit further that can override this one).");
	nextPage.setString("Next page");
	backToMenu.setString("Back to menu");
	
	rules.setFont(_exo2BlackFont);
	gobanSizeExplanation.setFont(_ex02BlackItalicFont);
	howToPlay.setFont(_exo2BlackFont);
	howToPlayExplanation.setFont(_ex02BlackItalicFont);
	nextPage.setFont(_ex02BlackItalicFont);
	backToMenu.setFont(_ex02BlackItalicFont);

	rules.setCharacterSize(125);
	gobanSizeExplanation.setCharacterSize(35);
	howToPlay.setCharacterSize(35);
	howToPlayExplanation.setCharacterSize(35);
	nextPage.setCharacterSize(20);
	backToMenu.setCharacterSize(20);
	
	rules.setFillColor(sf::Color(193, 167, 252));
	gobanSizeExplanation.setFillColor(sf::Color::White);
	howToPlay.setFillColor(sf::Color(193, 167, 252));
	howToPlayExplanation.setFillColor(sf::Color::White);
	nextPage.setFillColor(sf::Color::White);
	backToMenu.setFillColor(sf::Color::White);
	
	rules.setPosition(789, 30);
	gobanSizeExplanation.setPosition(54, 219);
	howToPlay.setPosition(54, 400);
	howToPlayExplanation.setPosition(54, 474);
	nextPage.setPosition(1685, 855);
	backToMenu.setPosition(135, 75);

	window.draw(rules);
	window.draw(gobanSizeExplanation);
	window.draw(howToPlay);
	window.draw(howToPlayExplanation);
	window.draw(nextPage);
	window.draw(backToMenu);
}

void	MainMenu::helpPage(sf::RenderWindow &window) {
	int	page = 1;

	_leftArrowIconSprite.setTexture(_arrowIconTexture);
	_rightArrowIconSprite.setTexture(_arrowIconTexture);
	_rightArrowIconSprite.setRotation(180);
	_leftArrowIconSprite.setPosition(54, 54);
	_rightArrowIconSprite.setPosition(1866, 900);
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	window.clear(sf::Color(38, 1, 69));

	if (_leftArrowIconSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_leftArrowIconSprite.setTexture(_arrowIconHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = MENU;
		}
	}
	else if (_rightArrowIconSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_rightArrowIconSprite.setTexture(_arrowIconHighlightedTexture);
	}
	else {
		_leftArrowIconSprite.setTexture(_arrowIconTexture);
		_rightArrowIconSprite.setTexture(_arrowIconTexture);
	}

	if (page == 1)
		helpPageOne(_exo2BlackFont, _ex02BlackItalicFont, window);

	window.draw(_leftArrowIconSprite);
	window.draw(_rightArrowIconSprite);
}
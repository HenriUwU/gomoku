/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpPage.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:55 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/13 15:33:33 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

static void	helpPageOne(sf::Font _gomokuFont, sf::Font _menuFont, sf::RenderWindow &window) {
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
	
	rules.setFont(_gomokuFont);
	gobanSizeExplanation.setFont(_menuFont);
	howToPlay.setFont(_gomokuFont);
	howToPlayExplanation.setFont(_menuFont);
	nextPage.setFont(_menuFont);
	backToMenu.setFont(_menuFont);

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

	_returnArrow.setTexture(_arrowTexture);
	_nextPageArrow.setTexture(_arrowTexture);
	_nextPageArrow.setRotation(180);
	_returnArrow.setPosition(54, 54);
	_nextPageArrow.setPosition(1866, 900);
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	window.clear(sf::Color(38, 1, 69));
	if (_returnArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_returnArrow.setTexture(_arrowTextureHighlighted);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			displayHelp = false;
			displayMenu = true;
		}
	}
	else if (_nextPageArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_nextPageArrow.setTexture(_arrowTextureHighlighted);
	}
	else {
		_returnArrow.setTexture(_arrowTexture);
		_nextPageArrow.setTexture(_arrowTexture);
	}

	if (page == 1)
		helpPageOne(_gomokuFont, _menuFont, window);

	window.draw(_returnArrow);
	window.draw(_nextPageArrow);
}
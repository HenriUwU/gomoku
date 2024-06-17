/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:51:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 16:57:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

GameState		gameState = MENU;
BoardColor		boardColor = NOBOARD;
Avatar			playerOneAvatar = NOAVATAR;
Avatar			playerTwoAvatar = NOAVATAR;
StonesColors	stonesColor = NOSTONECOLOR;
GameMode		gameMode = NOGAMEMODE;
AIMode			aiMode = NOAIMODE;

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gomoku");
	MainMenu mainMenu;
	CustomPage customPage;
	Gameplay gameplay(window);
	Goban goban(window);
	sf::Texture cursorTexture;
	sf::Sprite cursor;

	if (!cursorTexture.loadFromFile("assets/images/icons/cursor.png")) {
		std::cerr << "Error: could not load cursor texture" << std::endl;
		return 1;
	}

	cursor.setTexture(cursorTexture);
	window.setMouseCursorVisible(false);

	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event)) {
			mainMenu.handleKeys(event, window);
			gameplay.handleKeys(event, window);
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
				window.close();
		}   
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		cursor.setPosition(mousePos.x, mousePos.y);
		switch (gameState) {
			case MENU:
				mainMenu.display(window);
				break;
			case GAME:
				goban.display(event, window);
				gameplay.mouseHover(window);
				break;
			case CUSTOM:
				customPage.display(window);
				break;
			case SETTINGS:
				mainMenu.settingsPage(window);
				break;
			case HELP:
				mainMenu.helpPage(window);
				break;
			default:
				break;
		}
		window.draw(cursor);
		window.display();
	}
}

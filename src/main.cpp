/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:51:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/14 14:57:45 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

GameState	gameState = MENU;

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gomoku");
	MainMenu mainMenu(window.getSize().x, window.getSize().y, window);
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
			case HELP:
				mainMenu.helpPage(window);
				break;
			case SETTINGS:
				mainMenu.settingsPage(window);
				break;
			default:
				break;
		}
/* 		if (gameState == MENU) {
			mainMenu.display(window);
		}
		else if (gameState == GAME) {
			goban.display(event, window);
			gameplay.mouseHover(window);
		}
		else if (gameState == HELP) {
			mainMenu.helpPage(window);
		}
		else if (gameState == SETTINGS) {
			mainMenu.settingsPage(window);
		} */
		window.draw(cursor);
		window.display();
	}
}

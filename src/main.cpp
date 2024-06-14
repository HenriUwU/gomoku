/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:51:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/14 11:53:20 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

bool displayMenu = true;
bool displayGame = false;
bool displayHelp = false;

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
		sf::Event event;
		while (window.pollEvent(event)) {
			mainMenu.handleKeys(event, window);
			gameplay.handleKeys(event, window);
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
				window.close();
		}   
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		cursor.setPosition(mousePos.x, mousePos.y);
		if (displayMenu == true) {
			mainMenu.display(window);
		}
		else if (displayGame == true) {
			goban.display(event, window);
			gameplay.mouseHover(window, event);
		}
		else if (displayHelp == true) {
			mainMenu.helpPage(window);
		}
		window.draw(cursor);
		window.display();
	}
}

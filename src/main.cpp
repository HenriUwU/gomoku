/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:37 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 16:39:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

int										musicVolume				= 100;
int										playersCaptures[2]		= {0, 0};
bool									aiPlaying				= false;
bool									isStonePlaceable		= false;
bool									startTimer				= false;
bool									moveSuggestionEnabled   = true;
AIMode									aiMode					= NOAIMODE;
Avatar									playerOneAvatar			= NOAVATAR;
GameState								gameState				= MENU;
BoardColor								boardColor				= NOBOARD;
EndGameState							endGameState			= NOVICTORY;
StonesColors							stonesColors			= NOSTONESCOLORS;
HelpMenuState							helpMenuState			= RULES;
ForbiddenMoves							forbiddenMoves			= NOFORBIDDENMOVE;
std::chrono::steady_clock::time_point	gameStartTime;

int main() {
	sf::RenderWindow	window(sf::VideoMode(1920, 1080), "Gomoku");
	sf::Texture			cursorTexture;
	sf::Sprite			cursorSprite;
	MainMenu			mainMenu;
	CustomMenu			customMenu;
	SettingsMenu		settingsMenu;
	HelpMenu			helpMenu;
	Music				music;
	Gameplay			gameplay;
	Bitboard			bitboard;

	if (!cursorTexture.loadFromFile("assets/images/icons/cursor.png")) {
		std::cerr << "Error: could not load cursor texture." << std::endl;
		return 1;
	}

	cursorSprite.setTexture(cursorTexture);
	window.setMouseCursorVisible(false);
	sf::Event event;
	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			if ((gameState == GAME || gameState == AIVERSUS) && isStonePlaceable && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
				isStonePlaceable = false;
			mainMenu.handleKeys(event, window);
			customMenu.handleKeys(event, window);
			settingsMenu.handleKeys(event, window);
			settingsMenu.handleVolume(event, window, music);
			helpMenu.handleKeys(event, window);
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
				window.close();
		}   
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		cursorSprite.setPosition(mousePos.x, mousePos.y);
		music.playMusic();
		switch (gameState) {
			case MENU:
				startTimer = false;
				mainMenu.display(window);
				break;
			case GAME:
				if (!startTimer) {
					startTimer = true;
					gameStartTime = std::chrono::steady_clock::now();
				}
				gameplay.display(event, window, bitboard);
				if (forbiddenMoves == NOFORBIDDENMOVE && endGameState == NOVICTORY && endGameState != SEEGAMESTATE)
					gameplay.mouseHover(window, bitboard);
				break; 
			case AIVERSUS:
				if (!startTimer) {
					startTimer = true;
					gameStartTime = std::chrono::steady_clock::now();
				}
				gameplay.display(event, window, bitboard);
				if (forbiddenMoves == NOFORBIDDENMOVE && endGameState == NOVICTORY && endGameState != SEEGAMESTATE)
					gameplay.mouseHover(window, bitboard);
				break;
			case CUSTOM:
				customMenu.display(window);
				break;
			case SETTINGS:
				settingsMenu.display(window);
				break;
			case HELP:
				helpMenu.display(window);
				break;
			default:
				break;				
		}
		window.draw(cursorSprite);
		window.display();
	}
}

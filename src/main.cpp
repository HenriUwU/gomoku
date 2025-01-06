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
bool									startTimer				= false;
bool									moveSuggestionEnabled   = true;
AIMode									aiMode					= IMPOSSIBLE;
Avatar									playerOneAvatar			= NOAVATAR;
GameState								gameState				= MENU;
BoardColor								boardColor				= NOBOARD;
EndGameState							endGameState			= NOVICTORY;
StonesColors							stonesColors			= NOSTONESCOLORS;
HelpMenuState							helpMenuState			= RULES;
ForbiddenMoves							forbiddenMoves			= NOFORBIDDENMOVE;
std::chrono::steady_clock::time_point	gameStartTime;
std::chrono::steady_clock::time_point	gameEndTime;

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
	AI					ai;

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
			mainMenu.handleKeys(event, window);
			customMenu.handleKeys(event, window);
			settingsMenu.handleKeys(event, window);
			settingsMenu.handleVolume(event, window, music);
			helpMenu.handleKeys(event, window);
			if ((event.type == sf::Event::Closed && !aiPlaying) || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape && !aiPlaying)) {
				gameplay.setClosingApp(true);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				window.close();
			}
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
					gameplay.play(window, bitboard, ai);
				break; 
			case AIVERSUS:
				if (!startTimer) {
					startTimer = true;
					gameStartTime = std::chrono::steady_clock::now();
				}
				gameplay.display(event, window, bitboard);
				if (forbiddenMoves == NOFORBIDDENMOVE && endGameState == NOVICTORY && endGameState != SEEGAMESTATE)
					gameplay.play(window, bitboard, ai);
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

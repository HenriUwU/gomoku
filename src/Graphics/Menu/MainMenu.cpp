/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:08 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/24 11:45:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu() {
	init();
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow& window) {
	window.draw(_mainMenuSprite);
	window.draw(_greenButtonSprite);
	window.draw(_orangeButtonSprite);
	window.draw(_redButtonSprite);
	window.draw(_blueButtonCustomSprite);
	window.draw(_blueButtonSettingsSprite);
	window.draw(_blueButtonHelpSprite);
}

void	MainMenu::moveUp() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 5;
		_greenButtonSprite.setTexture(_buttonsTextures[H_1VS1]);
	}
	if (_selectedItemIndex - 1 >= 5 && _selectedItemIndex <= 7) {
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_buttonsTextures[B_AIVERSUS]);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_buttonsTextures[B_EXIT]);
		_selectedItemIndex--;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_buttonsTextures[H_AIVERSUS]);
		else if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_buttonsTextures[H_1VS1]);
	}
	if (_selectedItemIndex > 7 && _selectedItemIndex < 11) {
		if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_buttonsTextures[B_CUSTOM]);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_buttonsTextures[B_SETTINGS]);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_buttonsTextures[B_HELP]);
		_selectedItemIndex = 7;
		_redButtonSprite.setTexture(_buttonsTextures[H_EXIT]);
	}
}

void	MainMenu::moveDown() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 4;	
		_greenButtonSprite.setTexture(_buttonsTextures[H_1VS1]);
	}
	if (_selectedItemIndex + 1 <= 7) {
		if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_buttonsTextures[B_1VS1]);
		else  if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_buttonsTextures[B_AIVERSUS]);
		_selectedItemIndex++;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_buttonsTextures[H_AIVERSUS]);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_buttonsTextures[H_EXIT]);
	} else if (_selectedItemIndex == 7) {
		_redButtonSprite.setTexture(_buttonsTextures[B_EXIT]);
		_blueButtonCustomSprite.setTexture(_buttonsTextures[H_CUSTOM]);
		_selectedItemIndex++;
	}
}

void	MainMenu::moveLeft() {
	if (_selectedItemIndex > 8) {
		if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_buttonsTextures[B_HELP]);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_buttonsTextures[B_SETTINGS]);
		_selectedItemIndex--;
		if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_buttonsTextures[H_SETTINGS]);
		else if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_buttonsTextures[H_CUSTOM]);
	}
}

void	MainMenu::moveRight() {
	if (_selectedItemIndex < 10 && _selectedItemIndex > 7) {
		if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_buttonsTextures[B_CUSTOM]);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_buttonsTextures[B_SETTINGS]);
		_selectedItemIndex++;
		if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_buttonsTextures[H_SETTINGS]);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_buttonsTextures[H_HELP]);
	}
}

void	MainMenu::handleKeys(const sf::Event& event, sf::RenderWindow& window) {
	if (gameState == MENU) {
		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			handleMouseMovement(mousePos);
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up)
				moveUp();
			if (event.key.code == sf::Keyboard::Down)
				moveDown();
			if (event.key.code == sf::Keyboard::Left)
				moveLeft();
			if (event.key.code == sf::Keyboard::Right)
				moveRight();
		}
		if ((getSelectedItemIndex() == 5 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 5 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = GAME;
			_selectedItemIndex = -1;
		}
		if ((getSelectedItemIndex() == 6 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 6 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = AIVERSUS;
			_selectedItemIndex = -1;		
		}
		if ((getSelectedItemIndex() == 7 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 7 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
			window.close();
		if ((getSelectedItemIndex() == 8 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 8 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = CUSTOM;
			_selectedItemIndex = -1;
		}
		if ((getSelectedItemIndex() == 9 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 9 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = SETTINGS;
			_selectedItemIndex = -1;
		}
		if ((getSelectedItemIndex() == 10 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 10 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = HELP;
			_selectedItemIndex = -1;
		}
	}
}

void	MainMenu::handleMouseMovement(const sf::Vector2i& mousePos) {
 	if (_greenButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_greenButtonSprite.setTexture(_buttonsTextures[H_1VS1]);
		_selectedItemIndex = 5;
	} else if (_orangeButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_orangeButtonSprite.setTexture(_buttonsTextures[H_AIVERSUS]);
		_selectedItemIndex = 6;
	} else if (_redButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_redButtonSprite.setTexture(_buttonsTextures[H_EXIT]);
		_selectedItemIndex = 7;
	} else if (_blueButtonCustomSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonCustomSprite.setTexture(_buttonsTextures[H_CUSTOM]);
		_selectedItemIndex = 8;
	} else if (_blueButtonSettingsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonSettingsSprite.setTexture(_buttonsTextures[H_SETTINGS]);
		_selectedItemIndex = 9;
	} else if (_blueButtonHelpSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonHelpSprite.setTexture(_buttonsTextures[H_HELP]);
		_selectedItemIndex = 10;
	} else {
		_greenButtonSprite.setTexture(_buttonsTextures[B_1VS1]);
		_orangeButtonSprite.setTexture(_buttonsTextures[B_AIVERSUS]);
		_redButtonSprite.setTexture(_buttonsTextures[B_EXIT]);
		_blueButtonCustomSprite.setTexture(_buttonsTextures[B_CUSTOM]);
		_blueButtonSettingsSprite.setTexture(_buttonsTextures[B_SETTINGS]);
		_blueButtonHelpSprite.setTexture(_buttonsTextures[B_HELP]);
		_selectedItemIndex = -1;
	}
}

void	MainMenu::init() {
	if (!_mainMenuTexture.loadFromFile("assets/images/menu/main/mainMenuTexture.png"))
		cerr << "Error while loading the 'mainMenuTexture.png' file." << endl;

	const string buttonsColors[] = {"green", "orange", "red", "blueCustom", "blueSettings", "blueHelp"};
	for (int i = 0; i < 6; i++) {
		sf::Texture basicTexture, hoverTexture;
		string		basicPath = "assets/images/menu/main/buttons/" + buttonsColors[i] + "ButtonTexture.png";
		string		hoverPath = "assets/images/menu/main/buttons/" + buttonsColors[i] + "HoveredButtonTexture.png";
		if (basicTexture.loadFromFile(basicPath) && hoverTexture.loadFromFile(hoverPath)) {
			_buttonsTextures.push_back(basicTexture);
			_buttonsTextures.push_back(hoverTexture);
		}
	}

	_mainMenuSprite.setTexture(_mainMenuTexture);
	_greenButtonSprite.setTexture(_buttonsTextures[B_1VS1]);
	_orangeButtonSprite.setTexture(_buttonsTextures[B_AIVERSUS]);
	_redButtonSprite.setTexture(_buttonsTextures[B_EXIT]);
	_blueButtonCustomSprite.setTexture(_buttonsTextures[B_CUSTOM]);
	_blueButtonSettingsSprite.setTexture(_buttonsTextures[B_SETTINGS]);
	_blueButtonHelpSprite.setTexture(_buttonsTextures[B_HELP]);

	_greenButtonSprite.setPosition(684, 299);
	_orangeButtonSprite.setPosition(684, 425);
	_redButtonSprite.setPosition(684, 551);
	_blueButtonCustomSprite.setPosition(684, 737);
	_blueButtonSettingsSprite.setPosition(902, 737);
	_blueButtonHelpSprite.setPosition(1120, 737);

	_selectedItemIndex = 5;
}

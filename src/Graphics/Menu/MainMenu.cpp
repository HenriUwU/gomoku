/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:08 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/18 14:47:52 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

using namespace std;

MainMenu::MainMenu() {
	mainMenuInit();
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow& window) {
	sf::RectangleShape leftLine(sf::Vector2f(150, 5));
	sf::RectangleShape rightLine(sf::Vector2f(150, 5));
	leftLine.setPosition(685, 705);
	rightLine.setPosition(1085, 705);

	window.clear(sf::Color(38, 1, 69));
	window.draw(_greenButtonSprite);
	window.draw(_orangeButtonSprite);
	window.draw(_redButtonSprite);
	window.draw(_blueButtonCustomSprite);
	window.draw(_blueButtonSettingsSprite);
	window.draw(_blueButtonHelpSprite);
	window.draw(leftLine);
	window.draw(rightLine);
	window.draw(_customIconSprite);
	window.draw(_settingsIconSprite);
	window.draw(_helpIconSprite);
	
	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		window.draw(_menuText[i]);
	}
}

void	MainMenu::MoveUp() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 5;
		_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
	}
	if (_selectedItemIndex - 1 >= 5 && _selectedItemIndex <= 7) {
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonTexture);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_redButtonTexture);
		_selectedItemIndex--;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonHighlightedTexture);
		else if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
	}
	if (_selectedItemIndex > 7 && _selectedItemIndex < 11) {
		if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex = 7;
		_redButtonSprite.setTexture(_redButtonHighlightedTexture);
	}
}

void	MainMenu::MoveDown() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 4;	
		_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
	}
	if (_selectedItemIndex + 1 <= 7) {
		if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_greenButtonTexture);
		else  if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonTexture);
		_selectedItemIndex++;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonHighlightedTexture);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_redButtonHighlightedTexture);
	}
	else if (_selectedItemIndex == 7) {
		_redButtonSprite.setTexture(_redButtonTexture);
		_blueButtonCustomSprite.setTexture(_blueButtonHighlightedTexture);
		_selectedItemIndex++;
	}
}

void	MainMenu::MoveLeft() {
	if (_selectedItemIndex > 8) {
		if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex--;
		if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonHighlightedTexture);
		else if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_blueButtonHighlightedTexture);
	}
}

void	MainMenu::MoveRight() {
	if (_selectedItemIndex < 10 && _selectedItemIndex > 7) {
		if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex++;
		if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonHighlightedTexture);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_blueButtonHighlightedTexture);
	}
}

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window) {
	if (gameState == MENU) {
		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			handleMouseMovement(mousePos);
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up)
				MoveUp();
			if (event.key.code == sf::Keyboard::Down)
				MoveDown();
			if (event.key.code == sf::Keyboard::Left)
				MoveLeft();
			if (event.key.code == sf::Keyboard::Right)
				MoveRight();
		}
		if ((getSelectedItemIndex() == 5 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 5 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = GAME;
			_selectedItemIndex = -1;
		}
		if ((getSelectedItemIndex() == 6 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			|| (getSelectedItemIndex() == 6 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
			gameState = VS_IA;
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

void MainMenu::handleMouseMovement(sf::Vector2i mousePos) {
 	if (_greenButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
		_selectedItemIndex = 5;
	}
	else if (_orangeButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_orangeButtonSprite.setTexture(_orangeButtonHighlightedTexture);
		_selectedItemIndex = 6;
	}
	else if (_redButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_redButtonSprite.setTexture(_redButtonHighlightedTexture);
		_selectedItemIndex = 7;
	}
	else if (_blueButtonCustomSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonCustomSprite.setTexture(_blueButtonHighlightedTexture);
		_selectedItemIndex = 8;
	}
	else if (_blueButtonSettingsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonSettingsSprite.setTexture(_blueButtonHighlightedTexture);
		_selectedItemIndex = 9;
	}
	else if (_blueButtonHelpSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonHelpSprite.setTexture(_blueButtonHighlightedTexture);
		_selectedItemIndex = 10;
	}
	else {
		_greenButtonSprite.setTexture(_greenButtonTexture);
		_orangeButtonSprite.setTexture(_orangeButtonTexture);
		_redButtonSprite.setTexture(_redButtonTexture);
		_blueButtonCustomSprite.setTexture(_blueButtonTexture);
		_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		_blueButtonHelpSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex = -1;
	}
}
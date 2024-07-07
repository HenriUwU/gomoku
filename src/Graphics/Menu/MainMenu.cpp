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

using namespace std;

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
	window.draw(_customIconSprite);
	window.draw(_settingsIconSprite);
	window.draw(_helpIconSprite);
	
	for (int i = 0; i < NB_MENU_ITEMS; i++)
		window.draw(_menuText[i]);
}

void	MainMenu::MoveUp() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 5;
		_greenButtonSprite.setTexture(_greenHoveredButtonTexture);
	}
	if (_selectedItemIndex - 1 >= 5 && _selectedItemIndex <= 7) {
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonTexture);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_redButtonTexture);
		_selectedItemIndex--;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeHoveredButtonTexture);
		else if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_greenHoveredButtonTexture);
	}
	if (_selectedItemIndex > 7 && _selectedItemIndex < 11) {
		if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 9)
			_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex = 7;
		_redButtonSprite.setTexture(_redHoveredButtonTexture);
	}
}

void	MainMenu::MoveDown() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 4;	
		_greenButtonSprite.setTexture(_greenHoveredButtonTexture);
	}
	if (_selectedItemIndex + 1 <= 7) {
		if (_selectedItemIndex == 5)
			_greenButtonSprite.setTexture(_greenButtonTexture);
		else  if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeButtonTexture);
		_selectedItemIndex++;
		if (_selectedItemIndex == 6)
			_orangeButtonSprite.setTexture(_orangeHoveredButtonTexture);
		else if (_selectedItemIndex == 7)
			_redButtonSprite.setTexture(_redHoveredButtonTexture);
	} else if (_selectedItemIndex == 7) {
		_redButtonSprite.setTexture(_redButtonTexture);
		_blueButtonCustomSprite.setTexture(_blueHoveredButtonTexture);
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
			_blueButtonSettingsSprite.setTexture(_blueHoveredButtonTexture);
		else if (_selectedItemIndex == 8)
			_blueButtonCustomSprite.setTexture(_blueHoveredButtonTexture);
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
			_blueButtonSettingsSprite.setTexture(_blueHoveredButtonTexture);
		else if (_selectedItemIndex == 10)
			_blueButtonHelpSprite.setTexture(_blueHoveredButtonTexture);
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
		_greenButtonSprite.setTexture(_greenHoveredButtonTexture);
		_selectedItemIndex = 5;
	} else if (_orangeButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_orangeButtonSprite.setTexture(_orangeHoveredButtonTexture);
		_selectedItemIndex = 6;
	} else if (_redButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_redButtonSprite.setTexture(_redHoveredButtonTexture);
		_selectedItemIndex = 7;
	} else if (_blueButtonCustomSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonCustomSprite.setTexture(_blueHoveredButtonTexture);
		_selectedItemIndex = 8;
	} else if (_blueButtonSettingsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonSettingsSprite.setTexture(_blueHoveredButtonTexture);
		_selectedItemIndex = 9;
	} else if (_blueButtonHelpSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_blueButtonHelpSprite.setTexture(_blueHoveredButtonTexture);
		_selectedItemIndex = 10;
	} else {
		_greenButtonSprite.setTexture(_greenButtonTexture);
		_orangeButtonSprite.setTexture(_orangeButtonTexture);
		_redButtonSprite.setTexture(_redButtonTexture);
		_blueButtonCustomSprite.setTexture(_blueButtonTexture);
		_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
		_blueButtonHelpSprite.setTexture(_blueButtonTexture);
		_selectedItemIndex = -1;
	}
}

void	MainMenu::init() {
	if (!_ex02BlackItalicFont.loadFromFile("assets/fonts/Exo_2/Exo2-BlackItalic.ttf"))
		cerr << "Error while loading the 'Exo2-BlackItalic.ttf' file." << endl;
	if (!_mainMenuTexture.loadFromFile("assets/images/menu/main/mainMenuTexture.png"))
		cerr << "Error while loading the 'mainMenuTexture.png' file." << endl;
	if (!_greenButtonTexture.loadFromFile("assets/images/menu/main/buttons/greenButtonTexture.png"))
		cerr << "Error while loading the 'greenButtonTexture.png' file." << endl;
	if (!_orangeButtonTexture.loadFromFile("assets/images/menu/main/buttons/orangeButtonTexture.png"))
		cerr << "Error while loading the 'orangeButtonTexture.png' file." << endl;
	if (!_redButtonTexture.loadFromFile("assets/images/menu/main/buttons/redButtonTexture.png"))
		cerr << "Error while loading the 'redButtonTexture.png' file." << endl;
	if (!_blueButtonTexture.loadFromFile("assets/images/menu/main/buttons/blueButtonTexture.png"))
		cerr << "Error while loading the 'blueButtonTexture.png' file." << endl;
	if (!_greenHoveredButtonTexture.loadFromFile("assets/images/menu/main/buttons/greenHoveredButtonTexture.png"))
		cerr << "Error while loading the 'greenHoveredButtonTexture.png' file." << endl;
	if (!_orangeHoveredButtonTexture.loadFromFile("assets/images/menu/main/buttons/orangeHoveredButtonTexture.png"))
		cerr << "Error while loading the 'orangeHoveredButtonTexture.png' file." << endl;
	if (!_redHoveredButtonTexture.loadFromFile("assets/images/menu/main/buttons/redHoveredButtonTexture.png"))
		cerr << "Error while loading the 'redHoveredButtonTexture.png' file." << endl;
	if (!_blueHoveredButtonTexture.loadFromFile("assets/images/menu/main/buttons/blueHoveredButtonTexture.png"))
		cerr << "Error while loading the 'blueHoveredButtonTexture.png' file." << endl;
	if (!_customIconTexture.loadFromFile("assets/images/menu/main//icons/customIconTexture.png"))
		cerr << "Error while loading the 'custom.png' file." << endl;
	if (!_settingsIconTexture.loadFromFile("assets/images/menu/main//icons/settingsIconTexture.png"))
		cerr << "Error while loading the 'settings.png' file." << endl;
	if (!_helpIconTexture.loadFromFile("assets/images/menu/main/icons/helpIconTexture.png"))
		cerr << "Error while loading the 'help.png' file." << endl;

	_mainMenuSprite.setTexture(_mainMenuTexture);
	_greenButtonSprite.setTexture(_greenButtonTexture);
	_orangeButtonSprite.setTexture(_orangeButtonTexture);
	_redButtonSprite.setTexture(_redButtonTexture);
	_blueButtonCustomSprite.setTexture(_blueButtonTexture);
	_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
	_blueButtonHelpSprite.setTexture(_blueButtonTexture);
	_customIconSprite.setTexture(_customIconTexture);
	_settingsIconSprite.setTexture(_settingsIconTexture);
	_helpIconSprite.setTexture(_helpIconTexture);

	_greenButtonSprite.setPosition(683.64, 297.95);
	_orangeButtonSprite.setPosition(683.64, 430.09);
	_redButtonSprite.setPosition(683.64, 559.64);
	_blueButtonCustomSprite.setPosition(683.64, 755.45);
	_blueButtonSettingsSprite.setPosition(901.27, 755.45);
	_blueButtonHelpSprite.setPosition(1119.77, 755.45);
	_customIconSprite.setPosition(695, 766);
	_settingsIconSprite.setPosition(913, 766);
	_helpIconSprite.setPosition(1131, 766);

	_menuText[0].setString("1 VS 1");
	_menuText[0].setCharacterSize(64.77);
	_menuText[0].setFont(_ex02BlackItalicFont);
	_menuText[0].setFillColor(sf::Color::White);
	_menuText[0].setPosition(877, 298);

	_menuText[1].setString("AI VERSUS");
	_menuText[1].setCharacterSize(64.77);
	_menuText[1].setFont(_ex02BlackItalicFont);
	_menuText[1].setFillColor(sf::Color::White);
	_menuText[1].setPosition(795, 430);

	_menuText[2].setString("EXIT");
	_menuText[2].setCharacterSize(64.77);
	_menuText[2].setFont(_ex02BlackItalicFont);
	_menuText[2].setFillColor(sf::Color::White);
	_menuText[2].setPosition(887, 559);

	_selectedItemIndex = 5;
	_greenButtonSprite.setTexture(_greenHoveredButtonTexture);
}

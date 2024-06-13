/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:08 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 18:33:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

using namespace std;

MainMenu::MainMenu(float width, float height, sf::RenderWindow &window) {
	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		cerr << "Error while loading the 'Exo2-Black.ttf' file." << endl;
	if (!_ex02BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		cerr << "Error while loading the 'Exo2-BlackItalic.ttf' file." << endl;
	if (!_greenButtonTexture.loadFromFile("assets/images/buttons/green_button.png"))
		cerr << "Error while loading the 'green_button.png' file." << endl;
	if (!_orangeButtonTexture.loadFromFile("assets/images/buttons/orange_button.png"))
		cerr << "Error while loading the 'orange_button.png' file." << endl;
	if (!_redButtonTexture.loadFromFile("assets/images/buttons/red_button.png"))
		cerr << "Error while loading the 'red_button.png' file." << endl;
	if (!_blueButtonTexture.loadFromFile("assets/images/buttons/blue_button.png"))
		cerr << "Error while loading the 'blue_button.png' file." << endl;
	if (!_greenButtonHighlightedTexture.loadFromFile("assets/images/buttons/green_button_highlight.png"))
		cerr << "Error while loading the 'green_button_highlight.png' file." << endl;
	if (!_orangeButtonHighlightedTexture.loadFromFile("assets/images/buttons/orange_button_highlight.png"))
		cerr << "Error while loading the 'orange_button_highlight.png' file." << endl;
	if (!_redButtonHighlightedTexture.loadFromFile("assets/images/buttons/red_button_highlight.png"))
		cerr << "Error while loading the 'red_button_highlight.png' file." << endl;
	if (!_blueButtonHighlightedTexture.loadFromFile("assets/images/buttons/blue_button_highlight.png"))
		cerr << "Error while loading the 'blue_button_highlight.png' file." << endl;
	if (!_customIconTexture.loadFromFile("assets/images/icons/custom.png"))
		cerr << "Error while loading the 'custom.png' file." << endl;
	if (!_settingsIconTexture.loadFromFile("assets/images/icons/settings.png"))
		cerr << "Error while loading the 'settings.png' file." << endl;
	if (!_helpIconTexture.loadFromFile("assets/images/icons/help.png"))
		cerr << "Error while loading the 'help.png' file." << endl;
	if (!_arrowIconTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		cerr << "Error while loading the 'return_arrow.png' file." << endl;
	if (!_arrowIconHighlightedTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		cerr << "Error while loading the 'return_arrow_highlight.png' file." << endl;

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

	(void)width;
	(void)height;
	(void)window;

	_menuText[0].setString("Go");
	_menuText[0].setCharacterSize(140.48);
	_menuText[0].setFont(_exo2BlackFont);
	_menuText[0].setFillColor(sf::Color(141, 82, 190));
	_menuText[0].setPosition(684, 40);

	_menuText[1].setString("moku");
	_menuText[1].setCharacterSize(140.48);
	_menuText[1].setFont(_exo2BlackFont);
	_menuText[1].setFillColor(sf::Color(208, 87, 47));
	_menuText[1].setPosition(865, 40);

	_menuText[2].setString("Go");
	_menuText[2].setCharacterSize(140.48);
	_menuText[2].setFont(_exo2BlackFont);
	_menuText[2].setFillColor(sf::Color(248, 231, 254));
	_menuText[2].setPosition(684, 30);

	_menuText[3].setString("moku");
	_menuText[3].setCharacterSize(140.48);
	_menuText[3].setFont(_exo2BlackFont);
	_menuText[3].setFillColor(sf::Color(255, 164, 94));
	_menuText[3].setPosition(865, 30);

	_menuText[4].setString("by hsebille & laprieur");
	_menuText[4].setCharacterSize(30.23);
	_menuText[4].setFont(_exo2BlackFont);
	_menuText[4].setFillColor(sf::Color::White);
	_menuText[4].setPosition(800, 222);

	_menuText[5].setString("1 VS 1");
	_menuText[5].setCharacterSize(64.77);
	_menuText[5].setFont(_ex02BlackItalicFont);
	_menuText[5].setFillColor(sf::Color::White);
	_menuText[5].setPosition(877, 298);

	_menuText[6].setString("AI VERSUS");
	_menuText[6].setCharacterSize(64.77);
	_menuText[6].setFont(_ex02BlackItalicFont);
	_menuText[6].setFillColor(sf::Color::White);
	_menuText[6].setPosition(795, 430);

	_menuText[7].setString("EXIT");
	_menuText[7].setCharacterSize(64.77);
	_menuText[7].setFont(_ex02BlackItalicFont);
	_menuText[7].setFillColor(sf::Color::White);
	_menuText[7].setPosition(887, 559);

	_menuText[8].setString("More options");
	_menuText[8].setCharacterSize(30.23);
	_menuText[8].setFont(_exo2BlackFont);
	_menuText[8].setFillColor(sf::Color::White);
	_menuText[8].setPosition(857, 685);

	_selectedItemIndex = 5;
	
	_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow& window) {
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::RectangleShape leftLine(sf::Vector2f(150, 5));
	sf::RectangleShape rightLine(sf::Vector2f(150, 5));
	background.setFillColor(sf::Color(38, 1, 69));
	leftLine.setPosition(685, 705);
	rightLine.setPosition(1085, 705);

	window.draw(background);
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

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window, MainMenu &mainMenu) {
	if (displayMenu == true) {
		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			mainMenu.handleMouseMovement(mousePos);
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
	}
	if ((getSelectedItemIndex() == 5 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 5 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
		displayMenu = false;
		displayGame = true;
		_selectedItemIndex = -1;
	}
	if ((getSelectedItemIndex() == 6 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 6 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
		cout << "Player vs AI" << endl;
	if ((getSelectedItemIndex() == 7 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 7 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
		window.close();
	if ((getSelectedItemIndex() == 8 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 8 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
		cout << "Customisation" << endl;
	}
	if ((getSelectedItemIndex() == 9 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 9 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
		cout << "Settings" << endl;
	}
	if ((getSelectedItemIndex() == 10 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 10 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
		displayMenu = false;
		displayHelp = true;
		_selectedItemIndex = -1;
	}
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		window.close();
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
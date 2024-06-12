/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:08 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/12 14:15:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

using namespace std;

MainMenu::MainMenu(float width, float height, sf::RenderWindow &window) {
	if (!_gomokuFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf")) {
		cerr << "Error while loading the gomokuFont file." << endl;
	}
	if (!_menuFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf")) {
		cerr << "Error while loading the menuFont file." << endl;
	}
	if (!_greenButtonTexture.loadFromFile("assets/images/green_button.png")) {
		cerr << "Error while loading the green button file." << endl;
	}
	if (!_orangeButtonTexture.loadFromFile("assets/images/orange_button.png")) {
		cerr << "Error while loading the orange button file." << endl;
	}
	if (!_redButtonTexture.loadFromFile("assets/images/red_button.png")) {
		cerr << "Error while loading the red button file." << endl;
	}
	if (!_blueButtonTexture.loadFromFile("assets/images/blue_button.png")) {
		cerr << "Error while loading the blueSquareTextureBehind file." << endl;
	}
	if (!_helpTexture.loadFromFile("assets/images/help.png")) {
		cerr << "Error while loading the helpTexture file." << endl;
	}
	if (!_settingsTexture.loadFromFile("assets/images/settings.png")) {
		cerr << "Error while loading the settingsTexture file." << endl;
	}
	if (!_customTexture.loadFromFile("assets/images/custom.png")) {
		cerr << "Error while loading the customTexture file." << endl;
	}
	if (!_greenButtonHighlightedTexture.loadFromFile("assets/images/green_button_highlight.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted2 file." << endl;
	}
	if (!_orangeButtonHighlightedTexture.loadFromFile("assets/images/orange_button_highlight.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted2 file." << endl;
	}
	if (!_redButtonHighlightedTexture.loadFromFile("assets/images/red_button_highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted2 file." << endl;
	}

	_greenButton.setTexture(_greenButtonTexture);
	_orangeButton.setTexture(_orangeButtonTexture);
	_redButton.setTexture(_redButtonTexture);
	_blueButtonCustom.setTexture(_blueButtonTexture);
	_blueButtonSettings.setTexture(_blueButtonTexture);
	_blueButtonHelp.setTexture(_blueButtonTexture);
	_help.setTexture(_helpTexture);
	_settings.setTexture(_settingsTexture);
	_custom.setTexture(_customTexture);

	_greenButton.setPosition(683.64, 297.95);
	_orangeButton.setPosition(683.64, 430.09);
	_redButton.setPosition(683.64, 559.64);
	_blueButtonCustom.setPosition(683.64, 755.45);
	_blueButtonSettings.setPosition(901.27, 755.45);
	_blueButtonHelp.setPosition(1119.77, 755.45);

	_custom.setPosition(695, 766);
	_settings.setPosition(913, 766);
	_help.setPosition(1131, 766);

	(void)width;
	(void)height;
	(void)window;

	_menu[0].setString("Go");
	_menu[0].setCharacterSize(140.48);
	_menu[0].setFont(_gomokuFont);
	_menu[0].setFillColor(sf::Color(141, 82, 190));
	_menu[0].setPosition(684, 40);

	_menu[1].setString("moku");
	_menu[1].setCharacterSize(140.48);
	_menu[1].setFont(_gomokuFont);
	_menu[1].setFillColor(sf::Color(208, 87, 47));
	_menu[1].setPosition(865, 40);

	_menu[2].setString("Go");
	_menu[2].setCharacterSize(140.48);
	_menu[2].setFont(_gomokuFont);
	_menu[2].setFillColor(sf::Color(248, 231, 254));
	_menu[2].setPosition(684, 30);

	_menu[3].setString("moku");
	_menu[3].setCharacterSize(140.48);
	_menu[3].setFont(_gomokuFont);
	_menu[3].setFillColor(sf::Color(255, 164, 94));
	_menu[3].setPosition(865, 30);

	_menu[4].setString("by hsebille & laprieur");
	_menu[4].setCharacterSize(30.23);
	_menu[4].setFont(_gomokuFont);
	_menu[4].setFillColor(sf::Color::White);
	_menu[4].setPosition(800, 222);

	_menu[5].setString("1 VS 1");
	_menu[5].setCharacterSize(64.77);
	_menu[5].setFont(_menuFont);
	_menu[5].setFillColor(sf::Color::White);
	_menu[5].setPosition(877, 298);

	_menu[6].setString("AI VERSUS");
	_menu[6].setCharacterSize(64.77);
	_menu[6].setFont(_menuFont);
	_menu[6].setFillColor(sf::Color::White);
	_menu[6].setPosition(795, 430);

	_menu[7].setString("EXIT");
	_menu[7].setCharacterSize(64.77);
	_menu[7].setFont(_menuFont);
	_menu[7].setFillColor(sf::Color::White);
	_menu[7].setPosition(887, 559);

	_menu[8].setString("More options");
	_menu[8].setCharacterSize(30.23);
	_menu[8].setFont(_gomokuFont);
	_menu[8].setFillColor(sf::Color::White);
	_menu[8].setPosition(857, 685);

	_selectedItemIndex = 5;
	
	_greenButton.setTexture(_greenButtonHighlightedTexture);
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
	window.draw(_greenButton);
	window.draw(_orangeButton);
	window.draw(_redButton);
	window.draw(_blueButtonCustom);
	window.draw(_blueButtonSettings);
	window.draw(_blueButtonHelp);
	window.draw(leftLine);
	window.draw(rightLine);
	window.draw(_custom);
	window.draw(_settings);
	window.draw(_help);
	
	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		window.draw(_menu[i]);
	}
}

void	MainMenu::MoveUp() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 5;
		_buttonBackground1.setTexture(_buttonBackgroundTextureHighlighted1);
		_buttonBackground2.setTexture(_buttonBackgroundTextureHighlighted2);
	}
	if (_selectedItemIndex - 1 >= 5) {
		if (_selectedItemIndex == 6)
			_orangeButton.setTexture(_orangeButtonTexture);
		else if (_selectedItemIndex == 7)
			_redButton.setTexture(_redButtonTexture);
		_selectedItemIndex--;
		if (_selectedItemIndex == 6)
			_orangeButton.setTexture(_orangeButtonHighlightedTexture);
		else if (_selectedItemIndex == 5)
			_greenButton.setTexture(_greenButtonHighlightedTexture);
	}
}

void	MainMenu::MoveDown() {
	if (_selectedItemIndex == -1) {
		_selectedItemIndex = 5;
		_buttonBackground1.setTexture(_buttonBackgroundTextureHighlighted1);
		_buttonBackground2.setTexture(_buttonBackgroundTextureHighlighted2);		
	}
	if (_selectedItemIndex + 1 <= 7) {
		if (_selectedItemIndex == 5)
			_greenButton.setTexture(_greenButtonTexture);
		else  if (_selectedItemIndex == 6)
			_orangeButton.setTexture(_orangeButtonTexture);
		_selectedItemIndex++;
		if (_selectedItemIndex == 6)
			_orangeButton.setTexture(_orangeButtonHighlightedTexture);
		else if (_selectedItemIndex == 7)
			_redButton.setTexture(_redButtonHighlightedTexture);
	}
}

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window, MainMenu &mainMenu) {
	if (event.type == sf::Event::MouseMoved) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		mainMenu.handleMouseMovement(mousePos);
	}
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up)
			MoveUp();
		if (event.key.code == sf::Keyboard::Down)
			MoveDown();
	}
	if ((getSelectedItemIndex() == 5 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 5 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
		displayMenu = false;
		displayGame = true;
	}
	if ((getSelectedItemIndex() == 6 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 6 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
		cout << "Player vs AI" << endl;
	if ((getSelectedItemIndex() == 7 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		|| (getSelectedItemIndex() == 7 && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
		window.close();
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		window.close();
}

void MainMenu::handleMouseMovement(sf::Vector2i mousePos) {
 	if (_menu[5].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_buttonBackground1.setTexture(_buttonBackgroundTextureHighlighted1);
		_buttonBackground2.setTexture(_buttonBackgroundTextureHighlighted2);
		_selectedItemIndex = 5;
	}
	else if (_menu[6].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_buttonBackground3.setTexture(_buttonBackgroundTextureHighlighted3);
		_buttonBackground4.setTexture(_buttonBackgroundTextureHighlighted4);
		_selectedItemIndex = 6;
	}
	else if (_menu[7].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_buttonBackground5.setTexture(_buttonBackgroundTextureHighlighted5);
		_buttonBackground6.setTexture(_buttonBackgroundTextureHighlighted6);
		_selectedItemIndex = 7;
	}
	else {
		_buttonBackground1.setTexture(_buttonBackgroundTexture1);
		_buttonBackground2.setTexture(_buttonBackgroundTexture2);
		_buttonBackground3.setTexture(_buttonBackgroundTexture3);
		_buttonBackground4.setTexture(_buttonBackgroundTexture4);
		_buttonBackground5.setTexture(_buttonBackgroundTexture5);
		_buttonBackground6.setTexture(_buttonBackgroundTexture6);
		_selectedItemIndex = -1;
	}
}
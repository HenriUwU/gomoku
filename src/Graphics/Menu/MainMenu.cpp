/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/06/11 20:53:18 by hsebille         ###   ########.fr       */
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
	if (!_buttonBackgroundTexture1.loadFromFile("assets/images/Green rectangle front.png")) {
		cerr << "Error while loading the buttonBackgroundTexture file." << endl;
	}
	if (!_buttonBackgroundTexture2.loadFromFile("assets/images/Green rectangle behind.png")) {
		cerr << "Error while loading the buttonBackgroundTexture2 file." << endl;
	}
	if (!_buttonBackgroundTexture3.loadFromFile("assets/images/Orange rectangle front.png")) {
		cerr << "Error while loading the buttonBackgroundTexture3 file." << endl;
	}
	if (!_buttonBackgroundTexture4.loadFromFile("assets/images/Orange rectangle behind.png")) {
		cerr << "Error while loading the buttonBackgroundTexture4 file." << endl;
	}
	if (!_buttonBackgroundTexture5.loadFromFile("assets/images/Red rectangle front.png")) {
		cerr << "Error while loading the buttonBackgroundTexture5 file." << endl;
	}
	if (!_buttonBackgroundTexture6.loadFromFile("assets/images/Red rectangle behind.png")) {
		cerr << "Error while loading the buttonBackgroundTexture6 file." << endl;
	}
	if (!_blueSquareTextureFront.loadFromFile("assets/images/Blue square front.png")) {
		cerr << "Error while loading the blueSquareTexture file." << endl;
	}
	if (!_blueSquareTextureBehind.loadFromFile("assets/images/Blue square behind.png")) {
		cerr << "Error while loading the blueSquareTextureBehind file." << endl;
	}
	if (!_lightBulbTexture.loadFromFile("assets/images/i.png")) {
		cerr << "Error while loading the lightBulbTexture file." << endl;
	}
	if (!_settingsWheelTexture.loadFromFile("assets/images/settings.png")) {
		cerr << "Error while loading the settingsWheelTexture file." << endl;
	}
	if (!_customizationTexture.loadFromFile("assets/images/art_1.png")) {
		cerr << "Error while loading the customizationTexture file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted1.loadFromFile("assets/images/Green rectangle front highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted2.loadFromFile("assets/images/Green rectangle behind highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted2 file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted3.loadFromFile("assets/images/Orange rectangle front highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted3 file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted4.loadFromFile("assets/images/Orange rectangle behind highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted4 file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted5.loadFromFile("assets/images/Red rectangle front highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted5 file." << endl;
	}
	if (!_buttonBackgroundTextureHighlighted6.loadFromFile("assets/images/Red rectangle behind highlighted.png")) {
		cerr << "Error while loading the buttonBackgroundTextureHighlighted6 file." << endl;
	}

	_buttonBackground1.setTexture(_buttonBackgroundTexture1);
	_buttonBackground2.setTexture(_buttonBackgroundTexture2);
	_buttonBackground3.setTexture(_buttonBackgroundTexture3);
	_buttonBackground4.setTexture(_buttonBackgroundTexture4);
	_buttonBackground5.setTexture(_buttonBackgroundTexture5);
	_buttonBackground6.setTexture(_buttonBackgroundTexture6);
	_blueSquareFront1.setTexture(_blueSquareTextureFront);
	_blueSquareFront2.setTexture(_blueSquareTextureFront);
	_blueSquareFront3.setTexture(_blueSquareTextureFront);
	_blueSquareBehind1.setTexture(_blueSquareTextureBehind);
	_blueSquareBehind2.setTexture(_blueSquareTextureBehind);
	_blueSquareBehind3.setTexture(_blueSquareTextureBehind);
	_lightBulb.setTexture(_lightBulbTexture);
	_settingsWheel.setTexture(_settingsWheelTexture);
	_customization.setTexture(_customizationTexture);
	
	_buttonBackground1.setPosition(683.64, 297.95);
	_buttonBackground2.setPosition(683.64, 307.95);
	_buttonBackground3.setPosition(683.64, 430.09);
	_buttonBackground4.setPosition(683.64, 440.09);
	_buttonBackground5.setPosition(683.64, 559.64);
	_buttonBackground6.setPosition(683.64, 569.64);

	_blueSquareBehind1.setPosition(683.64, 765.45);
	_blueSquareFront1.setPosition(683.64, 755.45);
	_blueSquareBehind2.setPosition(901.27, 765.45);
	_blueSquareFront2.setPosition(901.27, 755.45);
	_blueSquareBehind3.setPosition(1118.91, 765.45);
	_blueSquareFront3.setPosition(1119.77, 755.45);

	_customization.setScale(0.2, 0.2);
	_settingsWheel.setScale(0.2, 0.2);	
	//_lightBulb.setScale(0.2, 0.2);

	_customization.setPosition(694, 760);
	_settingsWheel.setPosition(909, 762);
	_lightBulb.setPosition(1130, 760);

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
	_menu[8].setPosition(857, 690);

	_selectedItemIndex = 5;

	_buttonBackground1.setTexture(_buttonBackgroundTextureHighlighted1);
	_buttonBackground2.setTexture(_buttonBackgroundTextureHighlighted2);
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow& window) {
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color(38, 1, 69));

	window.draw(background);
	window.draw(_buttonBackground2);
	window.draw(_buttonBackground1);
	window.draw(_buttonBackground4);
	window.draw(_buttonBackground3);
	window.draw(_buttonBackground6);
	window.draw(_buttonBackground5);
	window.draw(_blueSquareBehind1);
	window.draw(_blueSquareFront1);
	window.draw(_blueSquareBehind2);
	window.draw(_blueSquareFront2);
	window.draw(_blueSquareBehind3);
	window.draw(_blueSquareFront3);
	window.draw(_customization);
	window.draw(_settingsWheel);
	window.draw(_lightBulb);
	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		window.draw(_menu[i]);
	}
}

void	MainMenu::MoveUp() {
	if (_selectedItemIndex - 1 >= 5) {
		if (_selectedItemIndex == 6) {
			_buttonBackground3.setTexture(_buttonBackgroundTexture3);
			_buttonBackground4.setTexture(_buttonBackgroundTexture4);
		}
		else if (_selectedItemIndex == 7) {
			_buttonBackground5.setTexture(_buttonBackgroundTexture5);
			_buttonBackground6.setTexture(_buttonBackgroundTexture6);
		}
		_selectedItemIndex--;
		if (_selectedItemIndex == 6){
			_buttonBackground3.setTexture(_buttonBackgroundTextureHighlighted3);
			_buttonBackground4.setTexture(_buttonBackgroundTextureHighlighted4);
		}
		else if (_selectedItemIndex == 5) {
			_buttonBackground1.setTexture(_buttonBackgroundTextureHighlighted1);
			_buttonBackground2.setTexture(_buttonBackgroundTextureHighlighted2);
		}
	}
}

void	MainMenu::MoveDown() {
	if (_selectedItemIndex + 1 <= 7) {
		if (_selectedItemIndex == 5) {
			_buttonBackground1.setTexture(_buttonBackgroundTexture1);
			_buttonBackground2.setTexture(_buttonBackgroundTexture2);
		}
		else if (_selectedItemIndex == 6) {
			_buttonBackground3.setTexture(_buttonBackgroundTexture3);
			_buttonBackground4.setTexture(_buttonBackgroundTexture4);
		}
		_selectedItemIndex++;
		if (_selectedItemIndex == 6) {
			_buttonBackground3.setTexture(_buttonBackgroundTextureHighlighted3);
			_buttonBackground4.setTexture(_buttonBackgroundTextureHighlighted4);
		}
		else if (_selectedItemIndex == 7) {
			_buttonBackground5.setTexture(_buttonBackgroundTextureHighlighted5);
			_buttonBackground6.setTexture(_buttonBackgroundTextureHighlighted6);
		}
	}
}

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window, MainMenu &mainMenu) {
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up) {
			MoveUp();
			mainMenu.display(window);
		}
		if (event.key.code == sf::Keyboard::Down) {
			MoveDown();
			mainMenu.display(window);
		}
	}
	if (getSelectedItemIndex() == 5 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		displayMenu = false;
		displayGame = true;
	}
	if (getSelectedItemIndex() == 6 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		cout << "Player vs AI" << endl;
	if (getSelectedItemIndex() == 7 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		window.close();
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		window.close();
}
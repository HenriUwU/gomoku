/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/05/21 18:00:35 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height) {
	if (!_font.loadFromFile("assets/fonts/ChunkFive-Regular.otf")) {
		std::cerr << "Error while loading the font file." << std::endl;
	}

	if (!_backgroundTexture.loadFromFile("assets/images/frame1.png")) {
		std::cerr << "Error while loading the background file." << std::endl;
	}

	if (!_music.openFromFile("assets/musics/MainMenuSong.ogg")) {
		std::cerr << "Error while loading the music file." << std::endl;
	}

	_backgroundSprite.setTexture(_backgroundTexture);

	float scaleX = width / _backgroundTexture.getSize().x;
	float scaleY = height / _backgroundTexture.getSize().y;
	_backgroundSprite.setScale(scaleX, scaleY);

	_backgroundSprite.setPosition(0, 0);
	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);

	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		_menu[i].setFont(_font);
		_menu[i].setCharacterSize(45);
		_menu[i].setFillColor(fontColor);
	}

	_menu[0].setString("Welcome to Gomoku");
	_menu[1].setString("Two players");
	_menu[2].setString("Versus AI");
	_menu[3].setString("Quit");
	_menu[1].setFillColor(selectedColor);

	float maxMenuWidth = 0.0f;
	for (int i = 0; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		maxMenuWidth = std::max(maxMenuWidth, bounds.width);
	}

	float offsetX = (width - maxMenuWidth) / 2;
	float offsetY = 1;

	_menu[0].setPosition(sf::Vector2f((offsetX + (maxMenuWidth - _menu[0].getLocalBounds().width)), (height / NB_MENU_ITEMS + 1) * 0.5));        
	for (int i = 1; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		offsetY += 0.5;
		float elementX = offsetX + (maxMenuWidth - bounds.width) / 2;
		_menu[i].setPosition(sf::Vector2f(elementX, (height / NB_MENU_ITEMS + 1) * offsetY));
	}

	_selectedItemIndex = 1;

	playMusic();
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow &window) {
	sf::Color backgroundColor(48, 1, 30);
	
	sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
	background.setFillColor(backgroundColor);
	background.setPosition(0, 0);

	window.draw(background);

	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		window.draw(_menu[i]);
	}
}

void	MainMenu::MoveUp() {
	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);
	
	if (_selectedItemIndex - 1 >= 1) {
		_menu[_selectedItemIndex].setFillColor(fontColor);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(selectedColor);
	}
}

void	MainMenu::MoveDown() {
	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);
	
	if (_selectedItemIndex + 1 < NB_MENU_ITEMS) {
		_menu[_selectedItemIndex].setFillColor(fontColor);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(selectedColor);
	}
}

void	MainMenu::playMusic()
{
	_music.play();
	_music.setLoop(true);
}

void	MainMenu::stopMusic()
{
	_music.stop();
}

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window) {
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up)
			MoveUp();
		if (event.key.code == sf::Keyboard::Down)
			MoveDown();
	}
	if (getSelectedItemIndex() == 1 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		stopMusic();
		displayMenu = false;
		displayGame = true;
	}
	if (getSelectedItemIndex() == 2 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		std::cout << "Player vs AI" << std::endl;
	if (getSelectedItemIndex() == 3 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		window.close();
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		window.close();
}
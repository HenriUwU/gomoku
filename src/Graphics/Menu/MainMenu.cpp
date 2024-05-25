/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/05/24 14:47:30 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height, sf::RenderWindow &window) {
	if (!_font.loadFromFile("assets/fonts/ChunkFive-Regular.otf")) {
		std::cerr << "Error while loading the font file." << std::endl;
	}

	if (!_backgroundTexture.loadFromFile("assets/images/star2.png")) {
		std::cerr << "Error while loading the background file." << std::endl;
	}

	if (!_gobanTexture.loadFromFile("assets/images/grid.png")) {
		std::cerr << "Error while loading the goban file." << std::endl;
	}

	if (!_welcomeToGomokuTexture.loadFromFile("assets/images/welcome.png")) {
		std::cerr << "Error while loading the welcome file." << std::endl;
	}

	if (!_emojiCoolTexture.loadFromFile("assets/images/emojicool.png")) {
		std::cerr << "Error while loading the emoji_cool file." << std::endl;
	}

	_emojiCoolSprite.setTexture(_emojiCoolTexture);
	_emojiCoolSprite.setScale(0.5, 0.5);
	_emojiCoolSprite.setPosition(0, 600);

	_gobanSprite.setTexture(_gobanTexture);
	_gobanSprite.setScale(1, 1);
	_gobanSprite.setPosition(1079, 40);
	_gobanSprite.setColor(sf::Color(255, 255, 255, 150));
	_gobanSprite.setRotation(-10);

	_welcomeToGomokuSprite.setTexture(_welcomeToGomokuTexture);
	_welcomeToGomokuSprite.setScale(0.3, 0.3);

	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);
	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		_menu[i].setFont(_font);
		_menu[i].setCharacterSize(45);
		_menu[i].setFillColor(fontColor);
	}
	_selectedItemIndex = 1;
	_menu[0].setString("Welcome to Gomoku");
	_menu[1].setString("Two players");
	_menu[2].setString("Versus AI");
	_menu[3].setString("Quit");
	_menu[1].setCharacterSize(55);
	_menu[1].setFillColor(selectedColor);

	float maxMenuWidth = 0.0f;
	for (int i = 0; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		maxMenuWidth = std::max(maxMenuWidth, bounds.width);
	}

	float offsetX = (width - maxMenuWidth) / 2;
	float offsetY = 1;

	_welcomeToGomokuSprite.setPosition(sf::Vector2f((offsetX + (maxMenuWidth - _menu[0].getLocalBounds().width)) - 410, (height / NB_MENU_ITEMS + 1) * 1));
	for (int i = 1; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		offsetY += 0.5;
		float elementX = offsetX + (maxMenuWidth - bounds.width) / 2;
		_menu[i].setPosition(sf::Vector2f(elementX - 350, (height / NB_MENU_ITEMS + 1) * offsetY + 40));
	}

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	size_t numberOfSprites = 30;
	initializeBackgroundSprites(numberOfSprites, window);
}

MainMenu::~MainMenu() {}

void	MainMenu::display(sf::RenderWindow& window, float deltaTime) {
	sf::Color backgroundColor(48, 1, 30);
	Goban goban(window);
	
	sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
	background.setFillColor(backgroundColor);
	background.setPosition(0, 0);
	window.draw(background);

	updateSprites(deltaTime, window);
	for (const auto &fadingSprite : _backgroundSprites) {
		window.draw(fadingSprite.sprite);
	}

	for (int i = 1; i < NB_MENU_ITEMS; i++) {
		window.draw(_menu[i]);
	}
	
	window.draw(_welcomeToGomokuSprite);
	window.draw(_gobanSprite);
	window.draw(_emojiCoolSprite);
}

void MainMenu::initializeBackgroundSprites(size_t count, const sf::RenderWindow &window) {
    for (size_t i = 0; i < count; ++i) {
        sf::Sprite sprite;
        sprite.setTexture(_backgroundTexture);
		sprite.setScale(1, 1);

        // Set a random position within the window bounds
        float randomX = static_cast<float>(std::rand() % window.getSize().x);
        float randomY = static_cast<float>(std::rand() % window.getSize().y);
        sprite.setPosition(randomX, randomY);

        // Set a small scale for the sprite
        float scale = static_cast<float>((std::rand() % 50) / 1000.0 + 0.05); // Scale between 0.05 and 0.1
        sprite.setScale(scale, scale);

		// Set a random rotation
		float rotation = static_cast<float>(std::rand() % 360);
		sprite.setRotation(rotation);

        FadingSprite fadingSprite = { sprite, 0.0f, true };
        _backgroundSprites.push_back(fadingSprite);
    }
}

void MainMenu::updateSprites(float deltaTime, const sf::RenderWindow &window) {
	for (auto &fadingSprite : _backgroundSprites) {
		if (fadingSprite.fadingIn) {
			fadingSprite.timer += deltaTime;
			if (fadingSprite.timer >= 1.0f) {
				fadingSprite.timer = 1.0f;
				fadingSprite.fadingIn = false;
		}
	} else {
		fadingSprite.timer -= deltaTime;
		if (fadingSprite.timer <= 0.0f) {
			fadingSprite.timer = 0.0f;
			fadingSprite.fadingIn = true;

		// Set a new random position within the window bounds when starting to fade in again
		float randomX = static_cast<float>(std::rand() % window.getSize().x);
		float randomY = static_cast<float>(std::rand() % window.getSize().y);
		fadingSprite.sprite.setPosition(randomX, randomY);
	}
	}
		sf::Color color = fadingSprite.sprite.getColor();
		color.a = static_cast<sf::Uint8>(255 * fadingSprite.timer); // Update opacity
		fadingSprite.sprite.setColor(color);
	}
}

void	MainMenu::MoveUp(sf::RenderWindow &window) {
	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);

	float maxMenuWidth = 0.0f;
	for (int i = 0; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		maxMenuWidth = std::max(maxMenuWidth, bounds.width);
	}

	float offsetX = (1920 - maxMenuWidth) / 2;
	float offsetY = 1;
	
	if (_selectedItemIndex - 1 >= 1) {
		_menu[_selectedItemIndex].setFillColor(fontColor);
		_menu[_selectedItemIndex].setCharacterSize(45);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(selectedColor);
		_menu[_selectedItemIndex].setCharacterSize(55);
	}

	for (int i = 1; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		offsetY += 0.5;
		float elementX = offsetX + (maxMenuWidth - bounds.width) / 2;
		_menu[i].setPosition(sf::Vector2f(elementX - 350, (window.getSize().y / NB_MENU_ITEMS + 1) * offsetY + 40));
	}
}

void	MainMenu::MoveDown(sf::RenderWindow &window) {
	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);
	
	float maxMenuWidth = 0.0f;
	for (int i = 0; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		maxMenuWidth = std::max(maxMenuWidth, bounds.width);
	}

	float offsetX = (1920 - maxMenuWidth) / 2;
	float offsetY = 1;
	
	if (_selectedItemIndex + 1 < NB_MENU_ITEMS) {
		_menu[_selectedItemIndex].setFillColor(fontColor);
		_menu[_selectedItemIndex].setCharacterSize(45);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(selectedColor);
		_menu[_selectedItemIndex].setCharacterSize(55);
	}

	for (int i = 1; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		offsetY += 0.5;
		float elementX = offsetX + (maxMenuWidth - bounds.width) / 2;
		_menu[i].setPosition(sf::Vector2f(elementX - 350, (window.getSize().y / NB_MENU_ITEMS + 1) * offsetY + 40));
	}
}

void	MainMenu::handleKeys(sf::Event &event, sf::RenderWindow &window) {
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up)
			MoveUp(window);
		if (event.key.code == sf::Keyboard::Down)
			MoveDown(window);
	}
	if (getSelectedItemIndex() == 1 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
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
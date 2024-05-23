/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/05/23 16:02:38 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height, sf::RenderWindow &window) {
	if (!_font.loadFromFile("assets/fonts/ChunkFive-Regular.otf")) {
		std::cerr << "Error while loading the font file." << std::endl;
	}

	if (!_music.openFromFile("assets/musics/MainMenuSong.ogg")) {
		std::cerr << "Error while loading the music file." << std::endl;
	}

	if (!_backgroundTexture.loadFromFile("assets/images/star2.png")) {
		std::cerr << "Error while loading the background file." << std::endl;
	}

	sf::Color fontColor(182, 204, 161);
	sf::Color selectedColor(182, 143, 64);

	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		_menu[i].setFont(_font);
		_menu[i].setCharacterSize(50);
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

	_menu[0].setPosition(sf::Vector2f((offsetX + (maxMenuWidth - _menu[0].getLocalBounds().width)) - 350, (height / NB_MENU_ITEMS + 1) * 1));        
	for (int i = 1; i < NB_MENU_ITEMS; ++i) {
		sf::FloatRect bounds = _menu[i].getLocalBounds();
		offsetY += 0.5;
		float elementX = offsetX + (maxMenuWidth - bounds.width) / 2;
		_menu[i].setPosition(sf::Vector2f(elementX - 350, (height / NB_MENU_ITEMS + 1) * offsetY + 40));
	}

	_selectedItemIndex = 1;

	playMusic();

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	size_t numberOfSprites = 15;
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

	//_backgroundSprites.clear();
	updateSprites(deltaTime, window);
	
	for (const auto &fadingSprite : _backgroundSprites) {
		window.draw(fadingSprite.sprite);
	}

	for (int i = 0; i < NB_MENU_ITEMS; i++) {
		window.draw(_menu[i]);
	}

	drawMainMenuBoard(window);
}

void MainMenu::drawMainMenuBoard(sf::RenderWindow &window) {
    unsigned int windowWidth = window.getSize().x;
    unsigned int windowHeight = window.getSize().y;
    float gridSize = windowHeight - 75;

    // Calculate the position for the top-right corner
    float offsetX = -20; // Adjust the horizontal margin
    float offsetY = -20; // Adjust the vertical margin
    float gridStartX = windowWidth - gridSize - offsetX;
    float gridStartY = offsetY;

    sf::Color gobanBackgroundColor(84, 84, 84, 100);
    sf::RectangleShape gobanBackground(sf::Vector2f(gridSize + 20, gridSize + 20));
    gobanBackground.setPosition(gridStartX - 10, gridStartY - 10);
    gobanBackground.setFillColor(gobanBackgroundColor);
    window.draw(gobanBackground);

    // Display the grid
    sf::Color linecolor(242, 244, 243);
    for (int i = 0; i < 19; i++) {
        sf::Vertex verticalLine[] =
        {
            sf::Vertex(sf::Vector2f((gridSize / 18) * i + gridStartX, gridStartY), linecolor),
            sf::Vertex(sf::Vector2f((gridSize / 18) * i + gridStartX, gridStartY + gridSize), linecolor)
        };

        sf::Vertex horizontalLine[] =
        {
            sf::Vertex(sf::Vector2f(gridStartX, (gridSize / 18) * i + gridStartY), linecolor),
            sf::Vertex(sf::Vector2f(gridStartX + gridSize, (gridSize / 18) * i + gridStartY), linecolor)
        };

        window.draw(verticalLine, 2, sf::Lines);
        window.draw(horizontalLine, 2, sf::Lines);
    }
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
		//sprite.setScale(0.15, 0.15);

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
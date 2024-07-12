/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:58 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/12 11:23:16 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gameplay.hpp"

Gameplay::Gameplay() : _cellSize(868 / 19.0f) {
	init();
}

Gameplay::~Gameplay() {
	if (_aiThread.joinable())
		_aiThread.join();
}

void	Gameplay::display(const sf::Event& event, sf::RenderWindow& window, const Bitboard& bitboard) {
	returnButton(event, window);
	defineStones();
	defineAvatars();
	defineBoard();

	window.draw(_gamePageSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_gobanSprite);
	window.draw(_firstPlayerAvatarSprite);
	window.draw(_secondPlayerAvatarSprite);
	window.draw(_gridAndIndexSprite);
	//if (!_aiThreadRunning)
		drawStones(window, bitboard);
}

void	Gameplay::returnButton(const sf::Event& event, const sf::RenderWindow& window) {
	if (event.type == sf::Event::MouseMoved) {
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON]);
		else
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	}
	if (event.type == sf::Event::MouseButtonPressed)
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			gameState = MENU;
}

void	Gameplay::drawStones(sf::RenderWindow& window, const Bitboard& bitboard) {
	sf::Vector2i gridPosition = sf::Vector2i(527, 50);
	
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {
			if (bitboard.getBit(x, y) == 1) {
				_firstPlayerStoneSprite.setPosition(gridPosition.x + x * 48 - 13, gridPosition.y + y * 48 - 13);
				window.draw(_firstPlayerStoneSprite);
			}
			else if (bitboard.getBit(x, y) == 2) {
				_secondPlayerStoneSprite.setPosition(gridPosition.x + x * 48 - 13, gridPosition.y + y * 48 - 13);
				window.draw(_secondPlayerStoneSprite);
			}
		}
	}
}

void	Gameplay::defineStones() {
	const int firstPlayerIndices[] = {0, 2, 4, 6, 0, 9, 11, 13, 0};
	const int secondPlayerIndices[] = {1, 3, 5, 7, 8, 10, 12, 14, 1};

	if (stonesColors >= 0 && stonesColors < 9) {
		_firstPlayerStoneSprite.setTexture(_stonesTextures[firstPlayerIndices[stonesColors]]);
		_secondPlayerStoneSprite.setTexture(_stonesTextures[secondPlayerIndices[stonesColors]]);
	}
}

void	Gameplay::defineAvatars() {
	if (playerOneAvatar == NOAVATAR) {
		_firstPlayerAvatarSprite.setTexture(_avatarsTextures[0]);
		_secondPlayerAvatarSprite.setTexture(_avatarsTextures[1]);
	} else {
		_firstPlayerAvatarSprite.setTexture(_avatarsTextures[playerOneAvatar]);
		if (playerOneAvatar + 1 < 6)
			_secondPlayerAvatarSprite.setTexture(_avatarsTextures[playerOneAvatar + 1]);
		else
			_secondPlayerAvatarSprite.setTexture(_avatarsTextures[0]);
	}
}

void	Gameplay::defineBoard() {
	if (boardColor == NOBOARD) {
		_gobanSprite.setTexture(_boardsTextures[0]);
	} else {
		for (int i = 0; i < 8; i++)
			if (i == boardColor)
				_gobanSprite.setTexture(_boardsTextures[i]);
	}
}

void	Gameplay::mouseHover(sf::RenderWindow& window, Bitboard& bitboard, bool isAIPlaying) {
	float cellSize = 48;
	std::pair <unsigned int, unsigned int>	startPoint = std::make_pair(527, 50);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);	
	if (mousePosition.x > 525 + 868 || mousePosition.y > 48 + 868)
		return ;
	
	float xIndex = std::round((mousePosition.x - startPoint.first) / cellSize);
	float yIndex = std::round((mousePosition.y - startPoint.second) / cellSize);

	sf::Vector2f nearestIntersection(startPoint.first + xIndex * cellSize, startPoint.second + yIndex * cellSize);
	_firstPlayerStoneSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
	_secondPlayerStoneSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);

	sf::Vector2i stonePos(nearestIntersection.x, nearestIntersection.y);

	sf::Vector2f worldPos = window.mapPixelToCoords(stonePos);
		
	float relativeX = worldPos.x - startPoint.first;
    float relativeY = worldPos.y - startPoint.second;

	int col = static_cast<int>(relativeX / _cellSize);
    int row = static_cast<int>(relativeY / _cellSize);

	if (col >= 0 && col < 19 && row >= 0 && row < 19) {
		if (bitboard.getBit(col, row) != 0)
			return ;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (col >= 0 && col < 19 && row >= 0 && row < 19) {
			if ((_currentPlayer == 1 && bitboard.placeStone(col, row, _currentPlayer)) || (!isAIPlaying && bitboard.placeStone(col, row, _currentPlayer))) {
				if (_currentPlayer == 1)
					_currentPlayer = 2;
				else
					_currentPlayer = 1;
			}
		}
	}

	if (isAIPlaying && _currentPlayer == 2 && !_aiThreadRunning) {
		_stopAITimer = false;
		_aiThreadRunning = true;
		if (_aiThread.joinable())
			_aiThread.join();
		_aiThread = std::thread(&Gameplay::AITurn, this, std::ref(bitboard));
/* 		std::thread timerThread([&]() {
			auto start = std::chrono::high_resolution_clock::now();
			auto now = std::chrono::high_resolution_clock::now();
			auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();;
			while (!_stopAITimer) {
				now = std::chrono::high_resolution_clock::now();
				elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
			}
			std::cout << "Time elapsed: " << elapsedMs << " ms" << std::endl;
		});
		timerThread.join(); */
	}

	if (_currentPlayer == 1)
		window.draw(_firstPlayerStoneSprite);
	else
		window.draw(_secondPlayerStoneSprite);
}

void	Gameplay::AITurn(Bitboard& bitboard) {
	AI ai;
	ai.play(bitboard);
	_currentPlayer = 1;
	_aiThreadRunning = false;
	_stopAITimer = true;
}

void    Gameplay::init() {	
	const std::string	backwardButton[] = {"backwardButton", "backwardHoveredButton"};
	const std::string	others[]		 = {"gridAndIndex", "1VS1Page"};
	const std::string	stonesColors[]   = {"black", "white", "green", "red", "salmon", "coral", "pink", "fluoYellow", "yellow", "orange", "violet", "darkGreen", "lightGreen", "turquoiseGreen", "indigo"};
	const std::string	avatarsNames[]   = {"tommy", "laure", "alex", "heric", "mousse", "gunther"};
	const std::string	boardsColors[]   = {"azure", "yellow", "red", "orange", "pink", "green", "gray", "black"};
	
	loadTextures(2, "assets/images/buttons/", backwardButton, "Texture.png", _pageTextures);
	loadTextures(2, "assets/images/game/", others, "Texture.png", _pageTextures);
	loadTextures(15, "assets/images/game/stones/", stonesColors, "StoneTexture.png", _stonesTextures);
	loadTextures(6, "assets/images/game/avatars/", avatarsNames, "AvatarTexture.png", _avatarsTextures);
	loadTextures(8, "assets/images/game/boards/", boardsColors, "BoardTexture.png", _boardsTextures);

	_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	_gridAndIndexSprite.setTexture(_pageTextures[GRIDANDINDEX]);
	_gamePageSprite.setTexture(_pageTextures[GAMEPAGE]);
	_firstPlayerStoneSprite.setTexture(_stonesTextures[0]);
	_secondPlayerStoneSprite.setTexture(_stonesTextures[1]);

	_firstPlayerAvatarSprite.setPosition(167, 278);
	_secondPlayerAvatarSprite.setPosition(1607, 278);
	_gobanSprite.setPosition(477, 0);
	_gridAndIndexSprite.setPosition(477, 0);
	_backwardButtonSprite.setPosition(100, 100);
}
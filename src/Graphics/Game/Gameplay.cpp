/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:26 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/21 16:57:23 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Game/Gameplay.hpp"

Gameplay::Gameplay() : _playerJustMoved(0), _isFirstMove(true), _didSuggestMove(false), _cellSize(868 / 19.0f), _player1Stats(3), _player2Stats(3) {
	init();
}

Gameplay::~Gameplay() {
	if (_aiThread.joinable())
		_aiThread.join();
}

void	Gameplay::display(const sf::Event& event, sf::RenderWindow& window, Bitboard& bitboard) {
	returnButton(event, window, bitboard);
	defineStones();
	defineAvatars();
	defineBoard();

	if (gameState == AIVERSUS)
		_gamePageSprite.setTexture(_pageTextures[AIVERSUSPAGE]);
	else
		_gamePageSprite.setTexture(_pageTextures[VSPAGE]);
	window.draw(_gamePageSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_gobanSprite);
	window.draw(_firstPlayerAvatarSprite);
	window.draw(_secondPlayerAvatarSprite);
	window.draw(_gridAndIndexSprite);
	for (int i = 0; i < 3; i++) {
		window.draw(_player1Stats[i]);
		window.draw(_player2Stats[i]);
	}
	if (!aiPlaying)
		statistics();
	drawStones(window, bitboard);
	popUp(event, window, bitboard);
}

void	Gameplay::returnButton(const sf::Event& event, const sf::RenderWindow& window, Bitboard& bitboard) {
	if (event.type == sf::Event::MouseMoved) {
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON]);
		else
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	}
	if (event.type == sf::Event::MouseButtonPressed)
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
			gameState = MENU;
			endGameState = NOVICTORY;
			std::fill(playersCaptures, playersCaptures + 2, 0);
			bitboard.clear();
			_player1TotalTime = std::chrono::milliseconds::zero();
			_player2TotalTime = std::chrono::milliseconds::zero();
			_lastMoveDuration = std::chrono::milliseconds::zero();
			setStatistics(_player1Stats, _font, 1);
			setStatistics(_player2Stats, _font, 2);
			startTimer = false;
			_isFirstMove = true;
			_moveStartTime = std::chrono::steady_clock::now();
			
			_playerJustMoved = 0;
		}
}

void	Gameplay::statistics() {
	_player1Stats[0].setString(std::to_string(playersCaptures[0] * 2));
	_player2Stats[0].setString(std::to_string(playersCaptures[1] * 2));
	
	if (!_isFirstMove) {
		std::stringstream ssTotalTime;
		std::stringstream ssLastMoveDuration;
		
		ssTotalTime << std::fixed << std::setprecision(2) << ((_playerJustMoved == 1) ? _player1TotalTime.count() : _player2TotalTime.count());
		ssLastMoveDuration << std::fixed << std::setprecision(2) << _lastMoveDuration.count();
		
		std::string totalTime = ssTotalTime.str() + "s";
		std::string lastMoveTime = ssLastMoveDuration.str() + "s";
		
		(_playerJustMoved == 1) ? _player1Stats[1].setString(totalTime) : _player2Stats[1].setString(totalTime);
		(_playerJustMoved == 1) ? _player1Stats[2].setString(lastMoveTime) : _player2Stats[2].setString(lastMoveTime);
	}
}

void	Gameplay::popUp(const sf::Event& event, sf::RenderWindow& window, Bitboard& bitboard) {
	if (forbiddenMoves == DOUBLE_THREE && !_aiThreadRunning)
		_popupSprite.setTexture(_popupTextures[FORBIDDENMOVE]);
	else if (endGameState == P1VICTORY)
		_popupSprite.setTexture(_popupTextures[PLAYER1VICTORY]);
	else if (endGameState == P2VICTORY)
		_popupSprite.setTexture(_popupTextures[PLAYER2VICTORY]);
	else if (endGameState == AIVICTORY)
		_popupSprite.setTexture(_popupTextures[MEGATRONVICTORY]);
	else
		return ;
	window.draw(_popupSprite);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (endGameState != NOVICTORY) {
		if (_popupMainMenuButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
			_popupMainMenuButtonSprite.setTexture(_popupTextures[MAINMENUHOVEREDBUTTON]);
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				gameState = MENU;
				endGameState = NOVICTORY;
				bitboard.clear();
				std::fill(playersCaptures, playersCaptures + 2, 0);
				_player1TotalTime = std::chrono::milliseconds::zero();
				_player2TotalTime = std::chrono::milliseconds::zero();
				_lastMoveDuration = std::chrono::milliseconds::zero();
				setStatistics(_player1Stats, _font, 1);
				setStatistics(_player2Stats, _font, 2);
			}
		}
		else if (_popupPlayAgainButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
			_popupPlayAgainButtonSprite.setTexture(_popupTextures[PLAYAGAINHOVEREDBUTTON]);
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				endGameState = NOVICTORY;
				bitboard.clear();
				std::fill(playersCaptures, playersCaptures + 2, 0);
				_player1TotalTime = std::chrono::milliseconds::zero();
				_player2TotalTime = std::chrono::milliseconds::zero();
				_lastMoveDuration = std::chrono::milliseconds::zero();
				setStatistics(_player1Stats, _font, 1);
				setStatistics(_player2Stats, _font, 2);
				startTimer = true;
				gameStartTime = std::chrono::steady_clock::now();
				_moveStartTime = gameStartTime;
				_isFirstMove = true;
			}
		}
		else {
			_popupMainMenuButtonSprite.setTexture(_popupTextures[MAINMENUBUTTON]);
			_popupPlayAgainButtonSprite.setTexture(_popupTextures[PLAYAGAINBUTTON]);
		}
		startTimer = false;
		_popupMainMenuButtonSprite.setPosition(743.8, 547.5);
		_popupPlayAgainButtonSprite.setPosition(980.8, 547.5);
		window.draw(_popupMainMenuButtonSprite);
		window.draw(_popupPlayAgainButtonSprite);
	}
	
	sf::RectangleShape clickableZone(sf::Vector2f(26, 26));
	clickableZone.setPosition(1162, 404);
	clickableZone.setFillColor(sf::Color(0, 0, 0, 0));
	window.draw(clickableZone);
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left
		&& clickableZone.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		forbiddenMoves = NOFORBIDDENMOVE;
		if (endGameState != NOVICTORY)
			endGameState = SEEGAMESTATE;
		window.clear();
	}
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

void	Gameplay::moveSuggestion(sf::RenderWindow& window) {
	std::pair <unsigned int, unsigned int>	startPoint = std::make_pair(527, 50);
	sf::Vector2f nearestIntersection(startPoint.first + _suggestedMove.first * 48, startPoint.second + _suggestedMove.second * 48);
	if (_currentPlayer == 1) {
		sf::Color spriteColor = _firstPlayerMoveSuggestionSprite.getColor();
		_firstPlayerMoveSuggestionSprite.setColor(sf::Color(spriteColor.r, spriteColor.g, spriteColor.b, 150));
		_firstPlayerMoveSuggestionSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
		window.draw(_firstPlayerMoveSuggestionSprite);
	} else if (_currentPlayer == 2) {
		sf::Color spriteColor = _secondPlayerMoveSuggestionSprite.getColor();
		_secondPlayerMoveSuggestionSprite.setColor(sf::Color(spriteColor.r, spriteColor.g, spriteColor.b, 150));
		_secondPlayerMoveSuggestionSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
		window.draw(_secondPlayerMoveSuggestionSprite);
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
	
	if (_isFirstMove) {
		if (isAIPlaying)
			_currentPlayer = 2;
		setStatistics(_player1Stats, _font, 1);
		setStatistics(_player2Stats, _font, 2);
	}
	
	if (isAIPlaying && !bitboard.isGameOver() && _currentPlayer == 2 && !_aiThreadRunning) {
		_stopAITimer = false;
		_aiThreadRunning = true;
		aiPlaying = true;
		if (_aiThread.joinable()) {
			_aiThread.join();
		}
		_aiThread = std::thread(&Gameplay::AITurn, this, std::ref(bitboard));
	}
	
	if (!isStonePlaceable && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (col >= 0 && col < 19 && row >= 0 && row < 19) {
			if ((_currentPlayer == 1 && bitboard.placeStone(col, row, _currentPlayer))
			|| (!isAIPlaying && bitboard.placeStone(col, row, _currentPlayer))) {
				if (_isFirstMove) {
					_isFirstMove = false;
					_moveStartTime = std::chrono::steady_clock::now();
					_lastMoveDuration = _moveStartTime - gameStartTime;
				} else {
					_moveEndTime = std::chrono::steady_clock::now();
					_lastMoveDuration = _moveEndTime - _moveStartTime;
					_moveStartTime = _moveEndTime;
				}
				isStonePlaceable = true;
				_playerJustMoved = _currentPlayer;
				_didSuggestMove = false;
				if (_playerJustMoved == 1)
					_player1TotalTime += _lastMoveDuration;
				else
					_player2TotalTime += _lastMoveDuration;
				_currentPlayer = (_currentPlayer == 1) ? 2 : 1;
			}
		}
	}

	if (moveSuggestionEnabled == true && aiMode == NOAIMODE && _didSuggestMove == false) {
		_didSuggestMove = true;
		AI ai;
		_suggestedMove = ai.moveSuggestion(bitboard, _currentPlayer);
	}
	if (moveSuggestionEnabled == true)
		moveSuggestion(window);
	if (_currentPlayer == 1)
		window.draw(_firstPlayerStoneSprite);
	else if (!_aiThreadRunning)
		window.draw(_secondPlayerStoneSprite);
}

void	Gameplay::AITurn(Bitboard& bitboard) {
	AI ai;
	ai.play(bitboard);
	if (_isFirstMove) {
		_isFirstMove = false;
		_moveStartTime = std::chrono::steady_clock::now();
		_lastMoveDuration = _moveStartTime - gameStartTime;
	} else {
		_moveEndTime = std::chrono::steady_clock::now();
		_lastMoveDuration = _moveEndTime - _moveStartTime;
		_moveStartTime = _moveEndTime;
	}
	_playerJustMoved = 2;
	if (_playerJustMoved == 1)
		_player1TotalTime += _lastMoveDuration;
	else
		_player2TotalTime += _lastMoveDuration;
	_currentPlayer = 1;
	aiPlaying = false;
	_aiThreadRunning = false;
}

void    Gameplay::init() {
	const std::string	backwardButton[] = {"backwardButton", "backwardHoveredButton"};
	const std::string	others[]		 = {"gridAndIndex", "1VS1Page", "aiVersusPage"};
	const std::string	popup[]			 = {"forbiddenMovePopUp", "megatronVictoryPopUp", "player1VictoryPopUp", "player2VictoryPopUp", "mainMenuButton", "mainMenuHoveredButton", "playAgainButton", "playAgainHoveredButton"};
	const std::string	stonesColors[]   = {"blackStone", "whiteStone", "greenStone", "redStone", "salmonStone", "coralStone", "pinkStone", "fluoYellowStone", "yellowStone", "orangeStone", "violetStone", "darkGreenStone", "lightGreenStone", "turquoiseGreenStone", "indigoStone"};
	const std::string	avatarsNames[]   = {"tommyAvatar", "laureAvatar", "alexAvatar", "hericAvatar", "mousseAvatar", "guntherAvatar"};
	const std::string	boardsColors[]   = {"azureBoard", "yellowBoard", "redBoard", "orangeBoard", "pinkBoard", "greenBoard", "grayBoard", "blackBoard"};
	
	loadTextures(2, "assets/images/buttons/", backwardButton, _pageTextures);
	loadTextures(3, "assets/images/game/", others, _pageTextures);
	loadTextures(8, "assets/images/game/pop-up/", popup, _popupTextures);
	loadTextures(15, "assets/images/game/stones/", stonesColors, _stonesTextures);
	loadTextures(6, "assets/images/game/avatars/", avatarsNames, _avatarsTextures);
	loadTextures(8, "assets/images/game/boards/", boardsColors, _boardsTextures);

	_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	_gridAndIndexSprite.setTexture(_pageTextures[GRIDANDINDEX]);
	_firstPlayerStoneSprite.setTexture(_stonesTextures[0]);
	_secondPlayerStoneSprite.setTexture(_stonesTextures[1]);
	_firstPlayerMoveSuggestionSprite.setTexture(_stonesTextures[0]);
	_secondPlayerMoveSuggestionSprite.setTexture(_stonesTextures[1]);

	_firstPlayerAvatarSprite.setPosition(167, 278);
	_secondPlayerAvatarSprite.setPosition(1607, 278);
	_gobanSprite.setPosition(477, 0);
	_gridAndIndexSprite.setPosition(477, 0);
	_backwardButtonSprite.setPosition(100, 100);

	_font.loadFromFile("assets/fonts/Exo2/Exo2-BlackItalic.ttf");
	setStatistics(_player1Stats, _font, 1);
	setStatistics(_player2Stats, _font, 2);
}
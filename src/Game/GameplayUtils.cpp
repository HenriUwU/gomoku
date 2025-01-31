/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameplayUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:53:56 by laprieur          #+#    #+#             */
/*   Updated: 2025/01/07 13:48:17 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game/Gameplay.hpp"

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
	(_currentPlayer == 1) ? _turnIndicatorText.setPosition(140, 750) : _turnIndicatorText.setPosition(1560, 750);
	window.draw(_turnIndicatorText);
	for (int i = 0; i < 5; i++) {
		window.draw(_player1Stats[i]);
		window.draw(_player2Stats[i]);
	}
	if (!aiPlaying)
		statistics();
	drawStones(window, bitboard);
	popUp(event, window, bitboard);
}

std::pair<int, int> Gameplay::calculatePosition(sf::RenderWindow& window) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	if (mousePosition.x > GRIDSTARTPOINT_X + GRIDPIXELSIZE || mousePosition.x < GRIDSTARTPOINT_X
		|| mousePosition.y > GRIDSTARTPOINT_Y + GRIDPIXELSIZE || mousePosition.y < GRIDSTARTPOINT_Y)
		return std::make_pair(-1, -1);
	
	float xIndex = std::round((mousePosition.x - GRIDSTARTPOINT_X) / CELLPIXELSIZE);
	float yIndex = std::round((mousePosition.y - GRIDSTARTPOINT_Y) / CELLPIXELSIZE);

	sf::Vector2f nearestIntersection(GRIDSTARTPOINT_X + xIndex * CELLPIXELSIZE, GRIDSTARTPOINT_Y + yIndex * CELLPIXELSIZE);
	_firstPlayerStoneSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
	_secondPlayerStoneSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);

	sf::Vector2i stonePos(nearestIntersection.x, nearestIntersection.y);
		
	float relativeX = stonePos.x - GRIDSTARTPOINT_X;
	float relativeY = stonePos.y - GRIDSTARTPOINT_Y;

	int col = static_cast<int>(relativeX / CELLPIXELSIZE);
	int row = static_cast<int>(relativeY / CELLPIXELSIZE);
	return std::make_pair(col, row);
}

void Gameplay::resetGame(Bitboard& bitboard) {
	endGameState = NOVICTORY;
	std::fill(playersCaptures, playersCaptures + 2, 0);
	std::fill(_playersTotalMoves, _playersTotalMoves + 2, 0);
    _player1AverageMoveTime.clear();
    _player2AverageMoveTime.clear();
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
	_didSuggestMove = false;
}

void	Gameplay::returnButton(const sf::Event& event, const sf::RenderWindow& window, Bitboard& bitboard) {
	if (event.type == sf::Event::MouseMoved) {
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON]);
		else
			_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	}
	if (!aiPlaying && event.type == sf::Event::MouseButtonPressed) {
		if (_backwardButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
			gameState = MENU;
			resetGame(bitboard);
		}
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
		
		std::chrono::duration<double>	player1AverageMoveTime = (std::accumulate(_player1AverageMoveTime.begin(), _player1AverageMoveTime.end(), std::chrono::duration<double>(0))) / _player1AverageMoveTime.size();
		std::chrono::duration<double>	player2AverageMoveTime = (std::accumulate(_player2AverageMoveTime.begin(), _player2AverageMoveTime.end(), std::chrono::duration<double>(0))) / _player2AverageMoveTime.size();
		
		std::stringstream	ssPlayer1AverageMoveTime;
		std::stringstream	ssPlayer2AverageMoveTime;
		
		ssPlayer1AverageMoveTime << std::fixed << std::setprecision(2) << player1AverageMoveTime.count();
		ssPlayer2AverageMoveTime << std::fixed << std::setprecision(2) << player2AverageMoveTime.count();

		(_player1AverageMoveTime.size() == 0) ? _player1Stats[3].setString("0.00s") : _player1Stats[3].setString(ssPlayer1AverageMoveTime.str() + "s");
        (_player2AverageMoveTime.size() == 0) ? _player2Stats[3].setString("0.00s") : _player2Stats[3].setString(ssPlayer2AverageMoveTime.str() + "s");

		(_playerJustMoved == 1) ? _player1Stats[1].setString(std::to_string(_playersTotalMoves[0])) : _player2Stats[1].setString(std::to_string(_playersTotalMoves[1]));
		(_playerJustMoved == 1) ? _player1Stats[2].setString(lastMoveTime) : _player2Stats[2].setString(lastMoveTime);
		(_playerJustMoved == 1) ? _player1Stats[4].setString(totalTime) : _player2Stats[4].setString(totalTime);
	}
}

void	Gameplay::popUp(const sf::Event& event, sf::RenderWindow& window, Bitboard& bitboard) {
	if (forbiddenMoves == DOUBLE_THREE)
		_popupSprite.setTexture(_popupTextures[FORBIDDENMOVE]);
	else if (endGameState == P1VICTORY)
		_popupSprite.setTexture(_popupTextures[PLAYER1VICTORY]);
	else if (endGameState == P2VICTORY)
		_popupSprite.setTexture(_popupTextures[PLAYER2VICTORY]);
	else if (endGameState == AIVICTORY)
		_popupSprite.setTexture(_popupTextures[MEGATRONVICTORY]);
	else
		return;

	window.draw(_popupSprite);

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (endGameState != NOVICTORY) {
		auto currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<double> timeElapsed = currentTime - gameEndTime;

		if (timeElapsed.count() < ENDGAME_INTERVAL)
			return;

		if (_popupMainMenuButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
			_popupMainMenuButtonSprite.setTexture(_popupTextures[MAINMENUHOVEREDBUTTON]);
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				gameState = MENU;
				resetGame(bitboard);
			}
		}
		else if (_popupPlayAgainButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
			_popupPlayAgainButtonSprite.setTexture(_popupTextures[PLAYAGAINHOVEREDBUTTON]);
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				resetGame(bitboard);
			}
		}
		else {
			_popupMainMenuButtonSprite.setTexture(_popupTextures[MAINMENUBUTTON]);
			_popupPlayAgainButtonSprite.setTexture(_popupTextures[PLAYAGAINBUTTON]);
		}
		aiPlaying = false;
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

void	Gameplay::updateTime() {
	if (_isFirstMove) {
		_isFirstMove = false;
		_moveStartTime = std::chrono::steady_clock::now();
		_lastMoveDuration = _moveStartTime - gameStartTime;
	} else {
		_moveEndTime = std::chrono::steady_clock::now();
		_lastMoveDuration = _moveEndTime - _moveStartTime;
		_moveStartTime = _moveEndTime;
	}
	_playerJustMoved = _currentPlayer;
    (_currentPlayer == 1) ? _playersTotalMoves[0] += 1 : _playersTotalMoves[1] += 1; 
	if (_playerJustMoved == 1) {
		_player1TotalTime += _lastMoveDuration;
		_player1AverageMoveTime.push_back(_lastMoveDuration);
	} else {
		_player2TotalTime += _lastMoveDuration;
		_player2AverageMoveTime.push_back(_lastMoveDuration);
	}
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

	_firstPlayerAvatarSprite.setPosition(171, 241);
	_secondPlayerAvatarSprite.setPosition(1591, 241);
	_gobanSprite.setPosition(477, 0);
	_gridAndIndexSprite.setPosition(477, 0);
	_backwardButtonSprite.setPosition(100, 100);

	_font.loadFromFile("assets/fonts/Exo2/Exo2-BlackItalic.ttf");
	setStatistics(_player1Stats, _font, 1);
	setStatistics(_player2Stats, _font, 2);
	
	_turnIndicatorText.setFont(_font);
	_turnIndicatorText.setString("It's your turn!");
	_turnIndicatorText.setCharacterSize(33);
	_turnIndicatorText.setFillColor(sf::Color::White);
}
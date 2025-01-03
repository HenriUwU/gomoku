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

#include "Gameplay.hpp"

Gameplay::Gameplay() : _playerJustMoved(0), _isFirstMove(true), _didSuggestMove(false), _cellSize(868 / 19.0f), _player1Stats(3), _player2Stats(3) {
	init();
}

Gameplay::~Gameplay() { }

void	Gameplay::play(sf::RenderWindow& window, Bitboard& bitboard, AI& ai) {
	std::pair<int, int> position = calculatePosition(window);
	
	if (_isFirstMove && gameState == AIVERSUS)
		_currentPlayer = 2;
	else if (_isFirstMove && gameState != AIVERSUS)
		_currentPlayer = 1;

	if (gameState == AIVERSUS && !bitboard.isGameOver() && _currentPlayer == 2 && !aiPlaying) {
		aiPlaying = true;

		std::thread([this, &bitboard, &ai]() {
				this->AITurn(bitboard, ai);
		}).detach();
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.first != -1 && position.second != -1) {
		if (!bitboard.isLegalMove(position.first, position.second, _currentPlayer) || (aiPlaying && _currentPlayer == 2))
			return;
			
		bitboard.placeStone(position.first, position.second, _currentPlayer);

		if (_isFirstMove) {
			_isFirstMove = false;
			_moveStartTime = std::chrono::steady_clock::now();
			_lastMoveDuration = _moveStartTime - gameStartTime;
		} else {
			_moveEndTime = std::chrono::steady_clock::now();
			_lastMoveDuration = _moveEndTime - _moveStartTime;
			_moveStartTime = _moveEndTime;
		}

		if (_currentPlayer == 1)
			_player1TotalTime += _lastMoveDuration;
		if (_currentPlayer == 2)
			_player2TotalTime += _lastMoveDuration;
		_didSuggestMove = false;
		_playerJustMoved = _currentPlayer;
		_currentPlayer = (_currentPlayer == 1) ? 2 : 1;
	}

	if (moveSuggestionEnabled) {
		if (gameState != AIVERSUS && _didSuggestMove == false) {
			_suggestedMove = ai.moveSuggestion(bitboard, _currentPlayer);
			_didSuggestMove = true;
		}
		if (gameState != AIVERSUS && _didSuggestMove == true)
			moveSuggestion(window);
	}

	if (_currentPlayer == 1 && !bitboard.getBit(position.first, position.second))
		window.draw(_firstPlayerStoneSprite);
	else if (gameState != AIVERSUS && !bitboard.getBit(position.first, position.second))
		window.draw(_secondPlayerStoneSprite);
}

void	Gameplay::AITurn(Bitboard& bitboard, AI& ai) {
	if (aiPlaying) {
		if (_closingApp)
			return;

		if (aiMode != CRAZY)
			ai.play(bitboard);
		else
			ai.crazyMode(bitboard);
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

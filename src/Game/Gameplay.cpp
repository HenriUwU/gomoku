/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:26 by laprieur          #+#    #+#             */
/*   Updated: 2025/01/06 12:19:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gameplay.hpp"

Gameplay::Gameplay() : _playerJustMoved(0), _isFirstMove(true), _didSuggestMove(false), _cellSize(868 / 19.0f), _player1Stats(5), _player2Stats(5) {
	init();
}

Gameplay::~Gameplay() { }

void	Gameplay::play(sf::RenderWindow& window, Bitboard& bitboard, AI& ai) {
	std::pair<int, int> position = calculatePosition(window);
	
	if (_isFirstMove && gameState == AIVERSUS)
		_currentPlayer = 2;
	else if (_isFirstMove && gameState != AIVERSUS)
		_currentPlayer = 1;

	if (gameState == AIVERSUS && _currentPlayer == 2 && !aiPlaying) {
		aiPlaying = true;

		std::thread([this, &bitboard, &ai]() {
				this->AITurn(bitboard, ai);
		}).detach();
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.first != -1 && position.second != -1) {
		if (!bitboard.isLegalMove(position.first, position.second, _currentPlayer) || (aiPlaying && _currentPlayer == 2))
			return;

		auto currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<double> timeElapsed = currentTime - _moveStartTime;

		if (timeElapsed.count() < MOVE_INTERVAL)
			return;
		bitboard.placeStone(position.first, position.second, _currentPlayer);
		
        updateTime();
		_didSuggestMove = false;
		_currentPlayer = (_currentPlayer == 1) ? 2 : 1;
	}

	if (moveSuggestionEnabled && gameState != AIVERSUS) {
		if (_didSuggestMove == false) {
			_suggestedMove = ai.suggestMove(bitboard, _currentPlayer);
			_didSuggestMove = true;
		}
		if (_didSuggestMove == true)
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
		updateTime();
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

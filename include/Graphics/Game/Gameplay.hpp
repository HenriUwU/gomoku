/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:03:52 by laprieur          #+#    #+#             */
/*   Updated: 2024/08/03 15:14:15 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

enum pageTextures {
	BACKWARDBUTTON,
	BACKWARDHOVEREDBUTTON,
	GRIDANDINDEX,
	VSPAGE,
	AIVERSUSPAGE
};

class Bitboard;

class Gameplay {
	private:
		float						_cellSize;
		sf::Sprite					_firstPlayerAvatarSprite;
		sf::Sprite					_secondPlayerAvatarSprite;
		sf::Sprite					_gobanSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_gridAndIndexSprite;
		sf::Sprite					_gamePageSprite;
		sf::Sprite					_firstPlayerStoneSprite;
		sf::Sprite					_secondPlayerStoneSprite;
		std::thread					_aiThread;
		std::atomic<int>			_currentPlayer{1};
		std::atomic<bool>			_isAIPlaying{true};
		std::atomic<bool>			_aiThreadRunning{false};
		std::atomic<bool>			_stopAITimer{false};
		std::vector<sf::Texture>	_pageTextures;
		std::vector<sf::Texture>	_stonesTextures;
		std::vector<sf::Texture>	_avatarsTextures;
		std::vector<sf::Texture>	_boardsTextures;

		sf::Texture					_popupTexture;
		sf::Sprite					_popupSprite;

	public:
		Gameplay();
		~Gameplay();

		void	init();
		void	display(const sf::Event& event, sf::RenderWindow& window, const Bitboard& bitboard);
		void	returnButton(const sf::Event& event, const sf::RenderWindow& window);
		void	popUp(const sf::Event& event, sf::RenderWindow& window);
		void	drawStones(sf::RenderWindow& window, const Bitboard& bitboard);
		void	defineStones();
		void	defineAvatars();
		void	defineBoard();
		void	mouseHover(sf::RenderWindow& window, Bitboard& bitboard, bool isAIPlaying);
		void	AITurn(Bitboard& bitboard);
};
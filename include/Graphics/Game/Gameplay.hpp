/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:33:07 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/21 16:07:30 by laprieur         ###   ########.fr       */
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

enum popUpTextures {
	FORBIDDENMOVE,
	MEGATRONVICTORY,
	PLAYER1VICTORY,
	PLAYER2VICTORY,
	MAINMENUBUTTON,
	MAINMENUHOVEREDBUTTON,
	PLAYAGAINBUTTON,
	PLAYAGAINHOVEREDBUTTON
};

enum Statistics {
	CAPTUREDSTONES,
	TOTALPLAYTIME,
	LASTMOVETIME
};

class Bitboard;

class Gameplay {
	private:
		int										_playerJustMoved;
		bool									_isFirstMove;
    	bool									_didSuggestMove;
		float									_cellSize;
		sf::Font								_font;
		sf::Sprite								_firstPlayerAvatarSprite;
		sf::Sprite								_secondPlayerAvatarSprite;
		sf::Sprite								_gobanSprite;
		sf::Sprite								_backwardButtonSprite;
		sf::Sprite								_gridAndIndexSprite;
		sf::Sprite								_gamePageSprite;
		sf::Sprite								_firstPlayerStoneSprite;
		sf::Sprite								_secondPlayerStoneSprite;
		sf::Sprite								_firstPlayerMoveSuggestionSprite;
		sf::Sprite								_secondPlayerMoveSuggestionSprite;
		sf::Sprite								_popupSprite;
		sf::Sprite								_popupMainMenuButtonSprite;
		sf::Sprite								_popupPlayAgainButtonSprite;
		std::thread								_aiThread;
		std::atomic<int>						_currentPlayer{1};
		std::atomic<bool>						_isAIPlaying{true};
		std::atomic<bool>						_aiThreadRunning{false};
		std::atomic<bool>						_stopAITimer{false};
		std::pair<int, int>						_suggestedMove;
		std::vector<sf::Text>					_player1Stats;
		std::vector<sf::Text>					_player2Stats;
		std::vector<sf::Texture>				_pageTextures;
		std::vector<sf::Texture>				_popupTextures;
		std::vector<sf::Texture>				_stonesTextures;
		std::vector<sf::Texture>				_avatarsTextures;
		std::vector<sf::Texture>				_boardsTextures;
		std::chrono::duration<double>			_player1TotalTime;
		std::chrono::duration<double>			_player2TotalTime;
		std::chrono::duration<double>			_lastMoveDuration;
		std::chrono::steady_clock::time_point	_moveStartTime;
		std::chrono::steady_clock::time_point	_moveEndTime;

		void	init();
		void	returnButton(const sf::Event& event, const sf::RenderWindow& window, Bitboard& bitboard);
		void	resetGame(Bitboard& bitboard);
		void	AITurn(Bitboard& bitboard);
		void	statistics();
		void	drawStones(sf::RenderWindow& window, const Bitboard& bitboard);
		void	defineStones();
		void	defineAvatars();
		void	defineBoard();
		void	popUp(const sf::Event& event, sf::RenderWindow& window, Bitboard& bitboard);
		void	moveSuggestion(sf::RenderWindow& window);

	public:
		Gameplay();
		~Gameplay();

		void	display(const sf::Event& event, sf::RenderWindow& window, Bitboard& bitboard);
		void	play(sf::RenderWindow& window, Bitboard& bitboard);
};

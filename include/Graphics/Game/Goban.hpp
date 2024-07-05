/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/24 14:49:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Bitboard;

class Goban {
	private:
		std::vector<sf::Texture>	_stonesTextures;
		std::vector<sf::Texture>	_avatarsTextures;
		std::vector<sf::Texture>	_boardsTextures;
		
		sf::Texture		_backwardButtonTexture;
		sf::Texture		_backwardHoveredButtonTexture;
		sf::Texture		_gridAndIndexTexture;
		sf::Texture		_gamePageTexture;
		sf::Texture		_firstStoneTexture;
		sf::Texture		_secondStoneTexture;

		sf::Sprite		_firstPlayerAvatarSprite;
		sf::Sprite		_secondPlayerAvatarSprite;
		sf::Sprite		_gobanSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_gridAndIndexSprite;
		sf::Sprite		_gamePageSprite;
		sf::Sprite		_firstPlayerStoneSprite;
		sf::Sprite		_secondPlayerStoneSprite;

	public:
		Goban();
		~Goban();

		void	init();
		void	display(sf::Event& event, sf::RenderWindow &window, Bitboard& bitboard);
		void	returnButton(sf::Event &event, sf::RenderWindow &window);
		void	drawStones(sf::RenderWindow &window, Bitboard &bitboard);
		void	defineStones();
		void	defineAvatars();
		void	defineBoard();
};
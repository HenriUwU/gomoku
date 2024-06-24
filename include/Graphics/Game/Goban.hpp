/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/24 12:03:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Bitboard;

class Goban {
	private:
		sf::Texture		_mousseAvatarTexture;
		sf::Texture		_tommyAvatarTexture;
		sf::Texture		_alexAvatarTexture;
		sf::Texture		_guntherAvatarTexture;
		sf::Texture		_hericAvatarTexture;
		sf::Texture		_laureAvatarTexture;
		sf::Texture		_backwardButtonTexture;
		sf::Texture		_backwardHoveredButtonTexture;
		sf::Texture		_gridTexture;
		sf::Texture 	_azureBoardTexture;
		sf::Texture 	_blackBoardTexture;
		sf::Texture 	_grayBoardTexture;
		sf::Texture 	_greenBoardTexture;
		sf::Texture 	_orangeBoardTexture;
		sf::Texture 	_pinkBoardTexture;
		sf::Texture 	_redBoardTexture;
		sf::Texture 	_yellowBoardTexture;
		sf::Texture		_gamePageTexture;
		sf::Texture		_firstStoneTexture;
		sf::Texture		_secondStoneTexture;
		sf::Sprite		_firstPlayerAvatarSprite;
		sf::Sprite		_secondPlayerAvatarSprite;
		sf::Sprite		_gobanSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_gridSprite;
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
};
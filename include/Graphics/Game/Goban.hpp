/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/14 10:43:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Goban : public Graphics {
	private:
		// Fonts
		sf::Font								_exo2BlackFont;
		sf::Font								_ex02BlackItalicFont;
		//Textures
		sf::Texture								_lanceAvatarTexture;
		sf::Texture								_tommyAvatarTexture;
		sf::Texture								_alexAvatarTexture;
		sf::Texture								_guntherAvatarTexture;
		sf::Texture								_hericAvatarTexture;
		sf::Texture								_laureAvatarTexture;
		sf::Texture 							_gobanTexture;
		sf::Texture								_returnArrowTexture;
		sf::Texture								_returnArrowHighlightTexture;
		// Sprites
		sf::Sprite								_firstPlayerAvatar;
		sf::Sprite								_secondPlayerAvatar;
		sf::Sprite								_goban;
		sf::Sprite								_returnArrow;
		// Text
		sf::Text								_backToMenu;
		sf::Text								_player1;
		sf::Text								_player2;
		sf::Text								_capturedStones;
		sf::Text								_capturedStones2;
		sf::Text								_totalTimer;
		sf::Text								_totalTimer2;
		sf::Text								_lastMoveTimer;
		sf::Text								_lastMoveTimer2;

	public:
		Goban(sf::RenderWindow &window);
		~Goban();

		void	display(sf::RenderWindow &window);
		void	drawPlayerPositions(sf::RenderWindow &window, std::map<std::string, int> playerPositions);
		void	scoreTable(int player, sf::RenderWindow &window);
		void	returnButton(sf::Event &event, sf::RenderWindow &window);
};
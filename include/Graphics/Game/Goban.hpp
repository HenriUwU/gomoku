/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/18 21:38:12 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Goban : public Graphics {
	private:
		sf::Texture		_lanceAvatarTexture;
		sf::Texture		_tommyAvatarTexture;
		sf::Texture		_alexAvatarTexture;
		sf::Texture		_guntherAvatarTexture;
		sf::Texture		_hericAvatarTexture;
		sf::Texture		_laureAvatarTexture;
		sf::Texture		_returnArrowTexture;
		sf::Texture		_returnArrowHighlightTexture;
		sf::Texture		_gridTexture;
		sf::Texture 	_gobanAzureTexture;
		sf::Texture 	_gobanBlackTexture;
		sf::Texture 	_gobanGrayTexture;
		sf::Texture 	_gobanGreenTexture;
		sf::Texture 	_gobanOrangeTexture;
		sf::Texture 	_gobanPinkTexture;
		sf::Texture 	_gobanRedTexture;
		sf::Texture 	_gobanYellowTexture;
		sf::Texture		_gamePageTexture;
		sf::Sprite		_firstPlayerAvatar;
		sf::Sprite		_secondPlayerAvatar;
		sf::Sprite		_goban;
		sf::Sprite		_returnArrow;
		sf::Sprite		_grid;
		sf::Sprite		_gamePage;

	public:
		Goban(sf::RenderWindow &window);
		~Goban();

		void	display(sf::Event& event, sf::RenderWindow &window);
		void	gobanInit();
		void	drawPlayerPositions(sf::RenderWindow &window, std::map<std::string, int> playerPositions);
		void	returnButton(sf::Event &event, sf::RenderWindow &window);
};
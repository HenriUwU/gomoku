/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/19 10:46:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Goban {
	private:
		sf::Texture		_mousseAvatarTexture;
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
		Goban();
		~Goban();

		void	init();
		void	display(sf::Event& event, sf::RenderWindow &window);
		void	returnButton(sf::Event &event, sf::RenderWindow &window);
};
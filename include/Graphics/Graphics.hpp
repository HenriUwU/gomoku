/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:54:03 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 19:24:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Graphics {
	protected:
		float									_cellSize;
		float									_gridSize;
		unsigned int							_windowWidth;
		unsigned int							_windowHeight;
		std::pair <unsigned int, unsigned int>	_gridStartPoint;
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
		// Sprites
		sf::Texture								_returnArrowTexture;
		sf::Texture								_returnArrowHighlightTexture;
		sf::Sprite								_firstPlayerAvatar;
		sf::Sprite								_secondPlayerAvatar;
		sf::Sprite								_returnArrow;

	public:
		Graphics(sf::RenderWindow &window);
		virtual ~Graphics();
};
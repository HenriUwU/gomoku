/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:54:03 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 16:23:15 by hsebille         ###   ########.fr       */
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
		sf::Font								_exo2Italic;
		sf::Font								_exo2;
		sf::Texture							    _avatar1;
		sf::Texture							    _avatar2;
		sf::Texture							    _avatar3;
		sf::Texture							    _avatar4;
		sf::Texture							    _avatar5;
		sf::Texture							    _avatar6;
		sf::Texture							    _returnArrowTexture;
		sf::Texture							    _returnArrowHighlightTexture;
		sf::Sprite								_firstPlayerAvatar;
		sf::Sprite								_secondPlayerAvatar;
		sf::Sprite								_returnArrow;

	public:
		Graphics(sf::RenderWindow &window);
		virtual ~Graphics();
};
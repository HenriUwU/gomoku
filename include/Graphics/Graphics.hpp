/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:54:03 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/14 10:40:20 by hsebille         ###   ########.fr       */
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

	public:
		Graphics(sf::RenderWindow &window);
		virtual ~Graphics();
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:49:07 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/10 14:57:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

#include "gomoku.hpp"

class Graphics {
	private:
		float									_gridSize;
		float									_cellSize;
		unsigned int							_windowWidth;
		unsigned int							_windowHeight;
		std::pair <unsigned int, unsigned int>	_gridStartPoint;

	public:
		Graphics(sf::RenderWindow &window);
		~Graphics();

		void	displayCheckerboard(sf::RenderWindow &window);
		void	circleFollowMouse(sf::RenderWindow &window);
};

#endif
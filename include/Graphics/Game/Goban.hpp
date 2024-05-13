/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 14:18:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOBAN_HPP
# define GOBAN_HPP

#include "gomoku.hpp"
#include "Graphics.hpp"

class Goban : public Graphics {
	private:
		float									_gridSize;
		float									_cellSize;
		unsigned int							_windowWidth;
		unsigned int							_windowHeight;
		std::pair <unsigned int, unsigned int>	_gridStartPoint;

	public:
		Goban(sf::RenderWindow &window);
		~Goban();

		void	display(sf::RenderWindow &window);
};

#endif
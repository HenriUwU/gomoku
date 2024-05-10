/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:49:07 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/10 11:02:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

#include "gomoku.hpp"

class Graphics {
	private:
		unsigned int	_windowWidth;
		unsigned int	_windowHeight;

	public:
		Graphics(sf::RenderWindow &window);
		~Graphics();

		void	displayCheckerboard(sf::RenderWindow &window);
		void	circleFollowMouse(sf::RenderWindow &window);
};

#endif
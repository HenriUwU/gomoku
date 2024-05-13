/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 15:27:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Graphics;

class Goban : public Graphics {
	public:
		Goban(sf::RenderWindow &window);
		~Goban();

		void	display(sf::RenderWindow &window);
};
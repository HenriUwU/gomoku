/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goban.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/20 15:56:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Goban : public Graphics {
	public:
		Goban(sf::RenderWindow &window);
		~Goban();

		void	display(sf::RenderWindow &window);
		void	drawPlayerPositions(sf::RenderWindow &window, std::map<std::string, int> playerPositions);
		void	scoreTable(int player, sf::RenderWindow &window);
		void	returnButton(sf::Event &event, sf::RenderWindow &window);
};
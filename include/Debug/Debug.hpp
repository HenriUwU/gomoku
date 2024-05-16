/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:09:39 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/16 15:47:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Debug {
	private:
		static sf::Font			_font;

	public:
		Debug();
		~Debug();

		static void	init(sf::RenderWindow &window);
		static void	currentPos(sf::RenderWindow &window, std::string position);
		static void	currentPlayer(sf::RenderWindow &window, int player);
};

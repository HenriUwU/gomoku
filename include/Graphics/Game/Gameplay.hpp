/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:53 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 14:18:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include "Graphics.hpp"

class Gameplay : public Graphics {
	private:
		std::map<std::string, int>				_playerPositions;
		std::map<bool, int>						_catchedStones;

	public:
		Gameplay(sf::RenderWindow &window);
		~Gameplay();

		void	circleFollowMouse(sf::RenderWindow &window);
};

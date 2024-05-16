/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:53 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/16 16:02:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Gameplay : public Graphics {
	private:
		int										_currentPlayer;
		std::map<std::string, int>				_playerPositions;
		std::map<int, int>						_catchedStones; // Key = player, value = number

	public:
		Gameplay(sf::RenderWindow &window);
		~Gameplay();

		void	drawPlayerPositions(sf::RenderWindow& window);
		void	circleFollowMouse(sf::RenderWindow &window, sf::Event &event);
		void	placeStone(std::string position, int player);
		bool	isMoveLegal(std::string position);

		void	findHorizontalLine(std::string position, std::vector<int> &horizontalLine);
		void	findVerticalLine(std::string position, std::vector<int> &verticalLine);
		void	findDiagonalLine(std::string position, std::vector<int> &diagonalLine);
		void	findAntiDiagonalLine(std::string position, std::vector<int> &antiDiagonalLine);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:53 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/23 09:26:05 by laprieur         ###   ########.fr       */
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
		void	placeStone(std::string position, sf::RenderWindow &window);

		void	findHorizontalLine(int nbStones, std::string position, std::vector<int> &horizontalLine);
		void	findVerticalLine(int nbStones, std::string position, std::vector<int> &verticalLine);
		void	findDiagonalLine(int nbStones, std::string position, std::vector<int> &diagonalLine);
		void	findAntiDiagonalLine(int nbStones, std::string position, std::vector<int> &antiDiagonalLine);
	
		bool	isMoveLegal(std::string position);
		bool	isWinningMove(std::string position);
		bool	isThereDoubleThree(std::vector<int>	nearbyLines[4]);
		bool	isCapturingMove(std::string position);
		void	removeCapturedPair(std::string position, int lineType, unsigned int pairIndex);
};

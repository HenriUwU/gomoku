/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:53 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/19 10:45:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Gameplay {
	private:
		int							_currentPlayer;
		std::map<std::string, int>	_playerPositions;
		std::map<int, int>			_catchedStones;
		sf::Vector2f				_gridPosition;
		float						_gridSize;
		float						_cellSize;

		sf::Texture					_blackStoneTexture;
		sf::Texture					_whiteStoneTexture;
		sf::Texture					_coralStoneTexture;
		sf::Texture					_darkGreenStoneTexture;
		sf::Texture					_lightGreenStoneTexture;
		sf::Texture					_violetStoneTexture;
		sf::Texture					_yellowStoneTexture;
		sf::Texture					_fluoYellowStoneTexture;
		sf::Texture					_pinkStoneTexture;
		sf::Texture					_greenStoneTexture;
		sf::Texture					_indigoStoneTexture;
		sf::Texture					_orangeStoneTexture;
		sf::Texture					_redStoneTexture;
		sf::Texture					_salmonStoneTexture;
		sf::Texture					_turquoiseGreenStoneTexture;
		sf::Sprite					_firstStone;
		sf::Sprite					_secondStone;

	public:
		Gameplay();
		~Gameplay();

		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
		void	mouseHover(sf::RenderWindow &window);
		void	drawPlayerPositions(sf::RenderWindow& window);
		void	circleFollowMouse(sf::RenderWindow &window, sf::Event &event);
		void	placeStone(std::string position, sf::RenderWindow &window);

		void	findHorizontalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &horizontalLine);
		void	findVerticalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &verticalLine);
		void	findDiagonalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &diagonalLine);
		void	findAntiDiagonalLine(int nbStones, std::string position, std::vector<std::pair<std::string, int>> &antiDiagonalLine);
	
		bool	isMoveLegal(std::string position);
		bool	isWinningMove(std::string position);
		bool	isThereDoubleThree(std::vector<std::pair<std::string, int>> nearbyLines[4]);
		bool	isCapturingMove(std::string position);
		bool	isAlignmentBreakable(std::vector<std::pair<std::string, int>> &line, int alignmentIndex);
};

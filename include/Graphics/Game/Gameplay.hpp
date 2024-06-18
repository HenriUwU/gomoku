/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:53 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:55 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Gameplay : public Graphics {
	private:
		int							_currentPlayer;
		std::map<std::string, int>	_playerPositions;
		std::map<int, int>			_catchedStones; // Key = player, value = number
		sf::Vector2f				_gridPosition;
		float						_gridSize;
		float						_cellSize;
		
		// Textures
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

		// Sprites
		sf::Sprite					_firstStone;
		sf::Sprite					_secondStone;

	public:
		Gameplay(sf::RenderWindow &window);
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

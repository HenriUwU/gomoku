/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:18 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/22 14:25:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class CustomMenu {
	private:
		enum Enum {
			PAGE,
			BACKWARDBUTTON,
			BACKWARDHOVEREDBUTTON,
			COLORSELECTOR,
			AVATARSELECTOR
		};

		sf::Sprite					_customMenuSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_stoneSelectorSprite;
		sf::Sprite					_avatarSelectorSprite;
		sf::Sprite					_boardSelectorSprite;
		std::vector<sf::Sprite>		_stonesSprites;
		std::vector<sf::Sprite>		_avatarsSprites;
		std::vector<sf::Sprite>		_boardsSprites;
		std::vector<sf::Texture>	_pageTextures;
		std::vector<sf::Texture>	_stonesTextures;
		std::vector<sf::Texture>	_avatarsTextures;
		std::vector<sf::Texture>	_boardsTextures;
		
		void	init();
		void	handleStonesSelection(const sf::RenderWindow& window);
		void	handleAvatarSelection(const sf::RenderWindow& window);
		void	handleBoardSelection(const sf::RenderWindow& window);

	public:
		CustomMenu();
		~CustomMenu();

		void	display(sf::RenderWindow& window);
		void	handleKeys(const sf::Event& event, const sf::RenderWindow& window);
};
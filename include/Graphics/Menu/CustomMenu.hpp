/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:18 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/22 11:55:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

enum CustomMenuTextures {
	T_CUSTOMMENU,
	T_BACKWARDBUTTON,
	T_BACKWARDHOVEREDBUTTON,
	T_COLORSELECTOR,
	T_AVATARSELECTOR
};

class CustomMenu {
	private:
		sf::Sprite					_customMenuSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_stoneSelectorSprite;
		sf::Sprite					_avatarSelectorSprite;
		sf::Sprite					_boardSelectorSprite;
		std::vector<sf::Texture>	_pageTextures;
		std::vector<sf::Sprite>		_stonesSprites;
		std::vector<sf::Sprite>		_avatarsSprites;
		std::vector<sf::Sprite>		_boardsSprites;
		std::vector<sf::Texture>	_stonesTextures;
		std::vector<sf::Texture>	_avatarsTextures;
		std::vector<sf::Texture>	_boardsTextures;
		

	public:
		CustomMenu();
		~CustomMenu();

		void	init();
		void	display(sf::RenderWindow& window);
		void	handleKeys(const sf::Event& event, const sf::RenderWindow& window);
		void	handleStonesSelection(const sf::RenderWindow& window);
		void	handleAvatarSelection(const sf::RenderWindow& window);
		void	handleBoardSelection(const sf::RenderWindow& window);
};
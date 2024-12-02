/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/08/14 14:29:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class MainMenu {
	private:
		enum Enum {
			PAGE,
			B_1VS1,
			H_1VS1,
			B_AIVERSUS,
			H_AIVERSUS,
			B_EXIT,
			H_EXIT,
			B_CUSTOM,
			H_CUSTOM,
			B_SETTINGS,
			H_SETTINGS,
			B_HELP,
			H_HELP
		};

		int							_selectedItemIndex;
		sf::Sprite					_mainMenuSprite;
		sf::Sprite					_greenButtonSprite;
		sf::Sprite					_orangeButtonSprite;
		sf::Sprite					_redButtonSprite;
		sf::Sprite					_blueButtonCustomSprite;
		sf::Sprite					_blueButtonSettingsSprite;
		sf::Sprite					_blueButtonHelpSprite;
		std::vector<sf::Texture>	_buttonsTextures;

	public:
		MainMenu();
		~MainMenu();

		int		getSelectedItemIndex() const { return _selectedItemIndex; }

		void	init();
		void	display(sf::RenderWindow& window);
		void	moveUp();
		void	moveDown();
		void	moveLeft();
		void	moveRight();
		void	handleKeys(const sf::Event& event, sf::RenderWindow& window);
		void	handleMouseMovement(const sf::Vector2i& mousePos);
};
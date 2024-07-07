/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/19 11:39:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

enum Buttons {
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

class MainMenu {
	private:
		int							_selectedItemIndex;
		sf::Texture					_mainMenuTexture;
		std::vector<sf::Texture>	_buttonsTextures;
		sf::Sprite					_mainMenuSprite;
		sf::Sprite					_greenButtonSprite;
		sf::Sprite					_orangeButtonSprite;
		sf::Sprite					_redButtonSprite;
		sf::Sprite					_blueButtonCustomSprite;
		sf::Sprite					_blueButtonSettingsSprite;
		sf::Sprite					_blueButtonHelpSprite;

	public:
		MainMenu();
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	init();
		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	MoveLeft();
		void	MoveRight();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
		void	handleMouseMovement(sf::Vector2i mousePos);
};
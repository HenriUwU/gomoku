/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/12 14:15:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include "Goban.hpp"

#define NB_MENU_ITEMS 9

class MainMenu {
	private:
		int							_selectedItemIndex;
		sf::Font					_gomokuFont;
		sf::Font					_menuFont;
		sf::Text					_menu[NB_MENU_ITEMS];
		sf::Texture					_greenButtonTexture;
		sf::Texture					_orangeButtonTexture;
		sf::Texture					_redButtonTexture;
		sf::Texture					_greenButtonHighlightedTexture;
		sf::Texture					_orangeButtonHighlightedTexture;
		sf::Texture					_redButtonHighlightedTexture;
		sf::Texture					_blueButtonTexture;
		sf::Texture					_helpTexture;
		sf::Texture					_settingsTexture;
		sf::Texture					_customTexture;
		sf::Sprite					_greenButton;
		sf::Sprite					_orangeButton;
		sf::Sprite					_redButton;
		sf::Sprite					_greenButtonHighlighted;
		sf::Sprite					_orangeButtonHighlighted;
		sf::Sprite					_redButtonHighlighted;
		sf::Sprite					_blueButtonCustom;
		sf::Sprite					_blueButtonSettings;
		sf::Sprite					_blueButtonHelp;
		sf::Sprite					_help;
		sf::Sprite					_settings;
		sf::Sprite					_custom;

	public:
		MainMenu(float width, float height, sf::RenderWindow &window);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window, MainMenu &mainMenu);
		void	handleMouseMovement(sf::Vector2i mousePos);
};

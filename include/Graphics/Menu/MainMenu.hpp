/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/11 23:32:19 by laprieur         ###   ########.fr       */
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
		sf::Texture					_buttonBackgroundTexture1;
		sf::Texture					_buttonBackgroundTexture2;
		sf::Texture					_buttonBackgroundTexture3;
		sf::Texture					_buttonBackgroundTexture4;
		sf::Texture					_buttonBackgroundTexture5;
		sf::Texture					_buttonBackgroundTexture6;
		sf::Texture					_buttonBackgroundTextureHighlighted1;
		sf::Texture					_buttonBackgroundTextureHighlighted2;
		sf::Texture					_buttonBackgroundTextureHighlighted3;
		sf::Texture					_buttonBackgroundTextureHighlighted4;
		sf::Texture					_buttonBackgroundTextureHighlighted5;
		sf::Texture					_buttonBackgroundTextureHighlighted6;
		sf::Texture					_blueSquareTextureFront;
		sf::Texture					_blueSquareTextureBehind;
		sf::Texture					_helpTexture;
		sf::Texture					_settingsTexture;
		sf::Texture					_customTexture;
		sf::Sprite					_buttonBackground1;
		sf::Sprite					_buttonBackground2;
		sf::Sprite					_buttonBackground3;
		sf::Sprite					_buttonBackground4;
		sf::Sprite					_buttonBackground5;
		sf::Sprite					_buttonBackground6;
		sf::Sprite					_buttonBackgroundHighlighted1;
		sf::Sprite					_buttonBackgroundHighlighted2;
		sf::Sprite					_buttonBackgroundHighlighted3;
		sf::Sprite					_buttonBackgroundHighlighted4;
		sf::Sprite					_buttonBackgroundHighlighted5;
		sf::Sprite					_buttonBackgroundHighlighted6;
		sf::Sprite					_blueSquareFront1;
		sf::Sprite					_blueSquareFront2;
		sf::Sprite					_blueSquareFront3;
		sf::Sprite					_blueSquareBehind1;
		sf::Sprite					_blueSquareBehind2;
		sf::Sprite					_blueSquareBehind3;
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
};

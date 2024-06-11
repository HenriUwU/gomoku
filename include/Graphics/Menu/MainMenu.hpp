/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/11 20:28:20 by hsebille         ###   ########.fr       */
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
		sf::Texture					_lightBulbTexture;
		sf::Texture					_settingsWheelTexture;
		sf::Texture					_customizationTexture;
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
		sf::Sprite					_lightBulb;
		sf::Sprite					_settingsWheel;
		sf::Sprite					_customization;

	public:
		MainMenu(float width, float height, sf::RenderWindow &window);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window, MainMenu &mainMenu);
};

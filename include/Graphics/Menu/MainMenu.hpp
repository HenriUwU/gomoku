/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/17 12:21:30 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include "Goban.hpp"

#define NB_MENU_ITEMS 9

class MainMenu {
	private:
		//--- Main Menu ---//
		int							_selectedItemIndex;
		sf::Font					_exo2BlackFont;
		sf::Font					_ex02BlackItalicFont;
		sf::Text					_menuText[NB_MENU_ITEMS];
		sf::Texture					_greenButtonTexture;
		sf::Texture					_orangeButtonTexture;
		sf::Texture					_redButtonTexture;
		sf::Texture					_blueButtonTexture;
		sf::Texture					_greenButtonHighlightedTexture;
		sf::Texture					_orangeButtonHighlightedTexture;
		sf::Texture					_redButtonHighlightedTexture;
		sf::Texture					_blueButtonHighlightedTexture;
		sf::Texture					_customIconTexture;
		sf::Texture					_settingsIconTexture;
		sf::Texture					_helpIconTexture;
		sf::Texture					_arrowIconTexture;
		sf::Texture					_arrowIconHighlightedTexture;
		sf::Sprite					_greenButtonSprite;
		sf::Sprite					_orangeButtonSprite;
		sf::Sprite					_redButtonSprite;
		sf::Sprite					_greenButtonHighlightedSprite;
		sf::Sprite					_orangeButtonHighlightedSprite;
		sf::Sprite					_redButtonHighlightedSprite;
		sf::Sprite					_blueButtonCustomSprite;
		sf::Sprite					_blueButtonSettingsSprite;
		sf::Sprite					_blueButtonHelpSprite;
		sf::Sprite					_customIconSprite;
		sf::Sprite					_settingsIconSprite;
		sf::Sprite					_helpIconSprite;
		sf::Sprite					_leftArrowIconSprite;
		sf::Sprite					_rightArrowIconSprite;

		//--- Custom Page ---//
		sf::Texture		_artistTexture;
		sf::Texture		_boardColorAzureTexture;
		sf::Texture		_boardColorBlackTexture;
		sf::Texture		_boardColorGrayTexture;
		sf::Texture		_boardColorGreenTexture;
		sf::Texture		_boardColorOrangeTexture;
		sf::Texture		_boardColorPinkTexture;
		sf::Texture		_boardColorRedTexture;
		sf::Texture		_boardColorYellowTexture;
		sf::Texture		_boardColorAzureSelectedTexture;
		sf::Texture		_boardColorBlackSelectedTexture;
		sf::Texture		_boardColorGraySelectedTexture;
		sf::Texture		_boardColorGreenSelectedTexture;
		sf::Texture		_boardColorOrangeSelectedTexture;
		sf::Texture		_boardColorPinkSelectedTexture;
		sf::Texture		_boardColorRedSelectedTexture;
		sf::Texture		_boardColorYellowSelectedTexture;
		sf::Texture		_avatarAlexTexture;
		sf::Texture		_avatarGuntherTexture;
		sf::Texture		_avatarHericTexture;
		sf::Texture		_avatarLaureTexture;
		sf::Texture		_avatarMousseTexture;
		sf::Texture		_avatarTommyTexture;
		sf::Texture		_avatarAlexSelectedTexture;
		sf::Texture		_avatarGuntherSelectedTexture;
		sf::Texture		_avatarHericSelectedTexture;
		sf::Texture		_avatarLaureSelectedTexture;
		sf::Texture		_avatarMousseSelectedTexture;
		sf::Texture		_avatarTommySelectedTexture;
		sf::Texture		_stoneColorBandWTexture;
		sf::Texture		_stoneColorBandYTexture;
		sf::Texture		_stoneColorDGandLGTexture;
		sf::Texture		_stoneColorGandRTexture;
		sf::Texture		_stoneColorOandVTexture;
		sf::Texture		_stoneColorPandFYTexture;
		sf::Texture		_stoneColorSandCTexture;
		sf::Texture		_stoneColorTGandITexture;
		sf::Texture		_stoneColorBandWSelectedTexture;
		sf::Texture		_stoneColorBandYSelectedTexture;
		sf::Texture		_stoneColorDGandLGSelectedTexture;
		sf::Texture		_stoneColorGandRSelectedTexture;
		sf::Texture		_stoneColorOandVSelectedTexture;
		sf::Texture		_stoneColorPandFYSelectedTexture;
		sf::Texture		_stoneColorSandCSelectedTexture;
		sf::Texture		_stoneColorTGandISelectedTexture;
		sf::Sprite		_artist;
		sf::Sprite		_boardColorAzure;
		sf::Sprite		_boardColorBlack;
		sf::Sprite		_boardColorGray;
		sf::Sprite		_boardColorGreen;
		sf::Sprite		_boardColorOrange;
		sf::Sprite		_boardColorPink;
		sf::Sprite		_boardColorRed;
		sf::Sprite		_boardColorYellow;
		sf::Sprite		_avatarAlex;
		sf::Sprite		_avatarGunther;
		sf::Sprite		_avatarHeric;
		sf::Sprite		_avatarLaure;
		sf::Sprite		_avatarMousse;
		sf::Sprite		_avatarTommy;
		sf::Sprite		_stoneColorBandW;
		sf::Sprite		_stoneColorBandY;
		sf::Sprite		_stoneColorDGandLG;
		sf::Sprite		_stoneColorGandR;
		sf::Sprite		_stoneColorOandV;
		sf::Sprite		_stoneColorPandFY;
		sf::Sprite		_stoneColorSandC;
		sf::Sprite		_stoneColorTGandI;

	public:
		MainMenu(float width, float height, sf::RenderWindow &window);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	MoveLeft();
		void	MoveRight();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
		void	handleMouseMovement(sf::Vector2i mousePos);

		void	mainMenuInit();
		void	customPageInit();
		void	settingsPageInit();
		void	helpPageInit();
		
		void	customPage(sf::RenderWindow &window);
		void	settingsPage(sf::RenderWindow &window);
		void	helpPage(sf::RenderWindow &window);
};
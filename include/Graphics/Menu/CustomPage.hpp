/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPage.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:38:30 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 17:06:36 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class CustomPage {
	private:
		sf::Font		_exo2BlackFont;
		sf::Font		_exo2BlackItalicFont;
		sf::Texture		_artistTexture;
		sf::Texture		_boardColorAzureTexture;
		sf::Texture		_boardColorBlackTexture;
		sf::Texture		_boardColorGrayTexture;
		sf::Texture		_boardColorGreenTexture;
		sf::Texture		_boardColorOrangeTexture;
		sf::Texture		_boardColorPinkTexture;
		sf::Texture		_boardColorRedTexture;
		sf::Texture		_boardColorYellowTexture;
		sf::Texture		_avatarAlexTexture;
		sf::Texture		_avatarGuntherTexture;
		sf::Texture		_avatarHericTexture;
		sf::Texture		_avatarLaureTexture;
		sf::Texture		_avatarMousseTexture;
		sf::Texture		_avatarTommyTexture;
		sf::Texture		_stoneColorBandWTexture;
		sf::Texture		_stoneColorBandYTexture;
		sf::Texture		_stoneColorDGandLGTexture;
		sf::Texture		_stoneColorGandRTexture;
		sf::Texture		_stoneColorOandVTexture;
		sf::Texture		_stoneColorPandFYTexture;
		sf::Texture		_stoneColorSandCTexture;
		sf::Texture		_stoneColorTGandITexture;
		sf::Texture		_returnButtonTexture;
		sf::Texture		_returnButtonHighlightedTexture;
		sf::Texture		_selectionHaloTexture;
		sf::Texture		_avatarSelectorTexture;
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
		sf::Sprite		_returnButton;
		sf::Sprite		_stonesSelection;
		sf::Sprite		_avatarsSelection;
		sf::Sprite		_boardSelection;
		sf::Text		_custom;
		sf::Text		_customShadow;
		sf::Text		_showYourArtisticSoul;
		sf::Text		_stonesColor;
		sf::Text		_avatars;
		sf::Text		_boards;
		sf::Text		_BandW;
		sf::Text		_BandY;
		sf::Text		_DGandLG;
		sf::Text		_GandR;
		sf::Text		_OandV;
		sf::Text		_PandFY;
		sf::Text		_SandC;		
		sf::Text		_TGandI;
		sf::Text		_Alex;
		sf::Text		_Gunther;
		sf::Text		_Heric;
		sf::Text		_Laure;
		sf::Text		_Mousse;
		sf::Text		_Tommy;
		sf::Text		_Azure;
		sf::Text		_Black;
		sf::Text		_Gray;
		sf::Text		_Green;
		sf::Text		_Orange;
		sf::Text		_Pink;
		sf::Text		_Red;
		sf::Text		_Yellow;
		sf::Text		_backToMenu;

	public:
		CustomPage();
		~CustomPage();

		void	customPageInit();
		void	display(sf::RenderWindow& window);
		void	handleKeys(sf::RenderWindow& window);
		void	handleStonesSelection(sf::RenderWindow& window);
		void	handleBoardSelection(sf::RenderWindow& window);
		void	handleAvatarsSelection(sf::RenderWindow& window);
};
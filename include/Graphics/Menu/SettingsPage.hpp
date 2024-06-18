/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsPage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 10:52:36 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class SettingsPage {
	private:
		sf::Font		_exo2BlackFont;
		sf::Font		_exo2BlackItalicFont;
		sf::Texture		_boxTexture;
		sf::Texture		_boxCheckedTexture;
		sf::Texture		_speakerTexture;
		sf::Texture		_volume_100Texture;
		sf::Texture		_volume_90Texture;
		sf::Texture		_volume_80Texture;
		sf::Texture		_volume_70Texture;
		sf::Texture		_volume_60Texture;
		sf::Texture		_volume_50Texture;
		sf::Texture		_volume_40Texture;
		sf::Texture		_volume_30Texture;
		sf::Texture		_volume_20Texture;
		sf::Texture		_volume_10Texture;
		sf::Texture		_volume_0Texture;
		sf::Texture		_sparklesTexture;
		sf::Texture		_returnButtonTexture;
		sf::Texture		_returnButtonHoverTexture;
		sf::Sprite		_box;
		sf::Sprite		_box2;
		sf::Sprite		_box3;
		sf::Sprite		_box4;
		sf::Sprite		_box5;
		sf::Sprite		_box6;
		sf::Sprite		_box7;
		sf::Sprite		_box8;
		sf::Sprite		_speaker;
		sf::Sprite		_volume;
		sf::Sprite		_sparkles;
		sf::Sprite		_returnButton;

	public:
		SettingsPage();
		~SettingsPage();

		void settingsPageInit();
		void display(sf::RenderWindow &window);		
		void handleKeys(sf::RenderWindow &window);
		void handleGameMode(sf::Vector2i mousePos);
		void handleAiMode(sf::Vector2i mousePos);
		void handleVolume(sf::Vector2i mousePos);
};
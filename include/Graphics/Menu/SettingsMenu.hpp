/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 22:26:34 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class SettingsMenu {
	private:
		sf::Texture		_settingsTexture;
		sf::Texture		_boxTexture;
		sf::Texture		_boxCheckedTexture;
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
		sf::Texture		_returnButtonTexture;
		sf::Texture		_returnButtonHoverTexture;
		sf::Texture		_switchTextureOn;
		sf::Texture		_switchTextureOff;
		sf::Sprite		_settings;
		sf::Sprite		_box1;
		sf::Sprite		_box2;
		sf::Sprite		_box3;
		sf::Sprite		_box4;
		sf::Sprite		_speaker;
		sf::Sprite		_volume;
		sf::Sprite		_returnButton;
		sf::Sprite		_switch;

	public:
		SettingsMenu();
		~SettingsMenu();

		void init();
		void display(sf::RenderWindow &window);		
		void handleKeys(sf::RenderWindow &window);
		void handleGameMode(sf::Vector2i mousePos);
		void handleAiMode(sf::Vector2i mousePos);
		void handleVolume(sf::Vector2i mousePos);
};
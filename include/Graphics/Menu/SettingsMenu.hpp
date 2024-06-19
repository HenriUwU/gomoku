/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 09:58:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class SettingsMenu {
	private:
		sf::Texture		_settingsTexture;
		sf::Texture		_boxTexture;
		sf::Texture		_boxCheckedTexture;
		sf::Texture		_volume100Texture;
		sf::Texture		_volume90Texture;
		sf::Texture		_volume80Texture;
		sf::Texture		_volume70Texture;
		sf::Texture		_volume60Texture;
		sf::Texture		_volume50Texture;
		sf::Texture		_volume40Texture;
		sf::Texture		_volume30Texture;
		sf::Texture		_volume20Texture;
		sf::Texture		_volume10Texture;
		sf::Texture		_volume0Texture;
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
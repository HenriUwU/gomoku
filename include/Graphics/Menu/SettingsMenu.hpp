/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/09 18:28:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Music;

class SettingsMenu {
	private:
		int							_currentVolumeLevel;
		sf::Sprite					_settingsMenuSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_volumeSprites[11];
		sf::Sprite					_switchButtonSprite;
		sf::Sprite					_boxImpossibleAISprite;
		sf::Sprite					_boxAggressiveAISprite;
		sf::Sprite					_boxPassiveAISprite;
		sf::Sprite					_boxDefensiveAISprite;
		sf::Texture					_settingsMenuTexture;
		sf::Texture					_backwardButtonTexture;
		sf::Texture					_backwardHoveredButtonTexture;
		sf::Texture					_switchOnButtonTexture;
		sf::Texture					_switchOffButtonTexture;
		sf::Texture					_boxTexture;
		sf::Texture					_boxCheckedTexture;
		std::vector<sf::Texture>	_volumeTextures;

	public:
		SettingsMenu();
		~SettingsMenu();

		void init();
		void display(sf::RenderWindow& window);		
		void handleKeys(const sf::Event& event, const sf::RenderWindow& window);
		void handleAiMode(const sf::RenderWindow& window);
		void handleVolume(const sf::Event& event, const sf::RenderWindow& window, Music& music);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/04 11:56:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class SettingsMenu {
	private:
		int							_currentVolumeLevel;
		sf::Texture					_settingsMenuTexture;
		sf::Texture					_backwardButtonTexture;
		sf::Texture					_backwardHoveredButtonTexture;
		std::vector<sf::Texture>	_volumeTextures;
		sf::Texture					_switchOnButtonTexture;
		sf::Texture					_switchOffButtonTexture;
		sf::Texture					_boxTexture;
		sf::Texture					_boxCheckedTexture;
		sf::Sprite					_settingsMenuSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_volumeSprites[11];
		sf::Sprite					_switchButtonSprite;
		sf::Sprite					_boxImpossibleAISprite;
		sf::Sprite					_boxAggressiveAISprite;
		sf::Sprite					_boxPassiveAISprite;
		sf::Sprite					_boxDefensiveAISprite;

	public:
		SettingsMenu();
		~SettingsMenu();

		void init();
		void display(sf::RenderWindow &window);		
		void handleKeys(sf::Event &event, sf::RenderWindow &window);
		void handleAiMode(sf::RenderWindow &window);
		void handleVolume(sf::Event &event, sf::RenderWindow &window);
};
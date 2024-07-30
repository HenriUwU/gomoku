/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/22 14:22:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Music;

class SettingsMenu {
	private:
		enum Enum {
			PAGE,
			BACKWARDBUTTON,
			BACKWARDHOVEREDBUTTON,
			SWITCHONBUTTON,
			SWITCHOFFBUTTON,
			BOX,
			CHECKEDBOX
		};
	
		int							_currentVolumeLevel;
		sf::Sprite					_settingsMenuSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_volumeSprites[11];
		sf::Sprite					_switchButtonSprite;
		sf::Sprite					_boxImpossibleAISprite;
		sf::Sprite					_boxAggressiveAISprite;
		sf::Sprite					_boxPassiveAISprite;
		sf::Sprite					_boxDefensiveAISprite;
		std::vector<sf::Texture>	_pageTextures;
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
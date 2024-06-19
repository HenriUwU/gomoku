/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:42 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 11:57:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class SettingsMenu {
	private:
		sf::Texture		_settingsMenuTexture;
		sf::Texture		_backwardButtonTexture;
		sf::Texture		_backwardHoveredButtonTexture;
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
		sf::Texture		_switchOnButtonTexture;
		sf::Texture		_switchOffButtonTexture;
		sf::Texture		_boxTexture;
		sf::Texture		_boxCheckedTexture;
		sf::Sprite		_settingsMenuSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_volumeBarSprite;
		sf::Sprite		_switchButtonSprite;
		sf::Sprite		_boxImpossibleAISprite;
		sf::Sprite		_boxAggressiveAISprite;
		sf::Sprite		_boxPassiveAISprite;
		sf::Sprite		_boxDefensiveAISprite;

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
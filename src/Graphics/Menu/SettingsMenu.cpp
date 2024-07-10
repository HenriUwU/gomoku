/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/09 22:31:16 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu() {
	init();
}

SettingsMenu::~SettingsMenu() {}

void	SettingsMenu::display(sf::RenderWindow& window) {
	handleAiMode(window);

	if (moveSuggestion == ENABLED)
		_switchButtonSprite.setTexture(_pageTextures[SWITCHONBUTTON]);
	else
		_switchButtonSprite.setTexture(_pageTextures[SWITCHOFFBUTTON]);

	if (aiMode == IMPOSSIBLE) {
		_boxImpossibleAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxAggressiveAISprite.setTexture(_pageTextures[BOX]);
		_boxPassiveAISprite.setTexture(_pageTextures[BOX]);
		_boxDefensiveAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == PASSIVE) {
		_boxAggressiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxPassiveAISprite.setTexture(_pageTextures[BOX]);
		_boxDefensiveAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == AGGRESSIVE) {
		_boxPassiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxDefensiveAISprite.setTexture(_pageTextures[BOX]);
		_boxAggressiveAISprite.setTexture(_pageTextures[BOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == DEFENSIVE) {
		_boxDefensiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxAggressiveAISprite.setTexture(_pageTextures[BOX]);
		_boxPassiveAISprite.setTexture(_pageTextures[BOX]);
	}

	window.draw(_settingsMenuSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_switchButtonSprite);
	window.draw(_boxImpossibleAISprite);
	window.draw(_boxAggressiveAISprite);
	window.draw(_boxPassiveAISprite);
	window.draw(_boxDefensiveAISprite);
	window.draw(_volumeSprites[_currentVolumeLevel]);
}

void	SettingsMenu::handleKeys(const sf::Event& event, const sf::RenderWindow& window) {
	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);

	if (gameState != SETTINGS)
		return;

	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON2]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			gameState = MENU;
		}
	} else
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON2]);

	if (_switchButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (moveSuggestion == ENABLED)
				moveSuggestion = DISABLED;
			else
				moveSuggestion = ENABLED;
		}
	}
}

void	SettingsMenu::handleVolume(const sf::Event& event, const sf::RenderWindow& window, Music& music) {
	int barX = 787;
	int barY = 335;
	int barWidth = 450;
	int barHeight = 40;
	
	if (gameState != SETTINGS)
		return;
	
	if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (mousePos.y >= barY && mousePos.y <= barY + barHeight) {
			int relativeX = mousePos.x - barX;
			if (relativeX >= 0 && relativeX <= barWidth) {
				int newVolumeLevel = (relativeX * 11) / barWidth;
				if (newVolumeLevel >= 0 && newVolumeLevel < 11) {
					_currentVolumeLevel = newVolumeLevel;
					newVolumeLevel = musicVolume;
					float volume = (_currentVolumeLevel / static_cast<float>(11 - 1)) * 100;
					music.defineVolume(volume);
				}
			}
		}
	}
}

void	SettingsMenu::handleAiMode(const sf::RenderWindow& window) {
	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);
	
	if (_boxImpossibleAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxImpossibleAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = IMPOSSIBLE;
	} else if (_boxAggressiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxAggressiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = PASSIVE;
	} else if (_boxPassiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxPassiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = AGGRESSIVE;
	} else if (_boxDefensiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxDefensiveAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = DEFENSIVE;
	} else if (aiMode == NOAIMODE) {
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxAggressiveAISprite.setTexture(_pageTextures[BOX]);
		_boxPassiveAISprite.setTexture(_pageTextures[BOX]);
		_boxDefensiveAISprite.setTexture(_pageTextures[BOX]);
	}
}

void	SettingsMenu::init() {
	const std::string	settingsMenu[] = {"settingsMenu"};
	const std::string	backwardButton[] = {"backwardButton", "backwardHoveredButton"};
	const std::string	volumeLevels[] = {"volume0", "volume10", "volume20", "volume30", "volume40", "volume50", "volume60", "volume70", "volume80", "volume90", "volume100"};
	const std::string	switchButton[] = {"switchOnButton", "switchOffButton"};
	const std::string	box[] = {"box", "boxChecked"};
	
	loadTextures(1, "assets/images/menu/settings/", settingsMenu, "Texture.png", _pageTextures);
	loadTextures(2, "assets/images/buttons/", backwardButton, "Texture.png", _pageTextures);
	loadTextures(11, "assets/images/menu/settings/volume/", volumeLevels, "Texture.png", _volumeTextures);
	loadTextures(2, "assets/images/menu/settings/switch/", switchButton, "Texture.png", _pageTextures);
	loadTextures(2, "assets/images/menu/settings/box/", box, "Texture.png", _pageTextures);
	
	for (int i = 0; i < 11; i++) {
		_volumeSprites[i].setTexture(_volumeTextures[i]);
		_volumeSprites[i].setPosition(787, 335);
	}

	_currentVolumeLevel = 10;
	_settingsMenuSprite.setTexture(_pageTextures[SETTINGSPAGE]);
	_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON2]);
	_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
	_boxAggressiveAISprite.setTexture(_pageTextures[BOX]);
	_boxPassiveAISprite.setTexture(_pageTextures[BOX]);
	_boxDefensiveAISprite.setTexture(_pageTextures[BOX]);

	_backwardButtonSprite.setPosition(100, 104);
	_switchButtonSprite.setPosition(890, 582);
	_boxImpossibleAISprite.setPosition(683, 724);
	_boxAggressiveAISprite.setPosition(683, 810);
	_boxPassiveAISprite.setPosition(990, 723);
	_boxDefensiveAISprite.setPosition(990, 810);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/12/21 14:55:52 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics/Menu/SettingsMenu.hpp"

SettingsMenu::SettingsMenu() {
	init();
}

SettingsMenu::~SettingsMenu() {}

void	SettingsMenu::display(sf::RenderWindow& window) {
	handleAiMode(window);

	if (moveSuggestion == true)
		_switchButtonSprite.setTexture(_pageTextures[SWITCHONBUTTON]);
	else
		_switchButtonSprite.setTexture(_pageTextures[SWITCHOFFBUTTON]);

	if (aiMode == IMPOSSIBLE) {
		_boxImpossibleAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxChallengingAISprite.setTexture(_pageTextures[BOX]);
		_boxCrazyAISprite.setTexture(_pageTextures[BOX]);
		_boxEasyAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == CRAZY) {
		_boxChallengingAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxCrazyAISprite.setTexture(_pageTextures[BOX]);
		_boxEasyAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == CHALLENGING) {
		_boxCrazyAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxEasyAISprite.setTexture(_pageTextures[BOX]);
		_boxChallengingAISprite.setTexture(_pageTextures[BOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
	} else if (aiMode == EASY) {
		_boxEasyAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxChallengingAISprite.setTexture(_pageTextures[BOX]);
		_boxCrazyAISprite.setTexture(_pageTextures[BOX]);
	}

	window.draw(_settingsMenuSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_switchButtonSprite);
	window.draw(_boxImpossibleAISprite);
	window.draw(_boxChallengingAISprite);
	window.draw(_boxCrazyAISprite);
	window.draw(_boxEasyAISprite);
	window.draw(_volumeSprites[_currentVolumeLevel]);
}

void	SettingsMenu::handleKeys(const sf::Event& event, const sf::RenderWindow& window) {
	if (gameState != SETTINGS)
		return;

	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);
	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDHOVEREDBUTTON]);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			gameState = MENU;
		}
	} else
		_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);

	if (_switchButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (moveSuggestion == true)
				moveSuggestion = false;
			else
				moveSuggestion = true;
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
	} else if (_boxChallengingAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxChallengingAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = CRAZY;
	} else if (_boxCrazyAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxCrazyAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = CHALLENGING;
	} else if (_boxEasyAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxEasyAISprite.setTexture(_pageTextures[CHECKEDBOX]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = EASY;
	} else if (aiMode == NOAIMODE) {
		_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
		_boxChallengingAISprite.setTexture(_pageTextures[BOX]);
		_boxCrazyAISprite.setTexture(_pageTextures[BOX]);
		_boxEasyAISprite.setTexture(_pageTextures[BOX]);
	}
}

void	SettingsMenu::init() {
	const std::string	page[] = {"settingsMenu"};
	const std::string	button[] = {"backwardButton", "backwardHoveredButton"};
	const std::string	volume[] = {"volume0", "volume10", "volume20", "volume30", "volume40", "volume50", "volume60", "volume70", "volume80", "volume90", "volume100"};
	const std::string	switchb[] = {"switchOnButton", "switchOffButton"};
	const std::string	box[] = {"box", "boxChecked"};
	
	loadTextures(1, "assets/images/menu/settings/", page, _pageTextures);
	loadTextures(2, "assets/images/buttons/", button, _pageTextures);
	loadTextures(11, "assets/images/menu/settings/volume/", volume, _volumeTextures);
	loadTextures(2, "assets/images/menu/settings/switch/", switchb, _pageTextures);
	loadTextures(2, "assets/images/menu/settings/box/", box, _pageTextures);
	
	for (int i = 0; i < 11; i++) {
		_volumeSprites[i].setTexture(_volumeTextures[i]);
		_volumeSprites[i].setPosition(787, 335);
	}

	_currentVolumeLevel = 10;
	_settingsMenuSprite.setTexture(_pageTextures[PAGE]);
	_backwardButtonSprite.setTexture(_pageTextures[BACKWARDBUTTON]);
	_boxImpossibleAISprite.setTexture(_pageTextures[BOX]);
	_boxChallengingAISprite.setTexture(_pageTextures[BOX]);
	_boxCrazyAISprite.setTexture(_pageTextures[BOX]);
	_boxEasyAISprite.setTexture(_pageTextures[BOX]);

	_backwardButtonSprite.setPosition(100, 104);
	_switchButtonSprite.setPosition(890, 582);
	_boxImpossibleAISprite.setPosition(683, 724);
	_boxChallengingAISprite.setPosition(683, 810);
	_boxCrazyAISprite.setPosition(1030, 723);
	_boxEasyAISprite.setPosition(1030, 810);
}
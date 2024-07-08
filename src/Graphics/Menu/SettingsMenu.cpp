/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/04 20:12:35 by laprieur         ###   ########.fr       */
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
		_switchButtonSprite.setTexture(_switchOnButtonTexture);
	else
		_switchButtonSprite.setTexture(_switchOffButtonTexture);

	if (aiMode == IMPOSSIBLE) {
		_boxImpossibleAISprite.setTexture(_boxCheckedTexture);
		_boxAggressiveAISprite.setTexture(_boxTexture);
		_boxPassiveAISprite.setTexture(_boxTexture);
		_boxDefensiveAISprite.setTexture(_boxTexture);
	} else if (aiMode == PASSIVE) {
		_boxAggressiveAISprite.setTexture(_boxCheckedTexture);
		_boxImpossibleAISprite.setTexture(_boxTexture);
		_boxPassiveAISprite.setTexture(_boxTexture);
		_boxDefensiveAISprite.setTexture(_boxTexture);
	} else if (aiMode == AGGRESSIVE) {
		_boxPassiveAISprite.setTexture(_boxCheckedTexture);
		_boxDefensiveAISprite.setTexture(_boxTexture);
		_boxAggressiveAISprite.setTexture(_boxTexture);
		_boxImpossibleAISprite.setTexture(_boxTexture);
	} else if (aiMode == DEFENSIVE) {
		_boxDefensiveAISprite.setTexture(_boxCheckedTexture);
		_boxImpossibleAISprite.setTexture(_boxTexture);
		_boxAggressiveAISprite.setTexture(_boxTexture);
		_boxPassiveAISprite.setTexture(_boxTexture);
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

	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			gameState = MENU;
		}
	} else
		_backwardButtonSprite.setTexture(_backwardButtonTexture);

	if (_switchButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (moveSuggestion == ENABLED)
				moveSuggestion = DISABLED;
			else
				moveSuggestion = ENABLED;
		}
	}
}

void	SettingsMenu::handleVolume(const sf::Event& event, const sf::RenderWindow& window) {	
	int barX = 787;
	int barY = 335;
	int barWidth = 450;
	int barHeight = 40;
	
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
					sound.setVolume(volume);
				}
			}
		}
	}
}

void	SettingsMenu::handleAiMode(const sf::RenderWindow& window) {
	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);
	
	if (_boxImpossibleAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxImpossibleAISprite.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = IMPOSSIBLE;
	} else if (_boxAggressiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxAggressiveAISprite.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = PASSIVE;
	} else if (_boxPassiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxPassiveAISprite.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = AGGRESSIVE;
	} else if (_boxDefensiveAISprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_boxDefensiveAISprite.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			aiMode = DEFENSIVE;
	} else if (aiMode == NOAIMODE) {
		_boxImpossibleAISprite.setTexture(_boxTexture);
		_boxAggressiveAISprite.setTexture(_boxTexture);
		_boxPassiveAISprite.setTexture(_boxTexture);
		_boxDefensiveAISprite.setTexture(_boxTexture);
	}
}

void	SettingsMenu::init() {
	if (!_settingsMenuTexture.loadFromFile("assets/images/menu/settings/settingsMenuTexture.png"))
		std::cerr << "Error: could not load settings texture" << std::endl;
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/backwardButtonTexture.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/backwardHoveredButtonTexture.png"))
		std::cerr << "Error: could not load return button hover texture" << std::endl;
	if (!_switchOnButtonTexture.loadFromFile("assets/images/menu/settings/moveSuggestion/switchOnButtonTexture.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;
	if (!_switchOffButtonTexture.loadFromFile("assets/images/menu/settings/moveSuggestion/switchOffButtonTexture.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;
	if (!_boxTexture.loadFromFile("assets/images/menu/settings/aiMode/boxTexture.png"))
		std::cerr << "Error: could not load box texture" << std::endl;
	if (!_boxCheckedTexture.loadFromFile("assets/images/menu/settings/aiMode/boxCheckedTexture.png"))
		std::cerr << "Error: could not load box checked texture" << std::endl;

	for (int i = 0; i < 11; i++) {
		sf::Texture texture;
		std::string	filePath = "assets/images/menu/settings/volume/volume" + std::to_string(i * 10) + "Texture.png";
		if (texture.loadFromFile(filePath))
			_volumeTextures.push_back(texture);
	}
	
	for (int i = 0; i < 11; i++) {
		_volumeSprites[i].setTexture(_volumeTextures[i]);
		_volumeSprites[i].setPosition(787, 335);
	}

	_currentVolumeLevel = 10;
	_settingsMenuSprite.setTexture(_settingsMenuTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_boxImpossibleAISprite.setTexture(_boxTexture);
	_boxAggressiveAISprite.setTexture(_boxTexture);
	_boxPassiveAISprite.setTexture(_boxTexture);
	_boxDefensiveAISprite.setTexture(_boxTexture);

	_backwardButtonSprite.setPosition(100, 104);
	_switchButtonSprite.setPosition(890, 582);
	_boxImpossibleAISprite.setPosition(683, 724);
	_boxAggressiveAISprite.setPosition(683, 810);
	_boxPassiveAISprite.setPosition(990, 723);
	_boxDefensiveAISprite.setPosition(990, 810);
}
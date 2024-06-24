/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsMenu.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/24 11:57:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu() {
	init();
}

SettingsMenu::~SettingsMenu() {}

void	SettingsMenu::display(sf::RenderWindow& window) {
	handleKeys(window);

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

	window.clear(sf::Color(38, 1, 69));
	window.draw(_settingsMenuSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_volumeBarSprite);
	window.draw(_switchButtonSprite);
	window.draw(_boxImpossibleAISprite);
	window.draw(_boxAggressiveAISprite);
	window.draw(_boxPassiveAISprite);
	window.draw(_boxDefensiveAISprite);
}

void	SettingsMenu::handleKeys(sf::RenderWindow& window) {
	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);

	if (_backwardButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = MENU;
		}
	} else
		_backwardButtonSprite.setTexture(_backwardButtonTexture);

	if (_switchButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (moveSuggestion == ENABLED)
				moveSuggestion = DISABLED;
			else
				moveSuggestion = ENABLED;
			sf::sleep(sf::milliseconds(100));
		}
	}
	
	handleVolume(mousePos);
	handleAiMode(mousePos);
}

void	SettingsMenu::handleVolume(sf::Vector2i mousePos) {
	(void)mousePos;
}

void	SettingsMenu::handleAiMode(sf::Vector2i mousePos) {
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
	if (!_volume100Texture.loadFromFile("assets/images/menu/settings/volume/volume100Texture.png"))
		std::cerr << "Error: could not load volume 100 texture" << std::endl;
	if (!_switchOnButtonTexture.loadFromFile("assets/images/menu/settings/moveSuggestion/switchOnButtonTexture.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;
	if (!_switchOffButtonTexture.loadFromFile("assets/images/menu/settings/moveSuggestion/switchOffButtonTexture.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;
	if (!_boxTexture.loadFromFile("assets/images/menu/settings/aiMode/boxTexture.png"))
		std::cerr << "Error: could not load box texture" << std::endl;
	if (!_boxCheckedTexture.loadFromFile("assets/images/menu/settings/aiMode/boxCheckedTexture.png"))
		std::cerr << "Error: could not load box checked texture" << std::endl;

	_settingsMenuSprite.setTexture(_settingsMenuTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_volumeBarSprite.setTexture(_volume100Texture);
	_boxImpossibleAISprite.setTexture(_boxTexture);
	_boxAggressiveAISprite.setTexture(_boxTexture);
	_boxPassiveAISprite.setTexture(_boxTexture);
	_boxDefensiveAISprite.setTexture(_boxTexture);

	_backwardButtonSprite.setPosition(100, 104);
	_volumeBarSprite.setPosition(787, 335);
	_switchButtonSprite.setPosition(890, 582);
	_boxImpossibleAISprite.setPosition(683, 724);
	_boxAggressiveAISprite.setPosition(683, 810);
	_boxPassiveAISprite.setPosition(990, 723);
	_boxDefensiveAISprite.setPosition(990, 810);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsPage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 21:01:27 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SettingsPage.hpp"

SettingsPage::SettingsPage() {
	settingsPageInit();
}

SettingsPage::~SettingsPage() {}

void	SettingsPage::display(sf::RenderWindow& window) {
	handleKeys(window);

	if (moveSuggestion == ENABLED)
		_switch.setTexture(_switchTextureOn);
	else
		_switch.setTexture(_switchTextureOff);

	if (aiMode == IMPOSSIBLE) {
		_box1.setTexture(_boxCheckedTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	else if (aiMode == PASSIVE) {
		_box2.setTexture(_boxCheckedTexture);
		_box1.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	else if (aiMode == AGGRESSIVE) {
		_box3.setTexture(_boxCheckedTexture);
		_box4.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box1.setTexture(_boxTexture);
	}
	else if (aiMode == DEFENSIVE) {
		_box4.setTexture(_boxCheckedTexture);
		_box1.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
	}

	window.clear(sf::Color(38, 1, 69));
	window.draw(_settings);
	window.draw(_box1);
	window.draw(_box2);
	window.draw(_box3);
	window.draw(_box4);
	window.draw(_speaker);
	window.draw(_volume);
	window.draw(_returnButton);
	window.draw(_switch);
}

void	SettingsPage::handleKeys(sf::RenderWindow& window) {
	sf::Vector2i	mousePos = sf::Mouse::getPosition(window);

	if (_returnButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_returnButton.setTexture(_returnButtonHoverTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = MENU;
		}
	}
	else
		_returnButton.setTexture(_returnButtonTexture);

	if (_switch.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
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

void	SettingsPage::handleVolume(sf::Vector2i mousePos) {
	(void)mousePos;
}

void	SettingsPage::handleAiMode(sf::Vector2i mousePos) {
	if (_box1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box1.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = IMPOSSIBLE;
		}
	}
	else if (_box2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box2.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = PASSIVE;
		}
	}
	else if (_box3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box3.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = AGGRESSIVE;
		}
	}
	else if (_box4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box4.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = DEFENSIVE;
		}
	}
	else if (aiMode == NOAIMODE) {
		_box1.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
}

void	SettingsPage::settingsPageInit() {
	if (!_boxTexture.loadFromFile("assets/images/icons/box.png"))
		std::cerr << "Error: could not load box texture" << std::endl;
	if (!_boxCheckedTexture.loadFromFile("assets/images/icons/box_checked.png"))
		std::cerr << "Error: could not load box checked texture" << std::endl;
	if (!_volume_100Texture.loadFromFile("assets/images/icons/volume_100.png"))
		std::cerr << "Error: could not load volume 100 texture" << std::endl;
	if (!_returnButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_returnButtonHoverTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load return button hover texture" << std::endl;
	if (!_settingsTexture.loadFromFile("assets/settingsPage/Settings_Gomoku.png"))
		std::cerr << "Error: could not load settings texture" << std::endl;
	if (!_switchTextureOn.loadFromFile("assets/images/buttons/On_Switch.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;
	if (!_switchTextureOff.loadFromFile("assets/images/buttons/Off_Switch.png"))
		std::cerr << "Error: could not load switch texture" << std::endl;

	_settings.setTexture(_settingsTexture);
	_box1.setTexture(_boxTexture);
	_box2.setTexture(_boxTexture);
	_box3.setTexture(_boxTexture);
	_box4.setTexture(_boxTexture);
	_volume.setTexture(_volume_100Texture);
	_returnButton.setTexture(_returnButtonTexture);

	_box1.setPosition(683, 724);
	_box2.setPosition(683, 810);
	_box3.setPosition(990, 723);
	_box4.setPosition(990, 810);
	_volume.setPosition(787, 335);
	_returnButton.setPosition(100, 104);
	_switch.setPosition(890, 582);
}
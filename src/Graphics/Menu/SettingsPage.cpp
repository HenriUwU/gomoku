/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsPage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 17:38:48 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SettingsPage.hpp"

SettingsPage::SettingsPage() {
	settingsPageInit();
}

SettingsPage::~SettingsPage() {}

void	SettingsPage::settingsPageInit() {
	if (!_boxTexture.loadFromFile("assets/images/icons/box.png"))
		std::cerr << "Error: could not load box texture" << std::endl;
	if (!_boxCheckedTexture.loadFromFile("assets/images/icons/box_checked.png"))
		std::cerr << "Error: could not load box checked texture" << std::endl;
	if (!_speakerTexture.loadFromFile("assets/images/icons/speaker.png"))
		std::cerr << "Error: could not load speaker texture" << std::endl;
	if (!_volume_100Texture.loadFromFile("assets/images/icons/volume_100.png"))
		std::cerr << "Error: could not load volume 100 texture" << std::endl;
	if (!_sparklesTexture.loadFromFile("assets/images/icons/sparkles.png"))
		std::cerr << "Error: could not load sparkles texture" << std::endl;
	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		std::cerr << "Error: could not load Exo2-Black font" << std::endl;
	if (!_exo2BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		std::cerr << "Error: could not load Exo2-BlackItalic font" << std::endl;
	if (!_returnButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_returnButtonHoverTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load return button hover texture" << std::endl;

	_box.setTexture(_boxTexture);
	_box2.setTexture(_boxTexture);
	_box3.setTexture(_boxTexture);
	_box4.setTexture(_boxTexture);
	_box5.setTexture(_boxTexture);
	_box6.setTexture(_boxTexture);
	_box7.setTexture(_boxTexture);
	_box8.setTexture(_boxTexture);
	_speaker.setTexture(_speakerTexture);
	_volume.setTexture(_volume_100Texture);
	_sparkles.setTexture(_sparklesTexture);
	_returnButton.setTexture(_returnButtonTexture);

	_box.setPosition(683, 493);
	_box2.setPosition(683, 579);
	_box3.setPosition(990, 493);
	_box4.setPosition(990, 579);
	_box5.setPosition(683, 724);
	_box6.setPosition(683, 810);
	_box7.setPosition(990, 723);
	_box8.setPosition(990, 810);
	_speaker.setPosition(684, 315);
	_volume.setPosition(787, 335);
	_sparkles.setPosition(1123, 254);
	_returnButton.setPosition(34, 34);
}

void	SettingsPage::display(sf::RenderWindow& window) {
	sf::RectangleShape	leftLine(sf::Vector2f(171, 5));
	sf::RectangleShape	rightLine(sf::Vector2f(171, 5));
	sf::RectangleShape	leftLine2(sf::Vector2f(197, 5));
	sf::RectangleShape rightLine2(sf::Vector2f(197, 5));
	sf::Text		gameModeText("Game mode", _exo2BlackFont, 30);
	sf::Text		aiModeText("AI Mode", _exo2BlackFont, 30);
	sf::Text		standard("Standard", _exo2BlackFont, 35);
	sf::Text		pro("Pro", _exo2BlackFont, 35);
	sf::Text		swap("Swap", _exo2BlackFont, 35);
	sf::Text		swap2("Swap2", _exo2BlackFont, 35);
	sf::Text		impossible("Impossible", _exo2BlackFont, 35);
	sf::Text		passive("Passive", _exo2BlackFont, 35);
	sf::Text		aggressive("Aggressive", _exo2BlackFont, 35);
	sf::Text		defensive("Defensive", _exo2BlackFont, 35);
	sf::Text		settings("Settings", _exo2BlackFont, 135);
	sf::Text		settingsShadow("Settings", _exo2BlackFont, 135);
	sf::Text		whereTheMagicBegins("Where the magic begins", _exo2BlackFont, 30);
	sf::Text		backToMenu("Back to menu", _exo2BlackItalicFont, 20);

	settingsShadow.setFillColor(sf::Color(193, 167, 252));

	leftLine.setPosition(683, 445);
	rightLine.setPosition(1066, 445);
	leftLine2.setPosition(683, 676);
	rightLine2.setPosition(1040, 676);
	standard.setPosition(753, 495);
	pro.setPosition(753, 581);
	swap.setPosition(1060, 497);
	swap2.setPosition(1060, 583);
	impossible.setPosition(753, 726);
	aggressive.setPosition(753, 813);
	passive.setPosition(1060, 724);
	defensive.setPosition(1060, 811);
	gameModeText.setPosition(874, 429);
	aiModeText.setPosition(900, 660);
	settings.setPosition(683, 60);
	settingsShadow.setPosition(683, 70);
	whereTheMagicBegins.setPosition(756, 254);
	backToMenu.setPosition(114, 54);

	handleKeys(window);

	if (gameMode == STANDARD) {
		_box.setTexture(_boxCheckedTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	if (gameMode == PRO) {
		_box2.setTexture(_boxCheckedTexture);
		_box.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	else if (gameMode == SWAP) {
		_box3.setTexture(_boxCheckedTexture);
		_box.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	else if (gameMode == SWAP2) {
		_box4.setTexture(_boxCheckedTexture);
		_box.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
	}

	if (aiMode == IMPOSSIBLE) {
		_box5.setTexture(_boxCheckedTexture);
		_box6.setTexture(_boxTexture);
		_box7.setTexture(_boxTexture);
		_box8.setTexture(_boxTexture);
	}
	else if (aiMode == PASSIVE) {
		_box6.setTexture(_boxCheckedTexture);
		_box5.setTexture(_boxTexture);
		_box7.setTexture(_boxTexture);
		_box8.setTexture(_boxTexture);
	}
	else if (aiMode == AGGRESSIVE) {
		_box7.setTexture(_boxCheckedTexture);
		_box5.setTexture(_boxTexture);
		_box6.setTexture(_boxTexture);
		_box8.setTexture(_boxTexture);
	}
	else if (aiMode == DEFENSIVE) {
		_box8.setTexture(_boxCheckedTexture);
		_box5.setTexture(_boxTexture);
		_box6.setTexture(_boxTexture);
		_box7.setTexture(_boxTexture);
	}

	window.clear(sf::Color(38, 1, 69));
	window.draw(leftLine);
	window.draw(rightLine);
	window.draw(leftLine2);
	window.draw(rightLine2);
	window.draw(_box);
	window.draw(_box2);
	window.draw(_box3);
	window.draw(_box4);
	window.draw(_box5);
	window.draw(_box6);
	window.draw(_box7);
	window.draw(_box8);
	window.draw(_speaker);
	window.draw(standard);
	window.draw(pro);
	window.draw(swap);
	window.draw(swap2);
	window.draw(impossible);
	window.draw(passive);
	window.draw(aggressive);
	window.draw(defensive);
	window.draw(gameModeText);
	window.draw(aiModeText);
	window.draw(_volume);
	window.draw(settingsShadow);
	window.draw(settings);
	window.draw(_sparkles);
	window.draw(whereTheMagicBegins);
	window.draw(_returnButton);
	window.draw(backToMenu);
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

	if (_box.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (gameMode == NOGAMEMODE)
			_box.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameMode = STANDARD;
		}
	}
	else if (_box2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (gameMode == NOGAMEMODE)
			_box2.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameMode = PRO;
		}
	}
	else if (_box3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (gameMode == NOGAMEMODE)
			_box3.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameMode = SWAP;
		}
	}
	else if (_box4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (gameMode == NOGAMEMODE)
			_box4.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameMode = SWAP2;
		}
	}
	else if (gameMode == NOGAMEMODE) {
		_box.setTexture(_boxTexture);
		_box2.setTexture(_boxTexture);
		_box3.setTexture(_boxTexture);
		_box4.setTexture(_boxTexture);
	}
	
	if (_box5.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box5.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = IMPOSSIBLE;
		}
	}
	else if (_box6.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box6.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = PASSIVE;
		}
	}
	else if (_box7.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box7.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = AGGRESSIVE;
		}
	}
	else if (_box8.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (aiMode == NOAIMODE)
			_box8.setTexture(_boxCheckedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			aiMode = DEFENSIVE;
		}
	}
	else if (aiMode == NOAIMODE) {
		_box5.setTexture(_boxTexture);
		_box6.setTexture(_boxTexture);
		_box7.setTexture(_boxTexture);
		_box8.setTexture(_boxTexture);
	}
}
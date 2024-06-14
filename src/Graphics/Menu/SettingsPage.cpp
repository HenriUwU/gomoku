/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SettingsPage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:24 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/14 16:00:17 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

void	MainMenu::settingsPage(sf::RenderWindow& window) {
	window.clear(sf::Color(38, 1, 69));

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::RectangleShape leftLine(sf::Vector2f(171, 5));
	sf::RectangleShape rightLine(sf::Vector2f(171, 5));
	sf::RectangleShape leftLine2(sf::Vector2f(197, 5));
	sf::RectangleShape rightLine2(sf::Vector2f(197, 5));
	sf::Texture		boxTexture;
	sf::Texture		boxCheckedTexture;
	sf::Texture		speakerTexture;
	sf::Texture		volume_100Texture;
	sf::Texture		sparklesTexture;
	sf::Sprite		box;
	sf::Sprite		box2;
	sf::Sprite		box3;
	sf::Sprite		box4;
	sf::Sprite		box5;
	sf::Sprite		box6;
	sf::Sprite		box7;
	sf::Sprite		box8;
	sf::Sprite		speaker;
	sf::Sprite		volume;
	sf::Sprite		sparkles;
	sf::Text		gameMode("Game mode", _exo2BlackFont, 30);
	sf::Text		aiMode("AI Mode", _exo2BlackFont, 30);
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
	sf::Text		backToMenu("Back to menu", _ex02BlackItalicFont, 20);

	if (!boxTexture.loadFromFile("assets/images/icons/box.png"))
		std::cerr << "Error: could not load box texture" << std::endl;
/* 	if (!boxCheckedTexture.loadFromFile("assets/images/icons/box_checked.png"))
		std::cerr << "Error: could not load box checked texture" << std::endl; */
	if (!speakerTexture.loadFromFile("assets/images/icons/speaker.png"))
		std::cerr << "Error: could not load speaker texture" << std::endl;
	if (!volume_100Texture.loadFromFile("assets/images/icons/volume_100.png"))
		std::cerr << "Error: could not load volume 100 texture" << std::endl;
	if (!sparklesTexture.loadFromFile("assets/images/icons/sparkles.png"))
		std::cerr << "Error: could not load sparkles texture" << std::endl;
		
	box.setTexture(boxTexture);
	box2.setTexture(boxTexture);
	box3.setTexture(boxTexture);
	box4.setTexture(boxTexture);
	box5.setTexture(boxTexture);
	box6.setTexture(boxTexture);
	box7.setTexture(boxTexture);
	box8.setTexture(boxTexture);
	speaker.setTexture(speakerTexture);
	volume.setTexture(volume_100Texture);
	sparkles.setTexture(sparklesTexture);
	_leftArrowIconSprite.setTexture(_arrowIconTexture);
	settingsShadow.setFillColor(sf::Color(193, 167, 252));

	leftLine.setPosition(683, 445);
	rightLine.setPosition(1066, 445);
	leftLine2.setPosition(683, 676);
	rightLine2.setPosition(1040, 676);
	box.setPosition(683, 493);
	box2.setPosition(683, 579);
	box3.setPosition(990, 493);
	box4.setPosition(990, 579);
	box5.setPosition(683, 724);
	box6.setPosition(683, 810);
	box7.setPosition(990, 723);
	box8.setPosition(990, 810);
	speaker.setPosition(684, 315);
	standard.setPosition(753, 495);
	pro.setPosition(753, 581);
	swap.setPosition(1060, 497);
	swap2.setPosition(1060, 583);
	impossible.setPosition(753, 726);
	aggressive.setPosition(753, 813);
	passive.setPosition(1060, 724);
	defensive.setPosition(1060, 811);
	gameMode.setPosition(874, 429);
	aiMode.setPosition(900, 660);
	volume.setPosition(787, 335);
	settings.setPosition(683, 60);
	settingsShadow.setPosition(683, 70);
	sparkles.setPosition(1123, 254);
	whereTheMagicBegins.setPosition(756, 254);
	backToMenu.setPosition(114, 54);
	_leftArrowIconSprite.setPosition(34, 34);

	if (_leftArrowIconSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		_leftArrowIconSprite.setTexture(_arrowIconHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = MENU;
		}
	}
	else {
		_leftArrowIconSprite.setTexture(_arrowIconTexture);
		_rightArrowIconSprite.setTexture(_arrowIconTexture);
	}

	window.draw(leftLine);
	window.draw(rightLine);
	window.draw(leftLine2);
	window.draw(rightLine2);
	window.draw(box);
	window.draw(box2);
	window.draw(box3);
	window.draw(box4);
	window.draw(box5);
	window.draw(box6);
	window.draw(box7);
	window.draw(box8);
	window.draw(speaker);
	window.draw(standard);
	window.draw(pro);
	window.draw(swap);
	window.draw(swap2);
	window.draw(impossible);
	window.draw(passive);
	window.draw(aggressive);
	window.draw(defensive);
	window.draw(gameMode);
	window.draw(aiMode);
	window.draw(volume);
	window.draw(settingsShadow);
	window.draw(settings);
	window.draw(sparkles);
	window.draw(whereTheMagicBegins);
	window.draw(_leftArrowIconSprite);
	window.draw(backToMenu);
}
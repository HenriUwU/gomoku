/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 12:25:17 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

void	MainMenu::customPage(sf::RenderWindow& window) {
	sf::RectangleShape	stoneColorFirstBar(sf::Vector2f(155, 5));
	sf::RectangleShape	stoneColorSecondBar(sf::Vector2f(155, 5));
	sf::RectangleShape	avatarsFirstBar(sf::Vector2f(198, 5));
	sf::RectangleShape	avatarsSecondBar(sf::Vector2f(201, 5));
	sf::RectangleShape	boardColorFirstBar(sf::Vector2f(206, 5));
	sf::RectangleShape	boardColorSecondBar(sf::Vector2f(207, 5));

	stoneColorFirstBar.setPosition(682, 324);
	stoneColorSecondBar.setPosition(1082, 324);
	avatarsFirstBar.setPosition(682, 508);
	avatarsSecondBar.setPosition(1037, 508);
	boardColorFirstBar.setPosition(682, 727);
	boardColorSecondBar.setPosition(1031, 727);
	
	window.clear(sf::Color(38, 1, 69));
	window.draw(_stoneColorBandW);
	window.draw(_stoneColorBandY);
	window.draw(_stoneColorDGandLG);
	window.draw(_stoneColorGandR);
	window.draw(_stoneColorOandV);
	window.draw(_stoneColorPandFY);
	window.draw(_stoneColorSandC);
	window.draw(_stoneColorTGandI);

	window.draw(_boardColorAzure);
	window.draw(_boardColorBlack);
	window.draw(_boardColorGray);
	window.draw(_boardColorGreen);
	window.draw(_boardColorOrange);
	window.draw(_boardColorPink);
	window.draw(_boardColorRed);
	window.draw(_boardColorYellow);

	window.draw(_avatarAlex);
	window.draw(_avatarGunther);
	window.draw(_avatarHeric);
	window.draw(_avatarLaure);
	window.draw(_avatarMousse);
	window.draw(_avatarTommy);

	window.draw(stoneColorFirstBar);
	window.draw(stoneColorSecondBar);
	window.draw(avatarsFirstBar);
	window.draw(avatarsSecondBar);
	window.draw(boardColorFirstBar);
	window.draw(boardColorSecondBar);
}
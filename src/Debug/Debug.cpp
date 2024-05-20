/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:08:50 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/20 16:25:50 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"

sf::Font			Debug::_font;

Debug::Debug() {}

Debug::~Debug() {}

void	Debug::init(sf::RenderWindow &window) {
	_font.loadFromFile("assets/fonts/arial.ttf");

	sf::Text	debug("Debug:", _font, 15);
	debug.setFillColor(sf::Color::White);
	debug.setPosition(30, 830);
	window.draw(debug);
}

void	Debug::currentPos(sf::RenderWindow &window, std::string position) {
	sf::Text	currentPos("current pos = " + position, _font, 15);

	currentPos.setFillColor(sf::Color::White);
	currentPos.setPosition(30, 845);
	window.draw(currentPos);
}

void	Debug::currentPlayer(sf::RenderWindow &window, int player) {
	sf::Text	currentPlayer("current player = " + std::to_string(player), _font, 15);

	currentPlayer.setFillColor(sf::Color::White);
	currentPlayer.setPosition(30, 860);
	window.draw(currentPlayer);
}
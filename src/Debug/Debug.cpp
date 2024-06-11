/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:08:50 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/11 12:45:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"

using namespace std;
sf::Font		Debug::_font;

Debug::Debug() {}

Debug::~Debug() {}

void	Debug::init(sf::RenderWindow &window) {
	_font.loadFromFile("assets/fonts/arial.ttf");

	sf::Text	debug("Debug:", _font, 15);
	debug.setFillColor(sf::Color::White);
	debug.setPosition(30, 830);
	window.draw(debug);
}

void	Debug::currentPos(sf::RenderWindow &window, string position) {
	sf::Text	currentPos("current pos = " + position, _font, 15);

	currentPos.setFillColor(sf::Color::White);
	currentPos.setPosition(30, 845);
	window.draw(currentPos);
}

void	Debug::currentPlayer(sf::RenderWindow &window, int player) {
	sf::Text	currentPlayer("current player = " + to_string(player), _font, 15);

	currentPlayer.setFillColor(sf::Color::White);
	currentPlayer.setPosition(30, 860);
	window.draw(currentPlayer);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:08:50 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/14 11:52:32 by laprieur         ###   ########.fr       */
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
	debug.setPosition(30, 15);
	window.draw(debug);
}

void	Debug::actualPos(sf::RenderWindow &window, std::string position) {
	sf::Text	actualPos("actual pos = " + position, _font, 15);

	actualPos.setFillColor(sf::Color::White);
	actualPos.setPosition(30, 45);
	window.draw(actualPos);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 15:28:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

Graphics::Graphics(sf::RenderWindow &window) {
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
	_gridSize = _windowHeight - 75;
	_cellSize = _gridSize / 18.0f;
	_gridStartPoint = std::make_pair((_windowWidth - _windowHeight) / 2 + 35, 35);
}

Graphics::~Graphics() {}
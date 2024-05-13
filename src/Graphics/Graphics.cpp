/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 13:57:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"

Graphics::Graphics() {
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
	_cellSize = _gridSize / 18.0f;
	_gridSize = _windowHeight - 75;
	_gridStartPoint = std::make_pair((_windowWidth - _windowHeight) / 2 + 35, 35);
}

Graphics::~Graphics() {}
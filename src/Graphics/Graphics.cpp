/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 16:22:47 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Graphics::Graphics(sf::RenderWindow &window) {
	_windowWidth = window.getSize().x;
	_windowHeight = window.getSize().y;
	_gridSize = _windowHeight - 75;
	_cellSize = _gridSize / 18.0f;
	_gridStartPoint = make_pair((_windowWidth - _windowHeight) / 2 + 35, 35);

	if (!_exo2Italic.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf")) {
		cerr << "Error: could not load Exo2-Italic font" << endl;
	}
	if (!_exo2.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf")) {
		cerr << "Error: could not load Exo2-Regular font" << endl;
	}

	if (!_avatar1.loadFromFile("assets/images/avatars/bewildered_face.png")) {
		cerr << "Error: could not load avatar1 texture" << endl;
	}
	if (!_avatar2.loadFromFile("assets/images/avatars/love_face.png")) {
		cerr << "Error: could not load avatar2 texture" << endl;
	}
	if (!_avatar3.loadFromFile("assets/images/avatars/smiling_face.png")) {
		cerr << "Error: could not load avatar3 texture" << endl;
	}
	if (!_avatar4.loadFromFile("assets/images/avatars/tired_face.png")) {
		cerr << "Error: could not load avatar4 texture" << endl;
	}
	if (!_avatar5.loadFromFile("assets/images/avatars/wink_face.png")) {
		cerr << "Error: could not load avatar5 texture" << endl;
	}
	if (!_avatar6.loadFromFile("assets/images/avatars/woman_face.png")) {
		cerr << "Error: could not load avatar6 texture" << endl;
	}
	if (!_returnArrowTexture.loadFromFile("assets/images/buttons/return_arrow.png")) {
		return ;
	}
	if (!_returnArrowHighlightTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png")) {
		return ;
	}
}

Graphics::~Graphics() {}

/* string	getCoordinates(float x, float y) {
	
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 19:13:44 by laprieur         ###   ########.fr       */
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

	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		cerr << "Error while loading the 'Exo2-Black.ttf' file." << endl;
	if (!_ex02BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		cerr << "Error while loading the 'Exo2-BlackItalic.ttf' file." << endl;
	if (!_lanceAvatarTexture.loadFromFile("assets/images/avatars/lance.png"))
		cerr << "Error while loading the 'bewildered.png' file." << endl;
	if (!_tommyAvatarTexture.loadFromFile("assets/images/avatars/tommy.png"))
		cerr << "Error while loading the 'happy.png' file." << endl;
	if (!_alexAvatarTexture.loadFromFile("assets/images/avatars/alex.png"))
		cerr << "Error while loading the 'smile.png' file." << endl;
	if (!_guntherAvatarTexture.loadFromFile("assets/images/avatars/gunther.png"))
		cerr << "Error while loading the 'tired.png' file." << endl;
	if (!_hericAvatarTexture.loadFromFile("assets/images/avatars/heric.png"))
		cerr << "Error while loading the 'wink.png' file." << endl;
	if (!_laureAvatarTexture.loadFromFile("assets/images/avatars/laure.png"))
		cerr << "Error while loading the 'woman.png' file." << endl;
}

Graphics::~Graphics() {}

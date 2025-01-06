/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:32:32 by laprieur          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:17 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

void	loadTextures(int nbTextures, const std::string pathStart, const std::string prefixes[], std::vector<sf::Texture>& textures) {
	for (int i = 0; i < nbTextures; i++) {
		sf::Texture texture;
		std::string	filePath = pathStart + prefixes[i] + "Texture.png";
		if (texture.loadFromFile(filePath))
			textures.push_back(texture);
	}
}

void	setTextures(int nbTextures, const std::vector<sf::Texture>& textures, std::vector<sf::Sprite>& sprites) {
	for (int i = 0; i < nbTextures; i++) {
		sf::Sprite sprite;
		sprite.setTexture(textures[i]);
		sprites.push_back(sprite);
	}
}

void	setPosition(int nbSprites, std::vector<sf::Sprite>& sprites, int x, int y, int offset) {
	for (int i = 0; i < nbSprites; i++)
		sprites[i].setPosition(x + (i * offset), y);
}

void	setPosition(sf::Sprite& sprite, int x, int y) {
	sprite.setPosition(x, y);
}

void	setStatistics(std::vector<sf::Text>& stats, sf::Font& font, int player) {
	for (int i = 0; i < 5; i++) {
		stats[i].setFont(font);
		stats[i].setString((i == 0 || i == 1) ? std::to_string(0) : std::to_string(0) + ".00s");
		stats[i].setCharacterSize(22);
		stats[i].setFillColor(sf::Color::White);
	}
	if (player == 1) {
		stats[0].setPosition(311, 504);
		stats[1].setPosition(263, 557);
		stats[2].setPosition(296, 610);
		stats[3].setPosition(276, 663);
		stats[4].setPosition(294, 716);
	} else if (player == 2) {
		stats[0].setPosition(1731, 504);
		stats[1].setPosition(1683, 557);
		stats[2].setPosition(1716, 610);
		stats[3].setPosition(1696, 663);
		stats[4].setPosition(1714, 716);
	}
}
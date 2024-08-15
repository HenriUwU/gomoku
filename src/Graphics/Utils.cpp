/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:27:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/08/15 18:40:18 by laprieur         ###   ########.fr       */
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
	for (int i = 0; i < 3; i++) {
		stats[i].setFont(font);
		stats[i].setString((i == 0) ? std::to_string(0) : std::to_string(0) + ".00s");
		stats[i].setCharacterSize(22);
		stats[i].setFillColor(sf::Color::White);
	}
	if (player == 1) {
		stats[0].setPosition(327, 530);
		stats[1].setPosition(313, 556);
		stats[2].setPosition(314, 583);
	} else if (player == 2) {
		stats[0].setPosition(1769, 530);
		stats[1].setPosition(1755, 556);
		stats[2].setPosition(1756, 583);
	}
}
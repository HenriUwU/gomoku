/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:27:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/22 14:53:19 by laprieur         ###   ########.fr       */
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
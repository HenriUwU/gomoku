/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:27:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/10 15:35:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

void	loadTextures(int nbTextures, const std::string pathStart, const std::string prefixes[], const std::string suffix, std::vector<sf::Texture>& textures) {
	for (int i = 0; i < nbTextures; i++) {
		sf::Texture texture;
		std::string	filePath = pathStart + prefixes[i] + suffix;
		if (texture.loadFromFile(filePath))
			textures.push_back(texture);
	}
}
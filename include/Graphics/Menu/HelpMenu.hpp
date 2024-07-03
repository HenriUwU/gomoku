/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:31 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/03 15:00:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class HelpMenu {
	private:
		sf::Texture		_rulesPageTexture;
		sf::Texture		_capturesPageTexture;
		sf::Texture		_doubleThreesPageTexture;
		sf::Texture		_backwardButtonTexture;
		sf::Texture		_backwardHoveredButtonTexture;
		sf::Texture		_forwardButtonTexture;
		sf::Texture		_forwardHoveredButtonTexture;
		sf::Sprite		_rulesPageSprite;
		sf::Sprite		_capturesPageSprite;
		sf::Sprite		_doubleThreesPageSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_forwardButtonSprite;

	public:
		HelpMenu();
		~HelpMenu();

		void init();
		void display(sf::RenderWindow &window);		
		void handleKeys(sf::Event &event, sf::RenderWindow &window);
};
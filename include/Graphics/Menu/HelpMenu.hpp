/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:31 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/02 15:55:31 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class HelpMenu {
	private:
		enum Enum {
			RULESPAGE,
			CAPTURESPAGE,
			DOUBLETHREESPAGE,
			BACKWARDBUTTON,
			BACKWARDHOVEREDBUTTON,
			FORWARDBUTTON,
			FORWARDHOVEREDBUTTON
		};

		AnimatedGIF					_winGif;
		sf::Sprite					_rulesPageSprite;
		sf::Sprite					_capturesPageSprite;
		sf::Sprite					_doubleThreesPageSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_forwardButtonSprite;
		sf::Sprite					_winGifSprite;
		std::vector<sf::Texture>	_pageTextures;

	public:
		HelpMenu();
		~HelpMenu();

		void init();
		void display(sf::RenderWindow& window);
		void handleKeys(const sf::Event& event, const sf::RenderWindow& window);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:31 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/08 10:23:57 by laprieur         ###   ########.fr       */
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
		AnimatedGIF					_captureGif;
		AnimatedGIF					_doubleThreeGif;
		AnimatedGIF					_exceptionDoubleThreeGif;
		sf::Sprite					_rulesPageSprite;
		sf::Sprite					_capturesPageSprite;
		sf::Sprite					_doubleThreesPageSprite;
		sf::Sprite					_backwardButtonSprite;
		sf::Sprite					_forwardButtonSprite;
		sf::Sprite					_winGifSprite;
		sf::Sprite					_captureGifSprite;
		sf::Sprite					_doubleThreeGifSprite;
		sf::Sprite					_exceptionDoubleThreeGifSprite;
		std::vector<sf::Texture>	_pageTextures;

	public:
		HelpMenu();
		~HelpMenu();

		void	init();
		void	display(sf::RenderWindow& window);
		void	handleKeys(const sf::Event& event, const sf::RenderWindow& window);
};
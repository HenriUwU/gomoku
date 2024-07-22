/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:31 by hsebille          #+#    #+#             */
/*   Updated: 2024/07/22 11:57:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class HelpMenu {
	private:
		enum HelpMenuTextures {
			T_RULESPAGE,
			T_CAPTURESPAGE,
			T_DOUBLETHREESPAGE,
			T_BACKWARDBUTTON,
			T_BACKWARDHOVEREDBUTTON,
			T_FORWARDBUTTON,
			T_FORWARDHOVEREDBUTTON
		};
	
		std::vector<sf::Texture>	_pageTextures;
		sf::Sprite		_rulesPageSprite;
		sf::Sprite		_capturesPageSprite;
		sf::Sprite		_doubleThreesPageSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_forwardButtonSprite;

	public:
		HelpMenu();
		~HelpMenu();

		void init();
		void display(sf::RenderWindow& window);		
		void handleKeys(const sf::Event& event, const sf::RenderWindow& window);
};
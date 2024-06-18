/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpPage.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:31 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 21:19:14 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class HelpPage {
	private:
		sf::Texture		_rulesPageTexture;
		sf::Texture		_capturesPageTexture;
		sf::Texture		_doubleThreePageTexture;
		sf::Texture		_leftArrowButtonTexture;
		sf::Texture		_leftArrowButtonHighlightedTexture;
		sf::Texture		_rightArrowButtonTexture;
		sf::Texture		_rightArrowButtonHighlightedTexture;
		sf::Sprite		_rulesPage;
		sf::Sprite		_capturesPage;
		sf::Sprite		_doubleThreePage;
		sf::Sprite		_leftArrow;
		sf::Sprite		_rightArrow;

	public:
		HelpPage();
		~HelpPage();

		void helpPageInit();
		void display(sf::RenderWindow &window);		
		void handleKeys(sf::RenderWindow &window);
};
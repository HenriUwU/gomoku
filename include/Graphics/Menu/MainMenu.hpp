/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:24 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/19 10:01:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include "Goban.hpp"

#define NB_MENU_ITEMS 9

class MainMenu {
	private:
		int				_selectedItemIndex;
		sf::Font		_exo2BlackFont;
		sf::Font		_ex02BlackItalicFont;
		sf::Text		_menuText[NB_MENU_ITEMS];
		sf::Texture		_greenButtonTexture;
		sf::Texture		_orangeButtonTexture;
		sf::Texture		_redButtonTexture;
		sf::Texture		_blueButtonTexture;
		sf::Texture		_greenButtonHighlightedTexture;
		sf::Texture		_orangeButtonHighlightedTexture;
		sf::Texture		_redButtonHighlightedTexture;
		sf::Texture		_blueButtonHighlightedTexture;
		sf::Texture		_customIconTexture;
		sf::Texture		_settingsIconTexture;
		sf::Texture		_helpIconTexture;
		sf::Sprite		_greenButtonSprite;
		sf::Sprite		_orangeButtonSprite;
		sf::Sprite		_redButtonSprite;
		sf::Sprite		_greenButtonHighlightedSprite;
		sf::Sprite		_orangeButtonHighlightedSprite;
		sf::Sprite		_redButtonHighlightedSprite;
		sf::Sprite		_blueButtonCustomSprite;
		sf::Sprite		_blueButtonSettingsSprite;
		sf::Sprite		_blueButtonHelpSprite;
		sf::Sprite		_customIconSprite;
		sf::Sprite		_settingsIconSprite;
		sf::Sprite		_helpIconSprite;

	public:
		MainMenu();
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	init();
		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	MoveLeft();
		void	MoveRight();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
		void	handleMouseMovement(sf::Vector2i mousePos);
};
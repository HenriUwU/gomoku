/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/13 14:23:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

#define NB_MENU_ITEMS 4

class MainMenu {
	private:
		int			_selectedItemIndex;
		sf::Font	_font;
		sf::Text	_menu[NB_MENU_ITEMS];
		sf::Texture	_backgroundTexture;
		sf::Sprite	_backgroundSprite;
		sf::Music	_music;

	public:
		MainMenu(float width, float height);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	playMusic();
		void	stopMusic();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
};

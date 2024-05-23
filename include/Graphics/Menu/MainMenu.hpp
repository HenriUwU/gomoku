/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/23 14:26:59 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

#define NB_MENU_ITEMS 4

struct FadingSprite {
	sf::Sprite sprite;
	float timer;
	bool fadingIn;
};

class MainMenu {
	private:
		int							_selectedItemIndex;
		sf::Font					_font;
		sf::Text					_menu[NB_MENU_ITEMS];
		sf::Texture					_backgroundTexture;
		std::vector<FadingSprite>	_backgroundSprites;
		sf::Music					_music;

		void initializeBackgroundSprites(size_t count, const sf::RenderWindow &window);
		void updateSprites(float deltaTime, const sf::RenderWindow &window);

	public:
		MainMenu(float width, float height, sf::RenderWindow &window);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window, float deltaTime);
		void	MoveUp();
		void	MoveDown();
		void	playMusic();
		void	stopMusic();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
};

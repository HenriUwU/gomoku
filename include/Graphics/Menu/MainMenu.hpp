/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:35 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/28 14:46:46 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"
#include "Goban.hpp"

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
		sf::Texture					_gobanTexture;
		sf::Sprite					_gobanSprite;

		void initializeBackgroundSprites(size_t count, const sf::RenderWindow &window);
		void updateSprites(float deltaTime, const sf::RenderWindow &window);

	public:
		MainMenu(float width, float height, sf::RenderWindow &window);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }

		void	display(sf::RenderWindow &window, float deltaTime);
		void	MoveUp(sf::RenderWindow &window);
		void	MoveDown(sf::RenderWindow &window);
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:06:48 by hsebille          #+#    #+#             */
/*   Updated: 2024/05/09 18:08:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINMENU_HPP
# define MAINMENU_HPP

#include "gomoku.hpp"

#define NB_MENU_ITEMS 4

class Graphics;

class MainMenu {
	private:
		int			_selectedItemIndex;
		sf::Font	_font;
		sf::Text	_menu[NB_MENU_ITEMS];
		sf::Texture	_backgroundTexture;
		sf::Sprite	_backgroundSprite;

	public:
		MainMenu(float width, float height);
		~MainMenu();

		int		getSelectedItemIndex() { return _selectedItemIndex; }   

		void	display(sf::RenderWindow &window);
		void	MoveUp();
		void	MoveDown();
		void	handleKeys(sf::Event &event, sf::RenderWindow &window);
};

#endif
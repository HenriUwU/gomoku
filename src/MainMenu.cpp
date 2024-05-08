/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/05/08 16:25:13 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
    if (!_font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error while loading the font file." << std::endl;
    }

    for (int i = 0; i < NB_MENU_ITEMS; ++i) {
        _menu[i].setFont(_font);
        _menu[i].setFillColor(sf::Color::White);
    }

    _menu[0].setString("Welcome to Gomoku");
    _menu[0].setPosition(sf::Vector2f(width / 3.5, (height / NB_MENU_ITEMS + 1) * 0.5));

    _menu[1].setString("Player vs Player");
    _menu[1].setFillColor(sf::Color::Red);
    _menu[1].setPosition(sf::Vector2f(width / 3, (height / NB_MENU_ITEMS + 1) * 1.25));

    _menu[2].setString("Player vs AI");
    _menu[2].setPosition(sf::Vector2f(width / 2.6, (height / NB_MENU_ITEMS + 1) * 1.75));

    _menu[3].setString("Quit");
    _menu[3].setPosition(sf::Vector2f(width / 2.2, (height / NB_MENU_ITEMS + 1) * 2.25));

    _selectedItemIndex = 1;
}

MainMenu::~MainMenu() {}

void MainMenu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < NB_MENU_ITEMS; i++) {
        window.draw(_menu[i]);
    } 
}

void MainMenu::MoveUp()
{
    if (_selectedItemIndex - 1 >= 1) {
        _menu[_selectedItemIndex].setFillColor(sf::Color::White);
        _selectedItemIndex--;
        _menu[_selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown()
{
    if (_selectedItemIndex + 1 < NB_MENU_ITEMS) {
        _menu[_selectedItemIndex].setFillColor(sf::Color::White);
        _selectedItemIndex++;
        _menu[_selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
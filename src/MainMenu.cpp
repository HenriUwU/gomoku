/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by hsebille          #+#    #+#             */
/*   Updated: 2024/05/08 18:09:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
    if (!_font.loadFromFile("assets/fonts/FFF_Tusj.ttf")) {
        std::cerr << "Error while loading the font file." << std::endl;
    }
    
    if (!_backgroundTexture.loadFromFile("assets/images/frame1.png")) {
        std::cerr << "Error while loading the background file." << std::endl;
    }

    _backgroundSprite.setTexture(_backgroundTexture);

    float scaleX = width / _backgroundTexture.getSize().x;
    float scaleY = height / _backgroundTexture.getSize().y;
    _backgroundSprite.setScale(scaleX, scaleY);

    _backgroundSprite.setPosition(0, 0);

    for (int i = 0; i < NB_MENU_ITEMS; i++) {
        _menu[i].setFont(_font);
        _menu[i].setCharacterSize(45);
        _menu[i].setFillColor(sf::Color::White);
    }

    _menu[0].setString("Welcome to Gomoku");
    //_menu[0].setPosition(sf::Vector2f(width / 2, (height / NB_MENU_ITEMS + 1) * 0.5));

    _menu[1].setString("Player vs Player");
    _menu[1].setFillColor(sf::Color::Red);
    //_menu[1].setPosition(sf::Vector2f(width / 2, (height / NB_MENU_ITEMS + 1) * 1.25));

    _menu[2].setString("Player vs AI");
    //_menu[2].setPosition(sf::Vector2f(width / 2, (height / NB_MENU_ITEMS + 1) * 1.75));

    _menu[3].setString("Quit");
    //_menu[3].setPosition(sf::Vector2f(width / 2, (height / NB_MENU_ITEMS + 1) * 2.25));

    // Trouver la largeur maximale des éléments du menu
    float maxMenuWidth = 0.0f;
    for (int i = 0; i < NB_MENU_ITEMS; ++i) {
        sf::FloatRect bounds = _menu[i].getLocalBounds();
        maxMenuWidth = std::max(maxMenuWidth, bounds.width);
    }

    // Calculer la position horizontale pour centrer les éléments
    float offsetX = (width - maxMenuWidth) / 2;

    // Placer chaque élément du menu centré horizontalement
    for (int i = 0; i < NB_MENU_ITEMS; ++i) {
        sf::FloatRect bounds = _menu[i].getLocalBounds();
        float offsetY = (height / NB_MENU_ITEMS + 1) * (i + 0.5);
        float elementX = offsetX + (maxMenuWidth - bounds.width) / 2; // Centre par rapport à la plus grande largeur
        _menu[i].setPosition(sf::Vector2f(elementX, offsetY));
    }

    _selectedItemIndex = 1;
}

MainMenu::~MainMenu() {}

void MainMenu::draw(sf::RenderWindow &window)
{
    //window.draw(_backgroundSprite);
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
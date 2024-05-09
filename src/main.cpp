/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:51:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/05/09 14:29:51 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

void    drawCheckerboard(float dimensions, std::pair<unsigned int, unsigned int> startPoint, sf::RenderWindow &window) {
    for (int i = 0; i < 20; i++) {

        sf::Vertex verticalLine[] =
        {
            sf::Vertex(sf::Vector2f((dimensions / 19) * i + startPoint.first, startPoint.second)),
            sf::Vertex(sf::Vector2f((dimensions / 19) * i + startPoint.first, startPoint.second + dimensions))
        };

        sf::Vertex horizontalLine[] =
        {
            sf::Vertex(sf::Vector2f(startPoint.first, (dimensions / 19) * i + startPoint.second)),
            sf::Vertex(sf::Vector2f(startPoint.first + dimensions, (dimensions / 19) * i + startPoint.second))
        };

        window.draw(verticalLine, 2, sf::Lines);
        window.draw(horizontalLine, 2, sf::Lines);

    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gomoku");

    MainMenu mainMenu(window.getSize().x, window.getSize().y);

    float windowHeight = window.getSize().y;
    unsigned int windowWidth = window.getSize().x;

    bool displayMenu = true;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                    mainMenu.MoveUp();
                if (event.key.code == sf::Keyboard::Down)
                    mainMenu.MoveDown();
            }
            if (mainMenu.getSelectedItemIndex() == 1 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
                mainMenu.stopMusic();
                displayMenu = false;
                std::pair <unsigned int, unsigned int> startPoint;
                startPoint = std::make_pair((windowWidth - (windowHeight - 20)) / 2, 10);
                window.clear(sf::Color::Black);
                drawCheckerboard(windowHeight - 20, startPoint, window);
                window.display();
            }
            if (mainMenu.getSelectedItemIndex() == 2 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
                std::cout << "Player vs AI" << std::endl;
            if (mainMenu.getSelectedItemIndex() == 3 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
                window.close();
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
        }   

        if (displayMenu == true) {
            window.clear(sf::Color::Black);
            mainMenu.draw(window);
            window.display();
        }
    }
}

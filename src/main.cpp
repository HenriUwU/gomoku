/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:51:50 by hsebille          #+#    #+#             */
/*   Updated: 2024/05/08 17:23:46 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gomoku");

    MainMenu mainMenu(window.getSize().x, window.getSize().y); 
    
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
            if (mainMenu.getSelectedItemIndex() == 1 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
                std::cout << "Player vs Player" << std::endl;
            if (mainMenu.getSelectedItemIndex() == 2 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
                std::cout << "Player vs AI" << std::endl;
            if (mainMenu.getSelectedItemIndex() == 3 && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
                window.close();
            if (event.type == sf::Event::Closed)
                window.close();
        }   
        window.clear();
        mainMenu.draw(window);
        window.display();        
    }
}



/* int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vertical Line Example");

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(150, 0)), // Start point
        sf::Vertex(sf::Vector2f(150, 300)) // End point (adjust Y coordinate for length)
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }   

        window.clear(sf::Color::Black);
        window.draw(line, 2, sf::Lines); // Drawing the line
        window.display();
    }

    return 0;
} */
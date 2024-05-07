#include <SFML/Graphics.hpp>

int main() {
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
}

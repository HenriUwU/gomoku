#include <SFML/Graphics.hpp>

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

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Vertical Line Example");

    float windowHeight = window.getSize().y;
    unsigned int windowWidth = window.getSize().x;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::pair <unsigned int, unsigned int> startPoint;
        startPoint = std::make_pair((windowWidth - (windowHeight - 100)) / 2, 50);

        window.clear(sf::Color::Black);
        drawCheckerboard(windowHeight - 100, startPoint, window);
        window.display();

    }

    return 0;
}

#include <SFML/Graphics.hpp>

int main()
{
    // Window
    sf::RenderWindow window { sf::VideoMode(1600, 1000), "_test_" };
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Walls
    sf::RectangleShape wallTop { sf::Vector2f(1600, 10) };
    sf::RectangleShape wallBot { sf::Vector2f(1600, 10) };
    sf::RectangleShape wallLeft { sf::Vector2f(10, 1000) };
    sf::RectangleShape wallRight { sf::Vector2f(10, 1000) };

    wallTop.setPosition(0, 0);
    wallBot.setPosition(0, 990);
    wallLeft.setPosition(0, 0);
    wallRight.setPosition(1590, 0);


    // Font
    sf::Font font;
    font.loadFromFile("../fonts/bit5x3.ttf");

    // While the window is open
    while (window.isOpen())
    {
        // Events
        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::Closed) window.close();
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        // Render
        window.clear();

        // Render walls
        window.draw(wallTop);
        window.draw(wallBot);
        window.draw(wallLeft);
        window.draw(wallRight);

        window.display();
    }

    return 0;
}
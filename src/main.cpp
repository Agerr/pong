#include "sprite.h"

#include <SFML/Graphics.hpp>

int main()
{
    // Window
    sf::RenderWindow window { sf::VideoMode(1600, 1000), "_test_" };
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Walls
    sf::RectangleShape wallTop { sf::Vector2f(1600, 15) };
    sf::RectangleShape wallBot { sf::Vector2f(1600, 15) };
    sf::RectangleShape wallLeft { sf::Vector2f(15, 1000) };
    sf::RectangleShape wallRight { sf::Vector2f(15, 1000) };
    sf::RectangleShape wallMid { sf::Vector2f(10, 30) };

    wallTop.setPosition(0, 0);
    wallBot.setPosition(0, 985);
    wallLeft.setPosition(0, 0);
    wallRight.setPosition(1585, 0);
    wallMid.setPosition(795, 0);

    float midWallCount = 970 / 30.f / 2.f;

    // Sprite
    Sprite sprite(775, 475);

    // Font
    sf::Font font;
    font.loadFromFile("../fonts/bit5x3.ttf");

    while (window.isOpen())
    {
        // Events
        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::Closed) window.close();
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        // Rendering
        window.clear();

        // Render walls
        window.draw(wallTop);
        window.draw(wallBot);
        window.draw(wallLeft);
        window.draw(wallRight);
        
        for (int i = 0; i < midWallCount; i++)
        {
            wallMid.setPosition(795, 60 * i);
            window.draw(wallMid);
        }

        // Render sprite
        sprite.move();
        sprite.render(window);

        window.display();
    }

    return 0;
}
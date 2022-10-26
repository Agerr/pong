#include "sprite.hpp"
#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Window
    sf::RenderWindow window { sf::VideoMode(1600, 1000), "Pong" };
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    // Font
    sf::Font font;
    font.loadFromFile("../fonts/bit5x3.ttf");

    // Walls
    sf::RectangleShape wallTop      { sf::Vector2f(1600, 15) };
    sf::RectangleShape wallBot      { sf::Vector2f(1600, 15) };
    sf::RectangleShape wallLeft     { sf::Vector2f(15, 1000) };
    sf::RectangleShape wallRight    { sf::Vector2f(15, 1000) };
    sf::RectangleShape wallMid      { sf::Vector2f(10, 30) };

    wallTop.setPosition(0, 0);
    wallBot.setPosition(0, 985);
    wallLeft.setPosition(0, 0);
    wallRight.setPosition(1585, 0);
    wallMid.setPosition(795, 0);

    float midWallCount = 970 / 30.f / 2.f;

    // Sprite
    Sprite sprite(775, 475);

    // Players
    Player player1(30, 450);
    Player player2(1555, 450);

    // Score
    sf::Text score1;
    sf::Text score2;

    score1.setFont(font);
    score1.setCharacterSize(200);
    score1.setFillColor(sf::Color::White);
    score1.setPosition(600, 0);

    score2.setFont(font);
    score2.setCharacterSize(200);
    score2.setFillColor(sf::Color::White);
    score2.setPosition(930, 0);

    while (window.isOpen())
    {
        // Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close
            if (event.type == sf::Event::Closed) window.close();

            // KeyPress
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape : window.close(); break;

                    case sf::Keyboard::W    :   player1.upFlag = true; break;
                    case sf::Keyboard::S    :   player1.downFlag = true; break;
                    case sf::Keyboard::Up   :   player2.upFlag = true; break;
                    case sf::Keyboard::Down :   player2.downFlag = true; break;

                    default : break;
                }
            }

            // KeyRelease
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::W    :   player1.upFlag = false; break;
                    case sf::Keyboard::S    :   player1.downFlag = false; break;
                    case sf::Keyboard::Up   :   player2.upFlag = false; break;
                    case sf::Keyboard::Down :   player2.downFlag = false; break;

                    default : break;
                }
            }
        }

        // Move players
        if (player1.upFlag      && player1.pos.y > 30)  player1.moveUp(10);
        if (player1.downFlag    && player1.pos.y < 870) player1.moveDown(10);
        if (player2.upFlag      && player2.pos.y > 30)  player2.moveUp(10);
        if (player2.downFlag    && player2.pos.y < 870) player2.moveDown(10);

        // Rendering
        window.clear();

        // Walls
        window.draw(wallTop);
        window.draw(wallBot);
        window.draw(wallLeft);
        window.draw(wallRight);
        
        for (int i = 0; i < midWallCount; i++)
        {
            wallMid.setPosition(795, 60 * i);
            window.draw(wallMid);
        }

        // Sprite
        sprite.move(player1, player2);
        sprite.render(window);

        // Players
        player1.render(window);
        player2.render(window);

        // Score
        score1.setString(std::to_string(player1.score));
        score2.setString(std::to_string(player2.score));
        window.draw(score1);
        window.draw(score2);

        window.display();
    }

    return 0;
}
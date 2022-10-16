#pragma once

#include <SFML/Graphics.hpp>

class Player 
{
    sf::Vector2f pos;
    sf::RectangleShape rect;

public:
    bool upFlag = false;
    bool downFlag = false;

    Player(float pos_x, float pos_y)
    {
        pos = sf::Vector2f(pos_x, pos_y);

        rect.setPosition(pos);
        rect.setSize(sf::Vector2f(15, 100));
        rect.setFillColor(sf::Color::White);
    }

    void moveUp(float amount);
    void moveDown(float amount);
    void render(sf::RenderWindow &window);
};
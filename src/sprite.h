#pragma once

#include <SFML/Graphics.hpp>

class Sprite
{
    sf::Vector2f pos;
    sf::RectangleShape rect;

    float vel_x { 7 };
    float vel_y { 7 };

public:
    Sprite(float pos_x, float pos_y)
    {
        pos = sf::Vector2f(pos_x, pos_y);
        
        rect.setPosition(pos);
        rect.setSize(sf::Vector2f(50, 50));
        rect.setFillColor(sf::Color::White);
    }
    void move();
    void render(sf::RenderWindow &window);
};
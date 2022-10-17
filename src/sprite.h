#pragma once

#include "player.h"

#include <SFML/Graphics.hpp>

class Sprite
{
    sf::Vector2f pos;
    sf::RectangleShape rect;

    float vel_x { 5 };
    float vel_y { 5 };

public:
    Sprite(float pos_x, float pos_y)
    {
        pos = sf::Vector2f(pos_x, pos_y);
        
        rect.setPosition(pos);
        rect.setSize(sf::Vector2f(50, 50));
        rect.setFillColor(sf::Color::White);
    }
    
    void move(Player player1, Player player2);
    void render(sf::RenderWindow &window);
};
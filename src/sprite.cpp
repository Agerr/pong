#include "sprite.hpp"

#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

void Sprite::move(Player player1, Player player2)
{
    // Wall Collisions
    if (pos.x < 15 || pos.x > 1535) vel_x *= -1;
    if (pos.y < 15 || pos.y > 935) vel_y *= -1;


    // Player 1 collision
    bool inX1 { (pos.x <= (player1.pos.x + 15)) && (pos.x > (player1.pos.x + 15 + vel_x)) };
    bool inY1 { ((pos.y + 50) > player1.pos.y) && (pos.y < (player1.pos.y + 100)) };
    if (inX1 && inY1) vel_x *= -1;


    // Player 2 collision
    bool inX2 { ((pos.x + 50) >= player2.pos.x) && ((pos.x + 50) < (player2.pos.x + vel_x)) };
    bool inY2 { ((pos.y + 50) > player2.pos.y) && (pos.y < player2.pos.y + 100) };
    if (inX2 && inY2) vel_x *= -1;

    pos.x += vel_x;
    pos.y += vel_y;
    rect.setPosition(pos);
}

void Sprite::render(sf::RenderWindow &window)
{
    window.draw(rect);
}
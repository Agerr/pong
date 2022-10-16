#include "./sprite.h"

#include <SFML/Graphics.hpp>

void Sprite::move()
{
    if (pos.x < 15 || pos.x > 1535) vel_x *= -1;
    if (pos.y < 15 || pos.y > 935) vel_y *= -1;

    pos.x += vel_x;
    pos.y += vel_y;
    rect.setPosition(pos);
}

void Sprite::render(sf::RenderWindow &window)
{
    window.draw(rect);
}
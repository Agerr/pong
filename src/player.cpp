#include "player.h"

#include <SFML/Graphics.hpp>

void Player::moveUp(float amount)
{
    pos.y -= amount;
    rect.setPosition(pos);
}

void Player::moveDown(float amount)
{
    pos.y += amount;
    rect.setPosition(pos);
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(rect);
}
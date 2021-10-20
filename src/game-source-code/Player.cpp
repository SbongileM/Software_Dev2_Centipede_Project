#include "Player.h"

Player::Player()
{
    xPosition = 360;
    yPosition = 640;
    speed = 20;
    state_of_player = ALIVE;

}

void Player::moveLeft()
{
    if(xPosition > 0) xPosition -= speed;
}

void Player::moveRight()
{
    if(xPosition < 660)xPosition += speed;
}

bool Player::isAlive()
{
    return state_of_player == ALIVE;
}

void Player::setState(State state)
{
    state_of_player = state;
}
void Player::setDirection(Direction direction_)
{
    direction= direction_;
}



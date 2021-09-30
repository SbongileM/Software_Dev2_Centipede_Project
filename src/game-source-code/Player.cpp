#include "Player.h"

Player::Player()
{
    xPosition = 300;
    yPosition = 600;
    speed = 30;
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

float Player::getXpos()
{
    return xPosition;
}

float Player::getYpos()
{
    return yPosition;
}


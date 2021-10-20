#include "Player.h"

Player::Player()
{
    xPosition = 360;
    yPosition = 640;
    speed = 20;
    state_of_player = ALIVE;

}

void Player::moveUp()
{
    if(yPosition > 500){yPosition -= speed;}
}

void Player::moveDown()
{
    if(yPosition < 630){yPosition += speed;}
}

void Player::moveLeft()
{
    if(xPosition > 0) xPosition -= speed;
}

void Player::moveRight()
{
    if(xPosition < 665)xPosition += speed;
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

void Player::changeDirection()
{
    switch (getDirection())
        {
        case Direction::RIGHT:
            moveLeft();
            break;
        case Direction::LEFT:
            moveRight();
            break;
        case Direction::DOWN:
            moveUp();
            break;
        case Direction::UP:
            moveDown();
            break;
        default:
            break;
        }
}

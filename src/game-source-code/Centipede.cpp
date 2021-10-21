#include "Centipede.h"
#include <iostream>
#include <cmath>
using namespace std;


Centipede::Centipede(int x, int y)
{
    state_of_centipedeSegment = ALIVE;
    xPosition = x;
    yPosition = y;
}

void Centipede::setState(State state)
{
    state_of_centipedeSegment = state;
}

void Centipede::setDirection (Direction direction)
{
    direction_=direction;
}

void Centipede::setBodyType(BodyType type)
{
    type_= type;
}

void Centipede::setBottomFlag(bool flag)
{
    reached_bottom =flag;
}

void Centipede::moveLeft()
{
    if (isAlive())
    {
        xPosition -= speed;
    }
}

void Centipede::moveRight()
{
    if (isAlive())
    {
        xPosition += speed;
    }
}

void Centipede::moveDown()
{
    yPosition += 20;
}

void Centipede::moveUp()
{
    yPosition -= 20;
}

bool Centipede::isAlive()
{
    return state_of_centipedeSegment == ALIVE;
}

bool Centipede::isDead()
{
    return state_of_centipedeSegment ==DEAD;
}

void Centipede::changeDirection()
{
     if (getDirection()== Direction::RIGHT)
        {
            moveLeft();
            setDirection(Direction::LEFT);
        }

     else if (getDirection()== Direction::LEFT)
        {
            moveRight();
            setDirection(Direction::RIGHT);
        }
}

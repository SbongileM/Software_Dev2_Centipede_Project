#include "Mushroom.h"

Mushroom::Mushroom(int x, int y)
{
    lives = 3;
    state_of_mushroom = ALIVE;
    xPosition = x;
    yPosition = y;
}

bool Mushroom::isAlive()
{
    return state_of_mushroom == ALIVE;

}

void Mushroom::setLives(int _lives)
{
    lives = _lives;
}

void Mushroom::setState(State state)
{
    state_of_mushroom = state;
}

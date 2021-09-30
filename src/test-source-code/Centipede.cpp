#include "Centipede.h"
#include <iostream>
#include <cmath>
using namespace std;


Centipede::Centipede(float x, float y)
{
    state_of_centipede = ALIVE;
    xPosition = x;
    yPosition = y;
    formationXpos = x;
    formationYpos = y;
}

void Centipede::moveLeft()
{
    if(xPosition > 0)
    {

        if (isAlive())
        {
            xPosition -= speed;
            if (yPosition < formationYpos-5)yPosition += speed;
            else if (yPosition > formationYpos+5)
            {
                yPosition = 0;
                xPosition = formationXpos;
            }
        }
            formationXpos -= speed;
    }
}

void Centipede::moveRight()
{
    if(xPosition < 670)
    {
        if (isAlive())
        {
            xPosition += speed;
            if (yPosition < formationYpos-5) yPosition += speed;
            else if (yPosition > formationYpos+5)
            {
                yPosition = 0;
                xPosition = formationXpos;
            }
        }
            formationXpos+=speed;
    }
}

void Centipede::dive()
{
    if (isDiving() && yPosition < 700)
    {
        if(xPosition >= 0 && xPosition <= 670)
        {
                xPosition += (2*speed*sin(yPosition/30));
                yPosition += speed;
        }
        else
        {
            if(xPosition >= 670)
            {
                xPosition += -speed;
                yPosition += speed;
            }
            else if (xPosition <= 0)
            {
                xPosition += speed;
                yPosition += speed;
            }
        }
    }
    if(yPosition >= 700) state_of_centipede = ALIVE;
}

bool Centipede::isAlive()
{
    return state_of_centipede == ALIVE;
}
bool Centipede::isDead()
{
    return state_of_centipede==DEAD;
}
bool Centipede::isDiving()
{
    return state_of_centipede == DIVING;
}

void Centipede::setState(State state)
{
    state_of_centipede = state;
}

float Centipede::getXpos()
{
    return xPosition;
}

float Centipede::getYpos()
{
    return yPosition;
}

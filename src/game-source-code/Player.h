#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"

class Player
{
public:

     Player();

     bool isAlive();

     int getXpos(){return xPosition;};

     int getYpos(){return yPosition;};

     Direction getDirection(){return direction;};

     void setState(State state);

     void setDirection(Direction direction_);

     void moveLeft();

     void moveRight();

     void moveUp();

     void moveDown();

private:
    int speed;
    int xPosition;
    int yPosition;
    Direction direction;
    State state_of_player;
};

#endif // PLAYER_H

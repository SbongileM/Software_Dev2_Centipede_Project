#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <vector>
#include <memory>
#include "Utils.h"

using namespace std;

class Mushroom
{
    public:
        Mushroom(int x, int y);

        bool isAlive();

        bool isDead();

        int getXpos(){return xPosition;};

        int getYpos(){return yPosition;};

        int getLives(){return lives;};

        void setState(State state);

        void setLives(int _lives);

    private:
        int xPosition;
        int yPosition;
        State state_of_mushroom;
        int lives;

};

typedef vector<shared_ptr<Mushroom>> Mushrooms;
#endif // MUSHROOM_H

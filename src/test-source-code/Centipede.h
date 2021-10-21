#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <vector>
#include <memory>
#include "Utils.h"

using std::vector;
using namespace std;

enum class BodyType
{
    HEAD,
    BODYSEG
};

class Centipede
{
public:
    Centipede(int x, int y);

    int getXpos(){return xPosition;};

    int getYpos(){return yPosition;};

    Direction getDirection (){return direction_;};

    BodyType getBodyType(){return type_;};

    bool HasReachedBottom() {return reached_bottom;};

    void setState(State state);

    void setDirection(Direction direction);

    void setBodyType(BodyType type);

    void setBottomFlag(bool flag);

    bool isAlive();

    bool isDead();

    void moveLeft();

    void moveRight();

    void moveDown();

    void moveUp();

    void changeDirection();

private:
    int xPosition;
    int yPosition;
    State state_of_centipedeSegment;
    Direction direction_;
    BodyType type_;
    int speed = 20;
    bool reached_bottom = false;

};

typedef vector<shared_ptr<Centipede>> VecOfCentipede;

#endif // CENTIPEDE_H

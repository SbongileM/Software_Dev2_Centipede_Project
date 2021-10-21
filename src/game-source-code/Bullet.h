#ifndef BULLET_H
#define BULLET_H
#include <vector>
#include <string>
#include <memory>
#include "Utils.h"

using std::string;
using std::vector;
using std::shared_ptr;

class Bullet
{
public:
    Bullet(int x, int y);

    bool isAlive(){return _state == ALIVE;};

    bool isDead(){return _state == DEAD;};

    float getXpos(){return _position[0];};

    float getYpos(){return _position[1];};

    void setState(State state){_state = state;};

    void moveBullet();


private:
    float _lifePoints;
    Position _position;
    State _state;
    float _speed;

    float speed();
    void moveUp();


};

typedef shared_ptr<Bullet> BulletPtr;
#endif

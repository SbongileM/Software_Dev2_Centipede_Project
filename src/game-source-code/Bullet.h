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

<<<<<<< HEAD
    int getXpos(){return _position[0];};

    int getYpos(){return _position[1];};
=======
    float getXpos(){return _position[0];};

    float getYpos(){return _position[1];};
>>>>>>> 7f56763008391ad6af30bc2dfe3a3813442fb53b

    void setState(State state){_state = state;};

    void moveBullet();


private:
    float _lifePoints;
    Position _position;
    State _state;
    float _speed;
<<<<<<< HEAD
=======

    float speed();
    void moveUp();
>>>>>>> 7f56763008391ad6af30bc2dfe3a3813442fb53b

    float speed();
    void moveUp();

};

typedef shared_ptr<Bullet> BulletPtr;
#endif

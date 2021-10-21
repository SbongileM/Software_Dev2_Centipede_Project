#include <stdexcept>
#include <iostream>
using std::cout;
using std::end;
#include "Bullet.h"
#include "Configuration.h"

Bullet::Bullet(int x,int y)
{
    _position = Position();
    _position.push_back(x);
    _position.push_back(y);
    _lifePoints = 20;
    _speed = DEFAULTSPEED;
    _state = ALIVE;
}

void Bullet::moveBullet()
{
    moveUp();
}

void Bullet::moveUp()
{
    if ( _position[1] > 0 ){_position[1] -= _speed;}

    else{_state = DEAD;}
}

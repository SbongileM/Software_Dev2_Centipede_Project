#include <stdexcept>
#include <iostream>
using std::cout;
using std::end;
#include "Bullet.h"
#include "Configuration.h"

Bullet::Bullet(float x, float y, Direction dir)
{
    _position = Position();
    _position.push_back(x);
    _position.push_back(y);

    _direction = dir;
    _lifePoints = 20;
    _speed = DEFAULTSPEED;
    _state = ALIVE;
}

void Bullet::move()
{
    if (_direction == UP)
    {
        moveUp();
    }
    else
    {
        throw std::invalid_argument("TRYING TO MOVE IN INVALID DIRECTION");
    }
}


void Bullet::moveUp()
{
    if ( _position[1] > 0 )
    {
        _position[1] -= _speed;
    }
    else
    {
        _state = DEAD;
    }
}


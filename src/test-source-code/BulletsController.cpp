#include "BulletsController.h"
#include <iostream>
using std::cout;
using std::endl;

void BulletsController::add(float x, float y, Direction direction)
{

   BulletPtr bullet(new Bullet(x, y, direction));
   int galaxipBullets = 0;

   for (auto bullet : _bullets)
     {
           galaxipBullets++;
     }
   if (galaxipBullets < 9 && direction == UP)         // max number of galaxip bullets
     _bullets.push_back(bullet);
}

void BulletsController::update()
{
    for (auto bullet: _bullets)
       bullet->move();

    BulletList temp;
    for (BulletsListIter iter = _bullets.begin(); iter != _bullets.end(); iter++)
    {
        if ((*iter)->isAlive())
        {

            temp.push_back((*iter));
        }
    }
    _bullets.clear();
    _bullets = temp;
}

void BulletsController::setBullets(BulletList bullets)
{
    _bullets= bullets;
}
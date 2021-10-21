#include "BulletsController.h"
#include <iostream>
using std::cout;
using std::endl;

void BulletsController::add(float x, float y)
{

    BulletPtr bullet(new Bullet(x, y));
    int playerBullets = 0;

    for (auto bullet : _bullets){playerBullets++;}

    if (playerBullets < 10 ) {_bullets.push_back(bullet);}
}

void BulletsController::update()
{
    for (auto bullet: _bullets){bullet->moveBullet();}

    deleteDeadBullets(_bullets);
}

void BulletsController::setBullets(BulletList bullets)
{
    _bullets= bullets;
}

void BulletsController::deleteDeadBullets(BulletList& bullets)
{
    BulletList temp;

    for (BulletsListIter iter = bullets.begin(); iter != bullets.end(); iter++)
    {
        if ((*iter)->isAlive()){temp.push_back((*iter));}
    }

    bullets.clear();
    bullets = temp;
}

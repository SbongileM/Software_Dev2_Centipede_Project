#include "CollisionDetector.h"
#include <iostream>
using namespace std;

CollisionDetector::CollisionDetector()
{
    score = 0;
    _gameOver = false;
}

bool CollisionDetector::hasCollided(shared_ptr<Centipede> centipedeseg, BulletPtr bullet)
{
    if((bullet->getYpos()-BULLETRADIUS) >= centipedeseg->getYpos() && (bullet->getYpos()-BULLETRADIUS) <= (centipedeseg->getYpos() + 40))
    {
        if(((bullet->getXpos()-BULLETRADIUS) >= centipedeseg->getXpos() && (bullet->getXpos()-BULLETRADIUS) <= centipedeseg->getXpos()+30) ||((bullet->getXpos()+BULLETRADIUS) >= centipedeseg->getXpos() && (bullet->getXpos()+BULLETRADIUS) <= centipedeseg->getXpos()+30))
            return true;
    }
    return false;
}


void CollisionDetector::checkCentipedesegAndBullet(VecOfCentipede& centipedetail,BulletList& bullets, int points)
{
    for (auto centipedeseg : centipedetail)
    {
        for (auto bullet : bullets)
        {
            if (!centipedeseg->isDead() && !bullet->isDead() && bullet->getDirection() == UP)
            {
                if (hasCollided (centipedeseg,bullet))
                {
                    if (centipedeseg->isDiving()) score += 50; // any centipedeseg shot while diving is worth an extra 50 points
                    score += points;
                    centipedeseg->setState(DEAD);
                    bullet->setState(DEAD);
                }
            }
        }
    }
}


void CollisionDetector::checkCollisions(VecOfCentipede& centipedetail,VecOfCentipede& headsegment, BulletList& bullets)
{
    checkCentipedesegAndBullet(centipedetail,bullets,10); // centipedetail worth 10 points
    checkCentipedesegAndBullet(headsegment,bullets,100); // centipedehead worth 100 points

}



#include "CollisionDetector.h"
#include <iostream>
using namespace std;

CollisionDetector::CollisionDetector()
{
    score = 0;
    _gameOver = false;
}

void CollisionDetector::checkCollisions(VecOfCentipede& centipede, BulletList& bullets, Player& player, Mushrooms& mushrooms, MushroomController& controller)
{
    checkCentipedesegAndBullet(centipede,bullets,controller);
    checkCentipedesegAndPlayer(centipede, player);
    checkMushroomAndBullet(mushrooms,bullets);
    checkCentipedesegAndMushroom(centipede,mushrooms);
    checkMushroomAndPlayer(mushrooms, player);
}

void CollisionDetector::checkCentipedesegAndBullet(VecOfCentipede& centipede,BulletList& bullets, MushroomController& controller)
{
    for (auto centipedeseg=begin(centipede); centipedeseg!=end(centipede); ++centipedeseg)
    {
        for (auto bullet : bullets)
        {
            if ((*centipedeseg)->isAlive() && (bullet->isAlive()) && hasCollided((*centipedeseg),bullet))
            {
                if ((*centipedeseg)->getBodyType()== BodyType::HEAD){score += 100;}
                else {score += 10;}

                (*centipedeseg)->setState(DEAD);
                bullet->setState(DEAD);

                controller.createMushroom((*centipedeseg)->getXpos(),(*centipedeseg)->getYpos());
                if((centipedeseg+1)!=end(centipede)){(*(centipedeseg+1))->setBodyType(BodyType::HEAD);}
            }
        }
    }
}

void CollisionDetector::checkCentipedesegAndPlayer(VecOfCentipede& centipede, Player& player)
{
    for (auto centipedeSeg : centipede)
    {
        if (hasCollided (centipedeSeg,player))
        {
            centipedeSeg->setState(DEAD);
            player.setState(DEAD);
            _gameOver = true;
        }
    }
}

void CollisionDetector::checkMushroomAndBullet(Mushrooms& mushrooms,BulletList& bullets)
{
    for (auto mushroom : mushrooms)
    {
        for (auto bullet : bullets)
        {
            int lives_ = mushroom->getLives();

            if (mushroom->isAlive() && bullet->isAlive() && hasCollided (mushroom,bullet))
            {
                if (mushroom->getLives()> 0)
                {
                        lives_--;
                        bullet->setState(DEAD);
                }

                else if (mushroom->getLives()== 0)
                {
                        score ++;
                        mushroom->setState(DEAD);
                        bullet->setState(DEAD);
                }
            }
            mushroom->setLives(lives_);
        }
    }
}

void CollisionDetector::checkCentipedesegAndMushroom(VecOfCentipede& centipede, Mushrooms& mushrooms)
{
    for (auto mushroom : mushrooms)
    {
        for (auto centipedeSeg : centipede)
        {
            if (hasCollided (centipedeSeg,mushroom))
            {
                if (centipedeSeg->HasReachedBottom() == false)
                {
                    centipedeSeg->moveDown();
                    centipedeSeg->changeDirection();
                }

                else if(centipedeSeg->HasReachedBottom() == true)
                {
                     centipedeSeg->moveUp();
                     centipedeSeg->changeDirection();
                }
            }
        }
    }
}

void CollisionDetector::checkMushroomAndPlayer(Mushrooms& mushrooms, Player& player)
{
     for (auto mushroom : mushrooms)
    {
      if (hasCollided (mushroom,player))
        {
          player.changeDirection();
        }
    }
}

bool CollisionDetector::hasCollided(shared_ptr<Centipede> centipedeseg, BulletPtr bullet)
{
    if((bullet->getYpos()) >= centipedeseg->getYpos() && (bullet->getYpos()) <= (centipedeseg->getYpos()+20))
    {
        if(((bullet->getXpos()) >= centipedeseg->getXpos() && (bullet->getXpos()) <= centipedeseg->getXpos()+20) ||((bullet->getXpos()) >= centipedeseg->getXpos() && (bullet->getXpos()) <= centipedeseg->getXpos()+20))
            return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(shared_ptr<Centipede> Centipedeseg, Player player)
{
    if((Centipedeseg->getYpos()+10 >= player.getYpos() && Centipedeseg->getYpos()+10 <= player.getYpos()+10)||(Centipedeseg->getYpos() >= player.getYpos() && Centipedeseg->getYpos() <= player.getYpos()+10) )
    {
        if((Centipedeseg->getXpos() >= player.getXpos() && Centipedeseg->getXpos() <= player.getXpos()+10) || (Centipedeseg->getXpos()+10 >= player.getXpos() && Centipedeseg->getXpos()+10 <= player.getXpos()+10))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(shared_ptr<Mushroom> mushroom, BulletPtr bullet)
{
    if((bullet->getYpos()) >= mushroom->getYpos() && (bullet->getYpos()) <= (mushroom->getYpos()+20))
    {
        if(((bullet->getXpos() >= mushroom->getXpos()) && (bullet->getXpos() <= mushroom->getXpos()+20)) ||((bullet->getXpos() >= mushroom->getXpos()) && (bullet->getXpos() <= mushroom->getXpos()+20)))
            return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(shared_ptr<Mushroom> mushroom, Player player)
{
    if(((mushroom->getYpos()+10 >= player.getYpos()) && (mushroom->getYpos()+10 <= player.getYpos()+10))||(mushroom->getYpos() >= player.getYpos() && mushroom->getYpos() <= player.getYpos()+10))
    {
        if(((mushroom->getXpos() >= player.getXpos()) && (mushroom->getXpos() <= player.getXpos()+10)) || ((mushroom->getXpos() >= player.getXpos()) && (mushroom->getXpos() <= player.getXpos()+10)))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(shared_ptr<Centipede> Centipedeseg, shared_ptr<Mushroom> mushroom)
{
    if((mushroom->getYpos()+10 >= Centipedeseg->getYpos() && mushroom->getYpos()+10 <= Centipedeseg->getYpos()+10)||(mushroom->getYpos() >= Centipedeseg->getYpos() && mushroom->getYpos() <= Centipedeseg->getYpos()+10) )
    {
        if((mushroom->getXpos() >= Centipedeseg->getXpos() && mushroom->getXpos() <= Centipedeseg->getXpos()+10) || (mushroom->getXpos()+10 >= Centipedeseg->getXpos() && mushroom->getXpos()+10 <= Centipedeseg->getXpos()+10))return true;
    }
    return false;
}


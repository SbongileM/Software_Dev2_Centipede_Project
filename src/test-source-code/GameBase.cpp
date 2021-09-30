#include "GameBase.h"
#include <iostream>

using namespace std;

GameBase::GameBase()
{
    createCentipedeseg();
    getCentipedesegVectors();
    state = Online;
    win = false;
    score = 0;
}

void GameBase::setState(GameState gameState)
{
    state = gameState;
}
void GameBase::PlayerMoveleft()
{
     player_.moveLeft();
}
void GameBase::PlayerMoveRight()
{
     player_.moveRight();
}
void GameBase::createCentipedeseg()
{
    centipedeController_.createCentipede();
}

void GameBase::shootPlayerBullet()
{
    bulletsController.add( player_.getXpos(),  player_.getYpos(), UP);

}

void GameBase::getCentipedesegVectors()
{
    centipedetail = centipedeController_.getVectorOfcentipedetail();
    headsegment = centipedeController_.getVectorOfheadsegment();
}
void GameBase::setCentipedesegVectors()
{
    centipedeController_.setVectorOfcentipedetail(centipedetail);
    centipedeController_.setVectorOfheadsegment(headsegment);
}

void GameBase::gameLogic()
{
    centipedeController_.update();
    getCentipedesegVectors();
    bulletsController.update();
    bullets = bulletsController.getBullets();
    CollisionDetector col;
    col.checkCollisions(centipedetail,headsegment,bullets);
    score += col.getScore();
    if(col.isGameOver() || allCentipedesegDead())
    {
        bullets.clear();
        state = GameOver;
        if(allCentipedesegDead()) win = true;
    }
    bulletsController.setBullets(bullets);
    setCentipedesegVectors();
}

bool GameBase::allCentipedesegDead()
{
    if(centipedetail.size()==0 && headsegment.size()==0)
        return true;
    return false;
}

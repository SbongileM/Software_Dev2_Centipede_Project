#include "GameBase.h"
#include <iostream>

using namespace std;

GameBase::GameBase()
{
    createCentipedeseg();
    getCentipedesegVectors();
    createMushrooms();
    GetMushrooms();
    state = Online;
    win = false;
    score = 0;
}

void GameBase::gameLogic()
{
    centipedeController_.update();
    getCentipedesegVectors();
    mushroomController_.update();
    GetMushrooms();
    bulletsController.update();
    bullets = bulletsController.getBullets();
    CollisionDetector col;
    col.checkCollisions(centipede,bullets,player_,mushrooms_,mushroomController_);
    score += col.getScore();
    if(col.isGameOver() || allCentipedesegDead())
    {
        bullets.clear();
        state = GameOver;
        if(allCentipedesegDead()) {win = true;}
    }
    bulletsController.setBullets(bullets);
    setCentipedesegVectors();
}

void GameBase::setState(GameState gameState)
{
    state = gameState;
}

void GameBase::PlayerMoveleft()
{
    player_.setDirection(Direction::LEFT);
    player_.moveLeft();
}

void GameBase::PlayerMoveRight()
{
    player_.setDirection(Direction::RIGHT);
    player_.moveRight();
}

void GameBase::PlayerMoveDown()
{
    player_.setDirection(Direction::DOWN);
    player_.moveDown();
}

void GameBase::PlayerMoveUp()
{
    player_.setDirection(Direction::UP);
    player_.moveUp();
}

void GameBase::createCentipedeseg()
{
    centipedeController_.createCentipede(10);
}

void GameBase::createMushrooms()
{
    mushroomController_.createMushrooms(10);
}

void GameBase::shootPlayerBullet()
{
    bulletsController.add(player_.getXpos(),  player_.getYpos());
}

void GameBase::getCentipedesegVectors()
{
    centipede = centipedeController_.getVecofCentipede();
}

void GameBase::GetMushrooms()
{
    mushrooms_= mushroomController_.getVecOfMushrooms();
}

void GameBase::setCentipedesegVectors()
{
    centipedeController_.setVecofCentipede(centipede);
}

void GameBase::setMushrooms()
{
    mushroomController_.setVecOfMushrooms(mushrooms_);
}

bool GameBase::allCentipedesegDead()
{
    if(centipede.size()==0) {return true;}
    else{return false;}
}

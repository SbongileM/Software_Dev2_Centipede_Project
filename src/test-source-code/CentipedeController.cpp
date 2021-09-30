#include "CentipedeController.h"
#include <cstdlib>
#include <time.h>

CentipedeController::CentipedeController()
{
    flag = false;
}

void CentipedeController::createCentipede()
{
    for (int i =20; i<500; i+=30)
    {
        for (int j =30; j<230; j+=50)
        {
            if ((i == 20) && (j == 30))
            {
                shared_ptr<Centipede> headsegment_(new Centipede(i,j));
                headsegment.push_back( headsegment_);
            }
            if ((i > 20) && (i < 500)&& (j == 30))
            {
                shared_ptr<Centipede> Centitail(new Centipede(i,j));
                centipedetail.push_back(Centitail);
            }
        }
    }
}

void CentipedeController::moveFormation()
{
    unsigned int number_of_deadcentipedetail = 0;
    for (auto iter=begin(centipedetail); iter!=end(centipedetail); ++iter)
    {
        if((*iter)->isDead())number_of_deadcentipedetail++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
    for (auto iter=begin(headsegment); iter!=end(headsegment); ++iter)
    {
        if((*iter)->isDead())number_of_deadcentipedetail++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
}


void CentipedeController::moveDiving(VecOfCentipede tail)
{
    for (auto iter=begin(tail); iter!=end(tail); ++iter)
    {
        if((*iter)->isDiving())
        {
            randomNum = (rand() % (10)) + 1;
            Position pos;
            if(randomNum == 7 )
            {
                pos.push_back((*iter)->getXpos());
                pos.push_back((*iter)->getYpos());
                _bulletPositions.push_back(pos);
            }
            (*iter)->dive();

        }
    }
}

void CentipedeController::moveDivingObjects()
{
    _bulletPositions.clear();
    moveDiving(centipedetail);
    setFlag(centipedetail);
    setFlag(headsegment);
}

void CentipedeController::setFlag(VecOfCentipede tail)
{
    for (auto iter=begin(tail); iter!=end(tail); ++iter)
    {
        if(!(*iter)->isDead() && (*iter)->getXpos() <= 0 )
        {
            flag = true;
        }
        if(!(*iter)->isDead() && (*iter)->getXpos() >= 670 )
        {
            flag = false;
        }
    }
}

void CentipedeController::update()
{
    moveDivingObjects();
    moveFormation();
    deleteDeadCentipede(centipedetail);
    deleteDeadCentipede(headsegment);
}

void  CentipedeController::deleteDeadCentipede(VecOfCentipede& tail)
{
    VecOfCentipede temp;
    for (auto Centipede : tail)
    {
        if (!Centipede->isDead())
        {
            temp.push_back(Centipede);
        }
    }
    tail.clear();
    tail = temp;
}

void CentipedeController::setVectorOfcentipedetail(VecOfCentipede tail)
{
    centipedetail = tail;
}

void  CentipedeController::setVectorOfheadsegment(VecOfCentipede Head)
{
    headsegment = Head;
}

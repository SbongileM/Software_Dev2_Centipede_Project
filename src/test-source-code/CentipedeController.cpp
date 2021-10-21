#include "CentipedeController.h"
#include <cstdlib>
#include <time.h>

CentipedeController::CentipedeController() { }

void CentipedeController::createCentipede(int number_ofSegments)
{
    auto temp = number_ofSegments;

    for (int i =300; i <(300+(20*temp)); i+=20)
    {
        int j = 40;

        if (i == 300)
        {
            shared_ptr<Centipede> headsegment_(new Centipede(i,j));
            (headsegment_)->setDirection(Direction::LEFT);
            (headsegment_)->setBodyType(BodyType::HEAD);
            centipede_.push_back( headsegment_);
        }
        else
        {
            shared_ptr<Centipede> bodyseg(new Centipede(i,j));
            (bodyseg)->setDirection(Direction::LEFT);
            (bodyseg)->setBodyType(BodyType::BODYSEG);
            centipede_.push_back(bodyseg);
        }
    }
}

void CentipedeController::moveCentipede()
{
    for (auto iter=begin(centipede_); iter!=end(centipede_); ++iter)
    {

        if ((*iter)->HasReachedBottom() == false){moveDown((*iter));}

        else if ((*iter)->HasReachedBottom() == true){moveUp((*iter));}

        switch ((*iter)->getDirection())
        {
        case Direction::RIGHT:
            (*iter)->moveRight();
            break;
        case Direction::LEFT:
            (*iter)->moveLeft();
            break;
        default:
            break;
        }
    }
}

void CentipedeController::moveDown(shared_ptr<Centipede>& centipede)
{
    if (centipede->getYpos() >= 640){centipede->setBottomFlag(true);}

    else
    {
        if(centipede->getXpos() <= 0)
        {
            centipede->setDirection(Direction::RIGHT);
            centipede->moveDown();
        }

        else if(centipede->getXpos() >= 675)
        {
            centipede->setDirection(Direction::LEFT);
            centipede->moveDown();
        }
    }
}

void CentipedeController::moveUp(shared_ptr<Centipede>& centipede)
{
    if (centipede->getYpos() <= 500){centipede->setBottomFlag(false);}

    else
    {
        if(centipede->getXpos() <= 0)
        {
            centipede->setDirection(Direction::RIGHT);
            centipede->moveUp();
        }

        else if(centipede->getXpos() >= 675)
        {
            centipede->setDirection(Direction::LEFT);
            centipede->moveUp();
        }
    }
}

void CentipedeController::update()
{
    moveCentipede();
    deleteDeadCentipede(centipede_);
}

void  CentipedeController::deleteDeadCentipede(VecOfCentipede& centipede)
{
    VecOfCentipede temp;

    for (auto Centip : centipede)
    {
        if(!Centip->isDead()){temp.push_back(Centip);}
    }

    centipede.clear();
    centipede = temp;
}

void CentipedeController::setVecofCentipede (VecOfCentipede centipede)
{
    centipede_ = centipede;
}


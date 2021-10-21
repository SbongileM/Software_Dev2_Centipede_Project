#include "MushroomController.h"
#include "Configuration.h"
#include <ctime>

MushroomController::MushroomController()
{}

void MushroomController::createMushrooms(int number_of_mushrooms)
{
    srand(time(0));

    for (int i =0; i <number_of_mushrooms; i++)
    {
        int x = (rand()*20)%SCREENWIDTH;
        int y = (rand()*20)%SCREENHEIGHT;

        if ((y >= 60 && y <= SCREENHEIGHT-100) && (x > 0 && x < SCREENWIDTH ))
        {
            shared_ptr<Mushroom> mushroom(new Mushroom(x,y));
            mushrooms_.push_back(mushroom);
        }
    }
}

void MushroomController::createMushroom (int x, int y)
{
     shared_ptr<Mushroom> muShroom(new Mushroom(x,y));
     mushrooms_.push_back(muShroom);
}

void MushroomController::update()
{
    deleteDeadMushroom(mushrooms_);
}

void MushroomController::deleteDeadMushroom(Mushrooms &mushrooms_)
{
    Mushrooms temp;
    for (auto mushroom : mushrooms_)
    {
        if (mushroom->isAlive())
        {
            temp.push_back(mushroom);
        }
    }
    mushrooms_.clear();
    mushrooms_ = temp;
}

void MushroomController::setVecOfMushrooms(Mushrooms _mushrooms)
{
    mushrooms_ = _mushrooms;
}


#ifndef MUSHROOMCONTROLLER_H
#define MUSHROOMCONTROLLER_H
#include "Mushroom.h"


class MushroomController
{
    public:
        MushroomController();

        Mushrooms getVecOfMushrooms(){return mushrooms_;};

        void createMushrooms(int number_of_mushrooms);

        void createMushroom (int x, int y);

        void update();

        void setVecOfMushrooms(Mushrooms _mushrooms);

    private:
        Mushrooms mushrooms_;

        void deleteDeadMushroom(Mushrooms &mushrooms_);
};

#endif // MUSHROOMCONTROLLER_H

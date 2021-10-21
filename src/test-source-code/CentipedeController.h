#ifndef CENTIPEDECONTROLLER_H
#define CENTIPEDECONTROLLER_H
#include "Centipede.h"
#include "Utils.h"
#include <vector>
#include <memory>

#include <iostream>
using namespace std;

class CentipedeController
{
public:
    CentipedeController();

    VecOfCentipede getVecofCentipede() {return centipede_;};

    void createCentipede( int number_ofSegments);

    void setVecofCentipede (VecOfCentipede centipede);

    void update();

private:
    VecOfCentipede centipede_;

    void moveCentipede();

    void deleteDeadCentipede(VecOfCentipede& centipede);

    void moveDown(shared_ptr<Centipede>& centipede);

    void moveUp(shared_ptr<Centipede>& centipede);

};

#endif // CentipedeCONTROLLER_H

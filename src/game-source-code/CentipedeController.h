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
 /** \brief A constructor, which sets a flag to FALSE
     *
     */
    CentipedeController();

    /** \brief Returns bullet positions.
     *
     * \return vector of bullet positions
     *
     */
    vector<Position> getBulletPositions() {return _bulletPositions;};

    /** \brief Returns Centipedes in lower level of formation.
     *
     * \return vector of Centipedes
     *
     */
    VecOfCentipede getVectorOfcentipedetail() {return centipedetail;};

    /** \brief Returns Centipedes in second level of formation.
     *
     * \return vector of Centipedes
     *
     */
    VecOfCentipede getVectorOfheadsegment() {return headsegment;};

    /** \brief Creates all the Centipedes and determines how far apart they are.
     *
     */
    void createCentipede();

    /** \brief Creates a vector of Centipedes.
     *
     *  \param vector of Centipedes
     */
    void setVectorOfcentipedetail(VecOfCentipede centipedetail);

    /** \brief Creates a second vector of Centipedes.
     *
     *  \param vector of Centipedes
     */
    void setVectorOfheadsegment(VecOfCentipede headsegment);

    /** \brief Creates a vector of a special type of Centipede
     *          known as flagship escorts.
     *
     *  \param vector of Centipedes
     */

    /** \brief Moves Centipedes and updates all Centipede vectors by making
     *          sure that dead Centipedes are deleted.
     *
     */
    void update();

private:
    /** \brief Responsible for the movement of diving Centipedes.
     *
     *  \param vector of Centipedes
     */
    void moveDiving(VecOfCentipede centipedetail);

    /** \brief Responsible for the movement of diving Centipedes
     *
     */
    void moveDivingObjects();

    /** \brief Responsible for the movement of Centipedes which are still in formation
     *
     */
    void moveFormation();

    /** \brief Finds and deletes all dead Centipedes from a Centipede vector
     *
     *  \param vector of Centipedes
     */
    void deleteDeadCentipede(VecOfCentipede& centipedetail);

    int num3, remainder, randomNum;
    bool flag;
    VecOfCentipede centipedetail;
    VecOfCentipede headsegment;
    vector<Position> _bulletPositions;
    void setFlag(VecOfCentipede centipedetail);
};

#endif // CentipedeCONTROLLER_H

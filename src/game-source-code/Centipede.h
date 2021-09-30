#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <vector>
#include <memory>
#include "Utils.h"

using std::vector;
using namespace std;

class Centipede
{
public:
     /** \brief Constructor
     *
     * It sets the x and y coordinates of a centipede.
     *
     * \param x float
     * \param y float
     *
     */
    Centipede(float x, float y);

    /** \brief Returns the x position of a centipedeseg.
     *
     * \return float
     *
     */
    float getXpos();

    /** \brief Returns the y position of a centipedeseg.
     *
     * \return float
     *
     */
    float getYpos();

    /** \brief Returns true if the centipedeseg is ALIVE.
     *
     * \return bool
     *
     */
    bool isAlive();

    /** \brief Returns true if the centipedeseg is DEAD.
     *
     * \return bool
     *
     */
    bool isDead();

    /** \brief Returns true if the centipedeseg is DIVING.
     *
     * \return bool
     *
     */
    bool isDiving();

    /** \brief Moves a centipedeseg a centipedeseg to the left.
     *
     */
    void moveLeft();

    /** \brief Moves a centipedeseg a centipedeseg to the right.
     *
     */
    void moveRight();

    /** \brief Controls how the centipedeseg dives.
     *
     */
    void dive();

    /** \brief Sets the state of a centipedeseg to DEAD or ALIVE.
     *
     */
    void setState(State state);

private:
    float formationXpos;
    float formationYpos;
    float xPosition;
    float yPosition;
    State state_of_centipede;
    double speed = 8;

};

typedef vector<shared_ptr<Centipede>> VecOfCentipede;

#endif // CENTIPEDE_H

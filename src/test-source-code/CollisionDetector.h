#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include <vector>
#include <memory>
#include "BulletsController.h"
#include "CentipedeController.h"
#include "Player.h"
#include "Configuration.h"

using namespace std;

class CollisionDetector
{
public:
    /** \brief Default Constructor
     *
     * It initialises private data members of the class
     */
    CollisionDetector();

    /** \brief Checks when collisions occur between various game objects.
     *
     * \param VecOfCentipede& centipedetail centipedetail in the fourth and fifth rows from the top
     * \param VecOfCentipede& headsegment centipedetail in the third row from the top
     * \param VecOfCentipede& flagShipEscorts Flagship escorts (in the second row from the top)
     * \param VecOfCentipede& flagShips Flagships (top row)
     * \param BulletList& bullets All game bullets (Centipedeseg and Player)
     * \param Player& Player The player's ship
     */
    void checkCollisions(VecOfCentipede& centipedetail,VecOfCentipede& headsegment, BulletList& bullets);

    /** \brief Checks whether the game is over or still in progress.
     *
     * \return bool
     *
     */
    bool isGameOver()
    {
        return _gameOver == true;
    };

    /** \brief Returns the current score of the player.
     *
     * \return int
     *
     */
    int  getScore()
    {
        return score;
    };

private:
    /** \brief Detects collisions between a Centipedeseg and a bullet.
    *
    *   \param Pointer to a Centipedeseg object
    *   \param Pointer to a bullet
    *   \return Returns true if a collision has occurred and returns false otherwise
    */
    bool hasCollided(shared_ptr<Centipede> Centipedeseg, BulletPtr bullet);


    /** \brief Increments the score after a collision between a Centipedeseg and a
     *          bullet has occurred and sets the states of both the bullet and the Centipedeseg to DEAD
     *
     * \param  Vector of centipedetail
     * \param  List of bullets
     * \param  Integer representing the points the score is incremented by.
     */
    void checkCentipedesegAndBullet(VecOfCentipede& centipedetail,BulletList& bullets, int points);

    int score;
    bool _gameOver;
};

#endif // COLLISIONDETECTOR_H

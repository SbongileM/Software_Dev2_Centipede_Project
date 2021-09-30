#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "CollisionDetector.h"


using namespace std;

/** \brief An enum type.
 *
 * GameState is an enum type which has two possible values:
 * Online and GameOver.
 * These are used to determine what state the game is in.
 */
typedef enum
{
    Online,
    GameOver
} GameState;

class GameBase
{
public:
    /** \brief Default Constructor
     *
     * It starts the game by setting the state to online
     *         and creates centipedetail.
     */
    GameBase();

    /** \brief Returns the state of the game, namely; Online and GameOver.
     *
     * \return GameState
     *
     */
    GameState getState(){return state;};

    /**  Allows
     */
    /** \brief Returns the player.
     *
     * \return player
     *
     */
    Player getPlayer(){return  player_;};

    /** \brief Allows access to the score
     *
     * \return int
     *
     */
    int getScore() {return score;};

    /** \brief Returns true if win is true.
     *
     * \return bool
     *
     */
    bool youWin() {return win==true;};

    /** \brief Allows access to a vector of centipedetail.
     *
     * \return VecOfCentipede
     *
     */
    VecOfCentipede getVectorOfCentipedetail() {return centipedetail;};


    /** \brief Allows access to a second vector of centipedetail.
     *
     * \return VecOfCentipede
     *
     */
    VecOfCentipede getVectorOfheadsegment(){return headsegment;};

    /** \brief Returns a list of bullets
     *
     * \return BulletList
     *
     */
    BulletList getVectorOfBullets() {return bullets;};

    /** \brief Allows creation of all Centipedeseg type objects
     *
     */
    void createCentipedeseg();

    /** \brief Ensures that all game objects are in a valid state and
     *   are up to date.
     */
    void gameLogic();

    /** \brief Responsible for the galaxip shooting bullets.
     *
     */
    void shootPlayerBullet();

    /** \brief Sets the state of the game.
     *
     * \param GameState
     */
    void setState(GameState gameState);

    /** \brief Responsible for the galaxip moving left.
     *
     */
    void PlayerMoveleft();

    /** \brief Responsible for the galaxip moving right.
     */
    void PlayerMoveRight();

private:
    /**  \brief Allows access to all types of centipedetail.
     */
    void getCentipedesegVectors();

    /**  \brief Makes sure that the vector of centipedetail is up to date and in a valid state.
     */
    void setCentipedesegVectors();

    /**  \brief Returns true if all centipedetail are dead.
     */
    bool allCentipedesegDead();

    bool win;
    int score;
    Player  player_;
    BulletList bullets;
    GameState state;
    VecOfCentipede centipedetail;
    VecOfCentipede headsegment;
    BulletsController bulletsController;
    CentipedeController centipedeController_;
};

#endif // GAMEBASE_H

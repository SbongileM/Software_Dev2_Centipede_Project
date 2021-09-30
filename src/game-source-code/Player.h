#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"

class Player
{
public:

    /** \brief Default Constructor
     *
     * Initialises the private members of the class.
     */
     Player();

    /** \brief Returns true galaxip if ALIVE.
     *
     * \return bool
     *
     */
    bool isAlive();

    /** \brief Returns a float which represents the x coordinate of the player.
     *
     * \return float
     *
     */
    float getXpos();

    /** \brief Returns a float which represents the y coordinate of the player.
     *
     * \return float
     *
     */
    float getYpos();

    /** \brief Sets the state of the player, namely dead or alive.
     *
     * \param state State
     * \return void
     *
     */
    void setState(State state);

    /** \brief Moves the player to the left.
     *
     */
    void moveLeft();

    /** \brief Moves the player to the right.
     *
     */
    void moveRight();

private:
    int speed;
    float xPosition;
    float yPosition;
    State state_of_player;
};

#endif // PLAYER_H

#include "Bullet.h"
#include "CollisionDetector.h"
#include "Centipede.h"
#include "Player.h"
#include "GameBase.h"
#include "Utils.h"


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"



// ------------- Tests for Player ----------------

TEST_CASE("Player is Alive")
{
    auto player = Player();
    auto alive = State::ALIVE;
    player.setState(alive);

    CHECK(player.isAlive());
}

TEST_CASE("Player moves up")
{
    auto player = Player();
    auto tempx = player.getXpos();
    auto tempy = player.getYpos();
    player.moveUp();
    auto x = player.getXpos();
    auto y = player.getYpos();

    CHECK(y<tempy);
    CHECK(x==tempx);
}

TEST_CASE("Player moves down")
{
    auto player = Player();
    auto tempx = player.getXpos();
    auto tempy = player.getYpos();
    player.moveDown();
    auto x = player.getXpos();
    auto y = player.getYpos();

    CHECK(y>tempy);
    CHECK(x==tempx);
}

TEST_CASE("Player moves left")
{
    auto player = Player();
    auto tempx = player.getXpos();
    auto tempy = player.getYpos();
    player.moveLeft();
    auto x = player.getXpos();
    auto y = player.getYpos();

    CHECK(y==tempy);
    CHECK(x<tempx);
}

TEST_CASE("Player moves right")
{
    auto player = Player();
    auto tempx = player.getXpos();
    auto tempy = player.getYpos();
    player.moveRight();
    auto x = player.getXpos();
    auto y = player.getYpos();

    CHECK(y==tempy);
    CHECK(x>tempx);
}

TEST_CASE("Player moves at a correct speed")
{
    auto player = Player();
    auto tempx = player.getXpos();
    auto tempy = player.getYpos();

    player.moveLeft();
    auto x = player.getXpos();
    CHECK(x==(tempx-20));

    player.moveRight();
    x = player.getXpos();
    CHECK(x==tempx);

    player.moveUp();
    auto y = player.getYpos();
    CHECK(y==(tempy-20));

    player.moveDown();
     y = player.getYpos();
    CHECK(y==tempy);
}
// ------------- Tests for Centipede ----------------
//


// ------------- Tests for Collisions ----------------
//
//// Test null case for contains() first - here, an empty line


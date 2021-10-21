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
// ------------- Tests for Centipede ----------------
//


// ------------- Tests for Collisions ----------------
//
//// Test null case for contains() first - here, an empty line


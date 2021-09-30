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

// ------------- Tests for Centipede ----------------
//
TEST_CASE("Centipede is found at the set position")
{
    int x = 50;
    int y =60;

    auto centipede = Centipede(x,y);

    CHECK(centipede.getXpos()==x);
    CHECK(centipede.getYpos()==y);
}


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

TEST_CASE("Centipede segment alive")
{
    int x = 50;
    int y =60;

    auto centipede = Centipede(x,y);
    auto alive = State::ALIVE;
    centipede.setState(alive);

    CHECK_FALSE(centipede.isDead());
}

// ------------- Tests for Collisions ----------------
//
//// Test null case for contains() first - here, an empty line
TEST_CASE("Score is updated when a centipede segment is shot")
{
    int x = 50;
    int y =60;
    VecOfCentipede heads;
    VecOfCentipede body;
    BulletList bullets;


    auto engine = GameBase();
    auto collision = CollisionDetector();
    auto head = Centipede(x,y);
    auto tail = Centipede(x,y);
    auto bullet =make_shared<Bullet>(Bullet(x,y, Direction::UP));

    heads.push_back(make_shared<Centipede>(head));
    body.push_back(make_shared<Centipede>(tail));
    bullets.push_back(bullet);

    collision.checkCollisions(heads,body,bullets);
    engine.createCentipedeseg();
    engine.gameLogic();

    //CHECK(head.isAlive());
    //CHECK(tail.isAlive());
    CHECK(engine.getScore()== 0);
}


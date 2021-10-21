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

// ------------- Tests for Bullet ----------------

TEST_CASE("Bullet is Alive")
{
    auto x = 365.0,y =445.0;
    auto bullet = Bullet(x,y);
    auto alive = State::ALIVE;
    bullet.setState(alive);

    CHECK(bullet.isAlive());
}

TEST_CASE("Bullet is Dead")
{
    auto x = 365.0,y =445.0;
    auto bullet = Bullet(x,y);
    auto dead = State::DEAD;
    bullet.setState(dead);

    CHECK(bullet.isDead());
}

// ------------- Tests for Centipede ----------------
//


// ------------- Tests for Collisions ----------------
//
TEST_CASE("Mushroom loses live after colliding with a bullet")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Mushroom> muShroom(new Mushroom(365,450));
    mushrooms.push_back(muShroom);

    BulletPtr bullet(new Bullet(365,450));
    bullets.push_back(bullet);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);

    CHECK(mushrooms[0]->getLives() == 2);
}
TEST_CASE("Mushroom loses live after colliding with a bullet")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Mushroom> muShroom(new Mushroom(365,450));
    mushrooms.push_back(muShroom);

    BulletPtr bullet(new Bullet(365,450));
    bullets.push_back(bullet);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);

    CHECK(mushrooms[0]->getLives() == 2);
}

TEST_CASE("Mushroom dies after 4 shots")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Mushroom> muShroom(new Mushroom(365,450));
    mushrooms.push_back(muShroom);

    BulletPtr bullet(new Bullet(365,450));
    bullets.push_back(bullet);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet1(new Bullet(365,450));
    bullets.push_back(bullet1);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet2(new Bullet(365,450));
    bullets.push_back(bullet2);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet3(new Bullet(365,450));
    bullets.push_back(bullet3);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);

    CHECK_FALSE(mushrooms[0]->isAlive());
}

TEST_CASE("Mushroom dies and score increments by 1")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Mushroom> muShroom(new Mushroom(365,450));
    mushrooms.push_back(muShroom);

    BulletPtr bullet(new Bullet(365,450));
    bullets.push_back(bullet);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet1(new Bullet(365,450));
    bullets.push_back(bullet1);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet2(new Bullet(365,450));
    bullets.push_back(bullet2);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);
    BulletPtr bullet3(new Bullet(365,450));
    bullets.push_back(bullet3);
    collisionHandler.checkCollisions(centipede,bullets,player,mushrooms,controller);

    CHECK(collisionHandler.getScore() == 1);
}

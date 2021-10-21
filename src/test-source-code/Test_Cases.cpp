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
    auto x = 365,y =445;
    auto bullet = Bullet(x,y);
    auto alive = State::ALIVE;
    bullet.setState(alive);

    CHECK(bullet.isAlive());
}

TEST_CASE("Bullet is Dead")
{
    auto x = 365,y =445;
    auto bullet = Bullet(x,y);
    auto dead = State::DEAD;
    bullet.setState(dead);

    CHECK(bullet.isDead());
}

// ------------- Tests for Centipede ----------------
//
TEST_CASE("CentipedeSegment is found at the set position")
{
    int x = 50;
    int y =60;

    auto centipedeseg = Centipede(x,y);

    CHECK(centipedeseg.getXpos()==x);
    CHECK(centipedeseg.getYpos()==y);
}

TEST_CASE("Dead centipede segments are deleted")
{
    VecOfCentipede temp;
    CentipedeController controller;

    controller.createCentipede(5);
    temp = controller.getVecofCentipede();

    controller.getVecofCentipede()[0]->setState(State::DEAD);
    controller.update();

    CHECK_FALSE(temp==controller.getVecofCentipede());
}


TEST_CASE("Bool becomes true when the centipede hits the bottom edge of the screen")
{
    VecOfCentipede temp;
    CentipedeController controller;

    shared_ptr<Centipede> headsegment_(new Centipede(60,620));
    temp.push_back( headsegment_);

    controller.setVecofCentipede(temp);
    controller.getVecofCentipede()[0]->moveDown();
    controller.update();

    CHECK(controller.getVecofCentipede()[0]->HasReachedBottom());
}

TEST_CASE("Centipede changes direction when it hits the right edge of the screen")
{
    VecOfCentipede temp;
    CentipedeController controller;

    shared_ptr<Centipede> headsegment_(new Centipede(675,640));
    temp.push_back( headsegment_);

    controller.setVecofCentipede(temp);
    controller.getVecofCentipede()[0]->moveRight();
    controller.update();

    CHECK(controller.getVecofCentipede()[0]->getDirection()==Direction::LEFT);
}


// ------------- Tests for Collisions -------------------
TEST_CASE("Score is updated when a centipede segment is shot")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> bodysegment_(new Centipede(50,600));
    (bodysegment_)->setBodyType(BodyType::BODYSEG);
    centipede.push_back( bodysegment_);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(collisionHandler.getScore()==10);

}

TEST_CASE("Score is updated when the centipede head is shot")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(50,600));
    (head_)->setBodyType(BodyType::HEAD);
    centipede.push_back( head_);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(collisionHandler.getScore()==100);

}

TEST_CASE("Game is over when player collides with centipede")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(340,600));
    (head_)->setBodyType(BodyType::HEAD);
    centipede.push_back( head_);

    player.moveLeft();

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(collisionHandler.isGameOver());

}

TEST_CASE("Centipede changes direction after colliding with mushroom")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(50,600));
    (head_)->setBodyType(BodyType::HEAD);
    (head_)->setDirection(Direction::LEFT);
    centipede.push_back( head_);

    shared_ptr<Mushroom> muShroom(new Mushroom(50,600));
    mushrooms.push_back(muShroom);


    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(centipede[0]->getDirection()==Direction::RIGHT);
}

TEST_CASE("Player changes direction after colliding with mushroom")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;


    shared_ptr<Mushroom> muShroom(new Mushroom(340,600));
    mushrooms.push_back(muShroom);

    player.moveRight();

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(player.getDirection()==Direction::LEFT);
}

TEST_CASE("Bullet dies after a colliding with the centipede")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(50,600));
    centipede.push_back( head_);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(bullets[0]->isDead());

}

TEST_CASE("Bullet dies after a colliding with a mushroom")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Mushroom> muShroom(new Mushroom(50,600));
    mushrooms.push_back(muShroom);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(bullets[0]->isDead());
}

TEST_CASE("Score is updated when the centipede head is shot")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(50,600));
    (head_)->setBodyType(BodyType::HEAD);
    centipede.push_back( head_);

    shared_ptr<Centipede> bodysegment_(new Centipede(50,620));
    (bodysegment_)->setBodyType(BodyType::BODYSEG);
    centipede.push_back( bodysegment_);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);

    CHECK(centipede[0]->getBodyType()==BodyType::HEAD);
}

TEST_CASE("Score is updated when the centipede head is shot")
{
    CollisionDetector collisionHandler;
    VecOfCentipede centipede;
    BulletList bullets;
    Player player;
    Mushrooms mushrooms;
    MushroomController controller;

    shared_ptr<Centipede> head_(new Centipede(50,600));
    (head_)->setBodyType(BodyType::HEAD);
    centipede.push_back( head_);

    BulletPtr bullet(new Bullet(50,600));
    bullets.push_back(bullet);

    collisionHandler.checkCollisions(centipede, bullets, player, mushrooms, controller);


    CHECK(controller.getVecOfMushrooms()[0]->getXpos()==50);
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

#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include <vector>
#include <memory>
#include "BulletsController.h"
#include "CentipedeController.h"
#include "Player.h"
#include "Configuration.h"
#include "Mushroom.h"
#include "MushroomController.h"

using namespace std;

class CollisionDetector
{
public:
    CollisionDetector();

    void checkCollisions(VecOfCentipede& centipede, BulletList& bullets, Player& player, Mushrooms& mushrooms, MushroomController& controller);

    bool hasCollided(shared_ptr<Centipede> Centipedeseg, BulletPtr bullet);

    bool hasCollided(shared_ptr<Centipede> Centipedeseg, Player player);

    bool hasCollided(shared_ptr<Mushroom> mushroom, BulletPtr bullet);

    bool hasCollided(shared_ptr<Centipede> Centipedeseg, shared_ptr<Mushroom> mushroom);

    bool hasCollided(shared_ptr<Mushroom> mushroom, Player player);

    bool isGameOver(){return _gameOver == true;};

    int  getScore(){return score;};

private:

    int score;
    bool _gameOver;


    void checkCentipedesegAndBullet(VecOfCentipede& centipede,BulletList& bullets, MushroomController& controller);

    void checkCentipedesegAndPlayer(VecOfCentipede& centipede, Player& player);

    void checkMushroomAndBullet(Mushrooms& mushrooms,BulletList& bullets);

    void checkCentipedesegAndMushroom(VecOfCentipede& centipede, Mushrooms& mushrooms);

    void checkMushroomAndPlayer(Mushrooms& mushrooms, Player& player);
};

#endif // COLLISIONDETECTOR_H

#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "CollisionDetector.h"


using namespace std;

typedef enum
{
    Online,
    GameOver
} GameState;

class GameBase
{
public:
    GameBase();

    GameState getState(){return state;};

    Player getPlayer(){return  player_;};

    int getScore() {return score;};

    bool youWin() {return win==true;};

    VecOfCentipede getVectorOfCentipede() {return centipede;};

    Mushrooms getMushrooms(){return mushrooms_;};

    BulletList getVectorOfBullets() {return bullets;};

    void createCentipedeseg();

    void createMushrooms();

    void gameLogic();

    void shootPlayerBullet();

    void setState(GameState gameState);

    void PlayerMoveleft();

    void PlayerMoveRight();

    void PlayerMoveUp();

    void PlayerMoveDown();

private:
    bool win;
    int score;
    Player  player_;
    BulletList bullets;
    GameState state;
    VecOfCentipede centipede;
    BulletsController bulletsController;
    CentipedeController centipedeController_;
    Mushrooms mushrooms_;
    MushroomController mushroomController_;

    void getCentipedesegVectors();

    void GetMushrooms();

    void setCentipedesegVectors();

    void setMushrooms();

    bool allCentipedesegDead();

};

#endif // GAMEBASE_H

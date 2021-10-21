#ifndef GAME_H
#define GAME_H
#include "Utils.h"
#include "DrawText.h"
#include "DrawObjects.h"

class Game
{
public:
    Game();

    void getGame(RenderWindow&, ScreenView&);

private:
    bool win;
    int numOfLives,score;

    string highScore;
    string convertToString(int Num);

    Sprite  background;
    Texture texture;
    BulletList bullets;
    DrawText display;
    DrawObjects drawObjects;
    Player player_;
    GameBase gamelogic;
    VecOfCentipede centipede;
    Mushrooms mushrooms_;

    string getHighScore();

    void endOfGame(RenderWindow&, ScreenView&);

    void getGameObjects();

    void paintBackground();

    void pollforUserInput(RenderWindow& window);

    void saveHighScore();

    void screenConstants(RenderWindow&);

    void startGame(RenderWindow&, ScreenView&);
};

#endif // GAME_H

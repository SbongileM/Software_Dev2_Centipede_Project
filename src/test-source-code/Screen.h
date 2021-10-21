#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Menu.h"
#include "Game.h"
#include "DisplayHelp.h"

using namespace sf;

class Screen
{
public:
    Screen();

    void display();

    void accessMenu();

    void accessGame();

    void accessHelp();

private:
    RenderWindow window;
    ScreenView _screenView;
    Menu menu;
    Game game;
    DisplayHelp help;
};

#endif // SCREEN_H

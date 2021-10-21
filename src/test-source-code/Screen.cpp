#include "Screen.h"

Screen::Screen()
{
    window.create(VideoMode(700,660),"CENTIPEDE",Style::Default);
    window.setFramerateLimit(10);
    _screenView = MENU;
}

void Screen::accessMenu()
{
    menu.getMenu(window,_screenView);
}

void Screen::accessGame()
{
    Game newGame;
    newGame.getGame(window,_screenView);
}

void Screen::accessHelp()
{
    help.getHelp(window,_screenView);
}

void Screen::display()
{
    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
            {
                window.close();
                break;
            }
        }
        switch(_screenView)
        {
        case MENU:
            accessMenu();
            break;
        case HELP:
            accessHelp();
            break;
        case GAME:
            accessGame();
            break;
        default:
            ;
        }
    }
}

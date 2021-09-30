#include "Screen.h"

Screen::Screen()
{
    window.create(VideoMode(700,700),"CENTIPEDE",Style::Default);
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
            if((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
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

#include "DisplayHelp.h"
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;
DisplayHelp::DisplayHelp(){ }//Default Constructor

void DisplayHelp::getHelp(RenderWindow& window, ScreenView& screenView)
{
    help(window, screenView);
}
void DisplayHelp::help(RenderWindow& window, ScreenView& screenView)
{
    while (window.isOpen() && screenView == HELP)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
            else if (event.type == Event::KeyPressed)
            {
                if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) window.close();
                if (event.key.code == Keyboard::BackSpace) screenView = MENU;
            }
        }
        window.clear(Color::Black);
        screenConstants(window);
        window.display();
    }
}

void DisplayHelp::screenConstants(RenderWindow& window)
{
    string line;
    int yPos = 0;

    display.setTextColor(Color::White);
    display.setFont("resources/font.ttf");

    ifstream filereader("resources/help.txt");
    if (!filereader) throw logic_error("help.txt could not be opened");
    while (getline(filereader, line))
    {
        yPos += +30;
        display.displayText(line, 30, Vector2f(20,yPos), window);
    }
    display.setFont("resources/transformers_movie.ttf");
}
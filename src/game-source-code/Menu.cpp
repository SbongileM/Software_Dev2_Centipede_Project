#include "Menu.h"

Menu::Menu()
{
    font.loadFromFile("resources/ARLRDBD.TTF");
    texture.loadFromFile("resources/menu.png");
    paintBackground();
}

void Menu::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}

void Menu::drawMenuOptions(RenderWindow &window)
{
        display.setTextColor(Color::Green);
        display.displayText("CENTIPEDE MENU", 60, Vector2f(50,20), window);
        display.setTextColor(Color::White);
        display.displayText("Move down and press enter", 20, Vector2f(50,100), window);
        display.displayText("for playing instructions", 20, Vector2f(50,120), window);
        display.displayText("START GAME", 40, Vector2f(50,150), window);
        display.displayText("HELP", 40, Vector2f(50,200), window);
}

void Menu::getMenu(RenderWindow& window, ScreenView &screenView)
{
    Text arrow(">", font , 40);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(20,150);
    arrow.setFillColor(Color::White);

    while (window.isOpen() && screenView == MENU)
    {
        window.clear(Color::Black);
        window.draw(background);
        color = Color::Red;
        drawMenuOptions(window);
        color = Color::White;
        window.draw(arrow);
        window.display();

        Event gamemenu;
        while (window.pollEvent(gamemenu))
        {
            Vector2f arrowPos = arrow.getPosition();

            if (gamemenu.type == Event::Closed){window.close();}

            else if (gamemenu.type == Event::KeyPressed)
            {
              switch (gamemenu.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    break;

                case Keyboard::Return:
                    if(arrowPos.y == 150) {screenView = GAME;}
                    else if(arrowPos.y == 200) {screenView = HELP;}
                    break;

                case Keyboard::Up:
                    if(arrowPos.y!=150){arrow.setPosition(arrowPos.x,arrowPos.y-50);}
                    break;

                case Keyboard::Down:
                    if(arrowPos.y!=200){arrow.setPosition(arrowPos.x,arrowPos.y+50);}
                    break;

                default:
                    break;
                }

            }
        }
    }
}

#include "Menu.h"

Menu::Menu() //loads menu font and menu background
{
    font.loadFromFile("resources/ARLRDBD.TTF");
    texture.loadFromFile("resources/menu.png");
    paintBackground();//prints background
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
        display.displayText("START GAME", 40, Vector2f(50,100), window);
        display.displayText("HELP", 40, Vector2f(50,150), window);
}
void Menu::getMenu(RenderWindow& window, ScreenView &screenView)
{
    Text arrow(">", font , 40);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(20,100);
    arrow.setFillColor(Color::White);

    while (window.isOpen() && screenView == MENU)
    {
        window.clear(Color::Black);
        window.draw(background);//earth
        color = Color::Red;
        drawMenuOptions(window);
        color = Color::White;
        window.draw(arrow);
        window.display();

        Event gamemenu;
        while (window.pollEvent(gamemenu))
        {
            Vector2f arrowPos = arrow.getPosition();

            if (gamemenu.type == Event::KeyPressed)
            {
                if ((gamemenu.type == sf::Event::Closed) || (gamemenu.key.code == sf::Keyboard::Escape))window.close();
                if (gamemenu.key.code == Keyboard::Return)
                {
                    if(arrowPos.y == 100) screenView = GAME;
                    if(arrowPos.y == 150) screenView = HELP;
                }
                if (gamemenu.key.code == Keyboard::Up)
                {
                    if(arrowPos.y!=100)arrow.setPosition(arrowPos.x,arrowPos.y-50);
                }
                if (gamemenu.key.code == Keyboard::Down)
                {
                    if(arrowPos.y!=200)arrow.setPosition(arrowPos.x,arrowPos.y+50);
                }
            }
        }
    }
}

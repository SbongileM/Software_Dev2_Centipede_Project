#ifndef MENU_H
#define MENU_H
#include "Utils.h"
#include "DrawText.h"

class Menu
{
public:
    Menu();
    void getMenu(RenderWindow&, ScreenView&);

private:
    DrawText display;
    Font font;
    Color color;
    Sprite  background;
    Texture texture;

    void drawMenuOptions(RenderWindow &window);
    void paintBackground();
};

#endif // MENU_H

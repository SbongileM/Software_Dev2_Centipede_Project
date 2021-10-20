#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameBase.h"
#include <cstring>
#include <iostream>

using namespace sf;
using namespace std;


class DrawText
{
public:
    DrawText();

    void displayText(string, int, Vector2f, RenderWindow &);

    void setTextColor(Color newColor){color = newColor;};

    void setFont(string);

private:
    Font font;
    Color color;
    Texture texture;
};

#endif // DISPLAY_H

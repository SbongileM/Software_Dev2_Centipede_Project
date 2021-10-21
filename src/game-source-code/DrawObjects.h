#ifndef DRAWOBJECTS_H
#define DRAWOBJECTS_H
#include "DrawText.h"


class DrawObjects
{
public:
    DrawObjects();

    void drawObjects(RenderWindow&,VecOfCentipede,BulletList, Player,Mushrooms);

private:
    bool win = false;
    Color color;
    Texture player_;
    Texture bullet;
    Texture bodysegment;
    Texture head;
    Texture mushroom1;
    Texture mushroom2;
    Texture mushroom3;
    Texture mushroom4;

    void drawBullets(RenderWindow& window, BulletList bullets);
    void drawCentipede(VecOfCentipede centipede, RenderWindow& window);
    void drawMushrooms(Mushrooms mushroomz,RenderWindow& window);
    void drawObject(Texture texture, float x, float y, RenderWindow&);
};

#endif // DRAWOBJECTS_H

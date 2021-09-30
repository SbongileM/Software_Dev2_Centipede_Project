#include "DrawObjects.h"

DrawObjects::DrawObjects() {}

void DrawObjects::drawObjects(RenderWindow& window,VecOfCentipede tail,VecOfCentipede head,vector <BulletPtr> bullets, Player player)
{
    texture.loadFromFile("resources/tail.png");
    drawCentipede(tail,window);

    texture.loadFromFile("resources/head.png");
    drawCentipede(head,window);

    texture.loadFromFile("resources/bullet.png");
    drawBullets(window, bullets);

    texture.loadFromFile("resources/player.png");
    drawObject(texture,player.getXpos(),player.getYpos(), window );
    window.display();
}


void DrawObjects::drawCentipede(VecOfCentipede tail, RenderWindow& window)
{
    for (auto iter=begin(tail); iter!=end(tail); ++iter)
        if((*iter)->isAlive()||(*iter)->isDiving()) drawObject(texture,(*iter)->getXpos(),(*iter)->getYpos(), window);
}

void DrawObjects::drawObject(Texture texture, float x, float y, RenderWindow& window)
{
    Sprite  ship;
    ship.setTexture(texture);
    ship.setTextureRect(IntRect(0, 0, 71, 98));
    ship.setPosition(x,y);
    ship.scale(0.4, 0.4);
    window.draw(ship);
}

void DrawObjects::drawBullets(RenderWindow& window, vector <BulletPtr> bullets)
{
    for (auto iter=begin(bullets); iter!=end(bullets); ++iter)
        if((*iter)->getDirection() == DOWN && (*iter)->isAlive())
        {
            color = Color::Red;
            drawBullet(texture,(*iter)->getXpos(),(*iter)->getYpos(),window);
        }
        else if ((*iter)->getDirection() == UP && (*iter)->isAlive())
        {
            color = Color::White;
            drawBullet(texture,(*iter)->getXpos(),(*iter)->getYpos(),window);
        }
}

void DrawObjects::drawBullet(Texture texture,float x, float y, RenderWindow& window)
{
    Sprite bullet;
    bullet.setTexture(texture);
    bullet.setTextureRect(IntRect(0, 0, 71, 98));
    bullet.setPosition(x,y);
    bullet.scale(0.4, 0.4);
    window.draw(bullet);
}

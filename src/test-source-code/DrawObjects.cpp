#include "DrawObjects.h"

DrawObjects::DrawObjects(){}

void DrawObjects::drawObjects(RenderWindow& window,VecOfCentipede centipede,vector <BulletPtr> bullets, Player player,Mushrooms mushrooms)
{
    head.loadFromFile("resources/head.png");
    mushroom1.loadFromFile("resources/mushroom1.png");
    mushroom2.loadFromFile("resources/mushroom2.png");
    mushroom3.loadFromFile("resources/mushroom3.png");
    mushroom4.loadFromFile("resources/mushroom.png");

    texture.loadFromFile("resources/tail.png");
    drawCentipede(centipede,window);

    texture.loadFromFile("resources/bullet.png");
    drawBullets(window, bullets);

    texture.loadFromFile("resources/player.png");
    drawObject(texture,player.getXpos(),player.getYpos(), window );

    drawMushrooms(mushrooms, window);
    window.display();
}


void DrawObjects::drawCentipede(VecOfCentipede centipede, RenderWindow& window)
{
    for (auto iter=begin(centipede); iter!=end(centipede); ++iter)
    {
        if((*iter)->getBodyType() == BodyType::HEAD)
        {
            drawObject(head,(*iter)->getXpos(),(*iter)->getYpos(), window);
        }
        else if((*iter)->getBodyType() == BodyType::BODYSEG)
        {
            drawObject(texture,(*iter)->getXpos(),(*iter)->getYpos(), window);
        }
    }

}

void DrawObjects::drawMushrooms(Mushrooms mushrooms,RenderWindow& window)
{
    for (auto iter=begin(mushrooms); iter!=end(mushrooms); ++iter)
    {
        if ((*iter)->isAlive())
        {
            if ((*iter)->getLives() == 3){drawObject(mushroom4,(*iter)->getXpos(),(*iter)->getYpos(), window);}

            else if ((*iter)->getLives() == 2){drawObject(mushroom1,(*iter)->getXpos(),(*iter)->getYpos(), window);}

            else if ((*iter)->getLives() == 1){drawObject(mushroom2,(*iter)->getXpos(),(*iter)->getYpos(), window);}

            else if ((*iter)->getLives() == 0){drawObject(mushroom3,(*iter)->getXpos(),(*iter)->getYpos(), window);}
        }
    }
}

void DrawObjects::drawObject(Texture texture, float x, float y, RenderWindow& window)
{
    Sprite  ship;
    ship.setTexture(texture);
    ship.setTextureRect(IntRect(0, 0, 71, 98));
    ship.setPosition(x,y);
    ship.scale(0.281, 0.204);
    window.draw(ship);
}

void DrawObjects::drawBullets(RenderWindow& window, vector <BulletPtr> bullets)
{
    for (auto iter=begin(bullets); iter!=end(bullets); ++iter)
    {
        if ((*iter)->isAlive())
        {
            drawObject(texture,(*iter)->getXpos(),(*iter)->getYpos(),window);
        }
    }
}

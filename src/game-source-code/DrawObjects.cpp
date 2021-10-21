#include "DrawObjects.h"
#include <stdexcept>

DrawObjects::DrawObjects(){}

void DrawObjects::drawObjects(RenderWindow& window,VecOfCentipede centipede,vector <BulletPtr> bullets, Player player,Mushrooms mushrooms)
{
    if(!head.loadFromFile("resources/head.png")){throw logic_error("head.png could not be opened");}
    if(!mushroom1.loadFromFile("resources/mushroom1.png")){throw logic_error("mushroom1.png could not be opened");}
    if(!mushroom2.loadFromFile("resources/mushroom2.png")){throw logic_error("mushroom2.png could not be opened");}
    if(!mushroom3.loadFromFile("resources/mushroom3.png")){throw logic_error("mushroom3.png could not be opened");}
    if(!mushroom4.loadFromFile("resources/mushroom.png")){throw logic_error("mushroom.png could not be opened");}
    if(!bodysegment.loadFromFile("resources/tail.png")){throw logic_error("tail.png could not be opened");}
    if(!bullet.loadFromFile("resources/bullet.png")){throw logic_error("bullet.png could not be opened");}
    if(!player_.loadFromFile("resources/player.png")){throw logic_error("player.png could not be opened");}

    drawCentipede(centipede,window);
    drawBullets(window, bullets);
    drawObject(player_,player.getXpos(),player.getYpos(), window );
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
            drawObject(bodysegment,(*iter)->getXpos(),(*iter)->getYpos(), window);
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
            drawObject(bullet,(*iter)->getXpos(),(*iter)->getYpos(),window);
        }
    }
}

#ifndef DRAWOBJECTS_H
#define DRAWOBJECTS_H
#include "DrawText.h"


class DrawObjects
{
public:
    /** \brief Default Constructor
     *
     */
    DrawObjects();

    /** \brief Draws Centipede objects, Galaxip object and the Bullet objects on to the window.
     *
     * \param RenderWindow&
     * \param VecOfCentipede
     * \param VecOfCentipede
     * \param VecOfCentipede
     * \param VecOfCentipede
     * \param BulletList
     * \param Galaxip
     */
    void drawObjects(RenderWindow&,VecOfCentipede,VecOfCentipede,BulletList, Player);

private:
    Texture texture;
    Color color;
    void drawBullets(RenderWindow& window, BulletList bullets);
    void drawCentipede(VecOfCentipede centipede, RenderWindow& window);
    void drawObject(Texture texture, float x, float y, RenderWindow&);
    void drawBullet(Texture texture,float x, float y, RenderWindow& window);
    bool win = false;
};

#endif // DRAWOBJECTS_H

#ifndef BULLE0ULLETCONTROLLER_H
#include <vector>
#include "Bullet.h"
#include "Utils.h"
using std::vector;
typedef vector<BulletPtr> BulletList;
typedef vector<BulletPtr>::iterator BulletsListIter;

class BulletsController
{
public:
    void add(float, float);

    BulletList getBullets(){return _bullets;};

    void update();

    void setBullets(BulletList);

    void deleteDeadBullets(BulletList&);

private:
    BulletList _bullets;

};
#endif

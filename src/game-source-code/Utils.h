// A file of common things
#ifndef UTILS_H
#define UTILS_H
#include <vector>

using std::vector;

typedef vector<int> Position;

typedef enum
{
    LEFT,
    RIGHT,
    UP,
    DOWN
} Direction;

typedef enum
{
    ALIVE,
    DEAD
} State;

typedef enum
{
    MENU,
    GAME,
    HELP
} ScreenView;

#endif

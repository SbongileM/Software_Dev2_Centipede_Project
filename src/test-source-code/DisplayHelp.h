#ifndef DISPLAYHELP_H
#define DISPLAYHELP_H
#include "Utils.h"
#include "DrawText.h"

class DisplayHelp
{
public:
    DisplayHelp();
    void getHelp(RenderWindow& window, ScreenView& screenView);

private:
    DrawText display;

    void help(RenderWindow& window, ScreenView& screenView);
    void paintBackground();
    void screenConstants(RenderWindow& window);
};

#endif // DISPLAYHELP_H

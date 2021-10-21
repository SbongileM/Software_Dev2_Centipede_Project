#include "DrawText.h"
#include <sstream>
#include<stdexcept>

using namespace std;

DrawText::DrawText()
{
    if(!font.loadFromFile("resources/transformers_movie.ttf")){throw logic_error("transformers_movie.ttf could not be opened");}
    color = Color::White;
}

void DrawText::setFont(string newFont)
{
    font.loadFromFile(newFont);
}

void DrawText::displayText(string text, int textSize, Vector2f position, RenderWindow &window)
{
    Text textToBeDisplayed(text, font , textSize);
    textToBeDisplayed.setStyle(Text::Regular);
    textToBeDisplayed.setPosition(position);
    textToBeDisplayed.
    setFillColor(color);
    window.draw(textToBeDisplayed);
}

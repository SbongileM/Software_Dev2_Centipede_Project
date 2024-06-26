#include "Game.h"
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>

using namespace std;

Game::Game()
{
    win = false;
    score = 0;
    numOfLives = 1;
    texture.loadFromFile("resources/game_over.png");
    paintBackground();
}

void Game::getGame(RenderWindow& window, ScreenView &screenView)
{
    startGame(window, screenView);
}

void Game::screenConstants(RenderWindow& window)
{
    display.displayText("HIGHEST SCORE :", 20, Vector2f(10,5),window);
    display.displayText("SCORE :", 20, Vector2f(250,5),window);
    score = gamelogic.getScore();
    display.displayText(convertToString(score), 20, Vector2f(340,5),window);
    display.displayText("LIVES :", 20, Vector2f(410,5),window);
    display.displayText(convertToString(numOfLives), 20, Vector2f(500,5),window);
}

void Game::getGameObjects()
{
    player_ = gamelogic.getPlayer();
    centipede = gamelogic.getVectorOfCentipede();
    bullets = gamelogic.getVectorOfBullets();
    mushrooms_=gamelogic.getMushrooms();
}

void Game::startGame(RenderWindow& window, ScreenView& screenView)
{
    highScore = getHighScore();

    while (window.isOpen() && screenView == GAME)
    {
        window.clear(Color::Black);
        display.displayText(highScore, 20, Vector2f(180,5),window);

        if(gamelogic.getState() == GameState::Online)
        {
            screenConstants(window);
            pollforUserInput(window);
            gamelogic.gameLogic();
            getGameObjects();
            drawObjects.drawObjects(window,centipede,bullets, player_,mushrooms_);
        }
        else {endOfGame(window,screenView);}
    }
}

void Game::pollforUserInput(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed) {window.close();}
        else if (event.type == Event::KeyPressed)
        {
            switch(event.key.code)
            {
            case Keyboard::Left:
                gamelogic.PlayerMoveleft();
                break;
            case Keyboard::Right:
                gamelogic.PlayerMoveRight();
                break;
            case Keyboard::Up:
                gamelogic.PlayerMoveUp();
                break;
            case Keyboard::Down:
                gamelogic.PlayerMoveDown();
                break;
            case Keyboard::Space:
                gamelogic.shootPlayerBullet();
                break;
            case Keyboard::Escape:
                window.close();
            default:
                break;
            }
        }
    }
}

string Game::convertToString(int Num)
{
    string Result;
    ostringstream convert;
    convert << Num;
    Result = convert.str();
    return Result;
}

string Game::getHighScore()
{
    string score;
    ifstream filereader("resources/HighScore.txt");
    if (!filereader){throw logic_error("HighScore.txt could not be opened");}
    else {getline(filereader, score);}

    return score;
}

void Game::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}

void Game::endOfGame(RenderWindow& window, ScreenView &screenView)
{
    display.setTextColor(Color:: White);

    while (window.isOpen() && screenView == GAME)
    {
        window.clear(Color::Black);
        window.draw(background);
        win = gamelogic.youWin();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();

            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape) window.close();
                else if (event.key.code == Keyboard::Return) screenView = MENU;
            }
        }

        if(numOfLives == 1 && win == false)
        {
            saveHighScore();
            display.displayText("GAME OVER", 50, Vector2f(50,200),window);
            display.displayText("YOU LOST", 60, Vector2f(200,350),window);
            display.displayText("Press Enter", 40, Vector2f(350,500),window);
        }

        else if(win == true)
        {
            saveHighScore();
            display.setTextColor(Color::Green);
            display.displayText("YOU WIN !", 100, Vector2f(200,200),window);
            display.displayText("Press Enter", 40, Vector2f(350,400),window);
        }
        window.display();
    }
}
void Game::saveHighScore()
{
    ofstream ofile("resources/HighScore.txt");
    int hScore;
    istringstream ( highScore ) >> hScore;
    if (score > hScore && ofile) ofile << score << endl;
    else if (ofile) ofile << highScore << endl;

}



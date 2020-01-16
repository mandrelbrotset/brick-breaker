#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    std::string TITLE = "SFML Game";
    int W_WIDTH = 640;
    int W_HEIGHT = 480;
    /*
    int W_WIDTH = 1280;
    int W_HEIGHT = 960;
    */

    Game game(TITLE, W_WIDTH, W_HEIGHT);

    return 0;
}
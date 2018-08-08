#include <iostream>
#include <vector>
#include <string>
#include "ZombieGame.hpp"
#include "Menu.hpp"

int main()
{
    std::vector<std::string> options;
    options.push_back("Play Game");
    options.push_back("Quit");

    while(getMenu(options) != 2)
    {
        ZombieGame game;
        game.playGame();
    }
    return 0;
}

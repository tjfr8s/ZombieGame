/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/07/2018
 * Description: This file implements a ZombieGame. The player starts in a 
 * space on the board and must find the cure before their health runs out. The
 * game consists of a series of turns, on which the player fights any zombies
 * in a space and interacts with the items in the space. After the player 
 * finishes a turn, they leave the space and move to a space adjacent to the 
 * one they are currently occupying. The game ends when the player finds the 
 * cure or dies.
*******************************************************************************/ 
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

    // Ask the player if they want to play or quit.
    while(getMenu(options) != 2)
    {
        ZombieGame game;
        game.playGame();
    }
    return 0;
}

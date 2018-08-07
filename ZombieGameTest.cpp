#include "ZombieGame.hpp"

int main()
{
    ZombieGame game;
    for(int i = 0; i < 5; i++)
    {
        game.takeTurn();
    }
    return 0;
}

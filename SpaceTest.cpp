#include "Space.hpp"
#include "Player.hpp"

int main()
{
    Player testPlayer(8);
    std::cout << "is ded: " << testPlayer.isDead() << std::endl;
    testPlayer.die();
    std::cout << "is ded: " << testPlayer.isDead() << std::endl;

    return 0;
}

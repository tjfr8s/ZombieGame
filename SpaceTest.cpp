#include "Space.hpp"
#include "Player.hpp"

int main()
{
    Player testPlayer(8);
    std::cout << "is ded: " << testPlayer.isDead() << std::endl;
    testPlayer.die();
    std::cout << "is ded: " << testPlayer.isDead() << std::endl;

    std::cout << "player has knife? " << testPlayer.hasItem(Player::KNIFE) <<
        std::endl;
    testPlayer.addItem(Player::KNIFE);
    std::cout << "player has knife? " << testPlayer.hasItem(Player::KNIFE) <<
        std::endl;
    std::cout << "player has health? " << testPlayer.hasItem(Player::HEALTH) <<
        std::endl;



    return 0;
}

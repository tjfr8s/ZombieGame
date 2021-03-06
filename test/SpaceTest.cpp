#include "Space.hpp"
#include "Player.hpp"
#include "General.hpp"
#include "Kitchen.hpp"
#include "Bedroom.hpp"
#include "Attic.hpp"

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

    testPlayer.removeItem(Player::KNIFE);
    std::cout << "player has knife? " << testPlayer.hasItem(Player::KNIFE) <<
        std::endl;

    std::cout << "\n\nZombie test 1 **************************\n\n";
    General space("test", true, false, Player::KEY, nullptr, nullptr, nullptr, 
            nullptr);

    testPlayer.addItem(Player::KNIFE);
    testPlayer.setIsDead(false);
    std::cout << "zombie? " << space.hasZombie() << std::endl;
    std::cout << "testPlayer dead? " << testPlayer.isDead() << std::endl;
    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;

    space.fight(&testPlayer);

    std::cout << "zombie? " << space.hasZombie() << std::endl;
    std::cout << "testPlayer dead? " << testPlayer.isDead() << std::endl;
    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;

    std::cout << "\n\nZombie test 2 **************************\n\n";

    testPlayer.removeItem(Player::KNIFE);
    space.toggleZombie();
    std::cout << "zombie? " << space.hasZombie() << std::endl;
    std::cout << "testPlayer dead? " << testPlayer.isDead() << std::endl;
    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;

    space.fight(&testPlayer);

    std::cout << "zombie? " << space.hasZombie() << std::endl;
    std::cout << "testPlayer dead? " << testPlayer.isDead() << std::endl;
    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;



    testPlayer.removeItem(Player::KEY);
    testPlayer.setIsDead(false);

    std::cout << "testPlayer has key? " << 
        testPlayer.hasItem(Player::KEY) << std::endl;

    space.action(&testPlayer);

    std::cout << "testPlayer has key? " << 
        testPlayer.hasItem(Player::KEY) << std::endl;


    std::cout << "\n\nKitchen test 1 **************************\n\n";
    Kitchen spaceK(false, false, nullptr, nullptr, nullptr, 
            nullptr);

    testPlayer.removeItem(Player::KNIFE);
    testPlayer.setIsDead(false);

    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;

    spaceK.action(&testPlayer);

    std::cout << "testPlayer has knife? " << 
        testPlayer.hasItem(Player::KNIFE) << std::endl;


    std::cout << "\n\nBedroom test 1 **************************\n\n";
    Bedroom spaceB(false, false, nullptr, nullptr, nullptr, 
            nullptr);

    testPlayer.removeItem(Player::HEALTH);
    testPlayer.setIsDead(false);

    std::cout << "testPlayer has health? " << 
        testPlayer.hasItem(Player::HEALTH) << std::endl;

    spaceB.action(&testPlayer);

    std::cout << "testPlayer has health? " << 
        testPlayer.hasItem(Player::HEALTH) << std::endl;


    std::cout << "\n\nAttic test 1 **************************\n\n";
    Attic spaceA(false, false, nullptr, nullptr, nullptr, 
            nullptr);

    testPlayer.removeItem(Player::CURE);
    testPlayer.setIsDead(false);

    std::cout << "testPlayer has the cure? " << 
        testPlayer.hasItem(Player::CURE) << std::endl;

    spaceA.action(&testPlayer);

    std::cout << "testPlayer has the cure? " << 
        testPlayer.hasItem(Player::CURE) << std::endl;


    return 0;
}

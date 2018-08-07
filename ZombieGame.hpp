#ifndef ZOMBIE_GAME_HPP
#define ZOMBIE_GAME_HPP
#include <iostream> 
#include <vector>
#include <string>
#include "Player.hpp"
#include "Space.hpp"
#include "General.hpp"
#include "Kitchen.hpp"
#include "Attic.hpp"
#include "Bedroom.hpp"

class ZombieGame
{
private: 
    Space* m_start;
    Space* m_playerSpace;
    Player m_player;
public:
    ZombieGame();
    ~ZombieGame();
    bool movePlayer();
        
};

#endif

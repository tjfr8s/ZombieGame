#include "General.hpp"

General::General(std::string name,
                  bool hasZombie,
                  bool isLocked,
                  Player::ItemType item,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space(name, hasZombie, isLocked, item, up, down, left, right) 
{
}

void General::action(Player* player)
{
}

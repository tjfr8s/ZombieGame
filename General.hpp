#ifndef GENERAL_HPP
#define GENERAL_HPP
#include "Space.hpp"
#include "Player.hpp"


class General : public Space
{
public:
    
    General(std::string name,
          bool hasZombie,
          bool isLocked,
          Player::ItemType item,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

    virtual ~General(){} 
    virtual void action(Player* player);

};


#endif

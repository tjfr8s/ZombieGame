#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <vector>
#include <string>



class Kitchen : public Space
{
public:
    
    Kitchen(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

    virtual ~Kitchen(){} 
    virtual void action(Player* player);

};


#endif

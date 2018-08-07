#ifndef BEDROOM_HPP
#define BEDROOM_HPP
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <vector>
#include <string>



class Bedroom : public Space
{
public:
    
    Bedroom(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

    virtual ~Bedroom(){} 
    virtual void action(Player* player);

};


#endif

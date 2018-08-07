#ifndef ATTIC_HPP
#define ATTIC_HPP
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <vector>
#include <string>



class Attic : public Space
{
public:
    
    Attic(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

    virtual ~Attic(){} 
    virtual void action(Player* player);

};


#endif

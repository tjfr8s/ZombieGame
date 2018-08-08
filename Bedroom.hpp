/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an Bedroom Space. The Bedroom space 
 * contians the Key, which the player needs to unlock the attic. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
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
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Bedroom" as the value for name and Player::KEY as the value for
 * item.
*******************************************************************************/ 
    Bedroom(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);


/*******************************************************************************
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~Bedroom(){} 


/*******************************************************************************
 * Description: This function allows the player to interact with the Bedroom 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
    virtual void action(Player* player);

};


#endif

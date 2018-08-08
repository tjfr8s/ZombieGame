/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an Attic Space. The Attic space contians 
 * the cure, which the player needs to compelte the game. It has an action 
 * member function for handling player interaction with the room. 
*******************************************************************************/ 
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
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Attic" as the value for name and Player::CURE as the value for
 * item.
*******************************************************************************/ 
    Attic(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

/*******************************************************************************
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~Attic(){} 


/*******************************************************************************
 * Description: This function allows the player to interact with the Attic 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
    virtual void action(Player* player);

};


#endif

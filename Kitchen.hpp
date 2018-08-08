/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an Kitchen Space. A Kitchen space can 
 * contain a knife, which the player can use to fight a zombie. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
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
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Kitchen" as the value for name and Player::KNIFE as the value for
 * item.
*******************************************************************************/ 
    Kitchen(bool hasZombie,
          bool isLocked,
          Space* up,
          Space* down,
          Space* left,
          Space* right);


/*******************************************************************************
 * Description: Virtual desctructor.
*******************************************************************************/ 
    virtual ~Kitchen(){} 


/*******************************************************************************
 * Description: This function allows the player to interact with the Kitchen 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
    virtual void action(Player* player);

};


#endif

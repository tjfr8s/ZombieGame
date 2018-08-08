/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an General Space. A General space can 
 * contain health, which the player can use to heal themselves. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
#ifndef GENERAL_HPP
#define GENERAL_HPP
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"


class General : public Space
{
public:
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, right, name, and item  and passes them to the Space constructor. 
*******************************************************************************/ 
    General(std::string name,
          bool hasZombie,
          bool isLocked,
          Player::ItemType item,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

/*******************************************************************************
 * Description: Virtual desctructor.
*******************************************************************************/ 
    virtual ~General(){} 


/*******************************************************************************
 * Description: This function allows the player to interact with the General 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space (if there is one there).
*******************************************************************************/ 
    virtual void action(Player* player);

};


#endif

/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an Bedroom Space. The Bedroom space 
 * contians the Key, which the player needs to unlock the attic. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
#include "Bedroom.hpp"

/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Bedroom" as the value for name and Player::KEY as the value for
 * item.
*******************************************************************************/ 
Bedroom::Bedroom(bool hasZombie,
                  bool isLocked,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space("Bedroom", hasZombie, isLocked, Player::KEY, up, down, left, right) 
{
}


/*******************************************************************************
 * Description: This function allows the player to interact with the Bedroom 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
void Bedroom::action(Player* player)
{
    int choice(0);
    std::vector<std::string> options;
    options.push_back("Leave");

    while(choice != 1)
    {
        // Add menu options based on status of Bedroom object.
        if(m_item == Player::KEY)
        {
            options.push_back("Pick up key");
        }

        choice = getMenu(options);

        // If the player chooses to leave, do nothing. If they choose
        // to pick up the Key, add it to the player's inventory and remove
        // it from the room.
        switch(choice)
        {
            case 1:
                break;
            case 2:
                player->addItem(Player::KEY);
                m_item = Player::EMPTY;        
                break;
        }
        // Remove all options accept for leave 
        for(int i = 0; i < static_cast<int>(options.size() - 1); i++)
        {
            options.pop_back();
        }
    }

}

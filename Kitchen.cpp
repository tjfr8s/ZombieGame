/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an Kitchen Space. A Kitchen space can 
 * contain a knife, which the player can use to fight a zombie. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
#include "Kitchen.hpp"
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Kitchen" as the value for name and Player::KNIFE as the value for
 * item.
*******************************************************************************/ 
Kitchen::Kitchen(bool hasZombie,
                  bool isLocked,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space("Kitchen", hasZombie, isLocked, Player::KNIFE, up, down, left, right) 
{
}


/*******************************************************************************
 * Description: This function allows the player to interact with the Kitchen 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
void Kitchen::action(Player* player)
{
    int choice(0);
    std::vector<std::string> options;
    options.push_back("Leave");

    while(choice != 1)
    {
        // Add menu options based on status of Kitchen object.
        if(m_item == Player::KNIFE)
        {
            options.push_back("Pick up knife");
        }

        choice = getMenu(options);

        // If the player chooses to leave, do nothing. If they choose
        // to pick up the Knife, add it to the player's inventory and remove
        // it from the room.
        switch(choice)
        {
            case 1:
                break;
            case 2:
                player->addItem(Player::KNIFE);
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

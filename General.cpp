/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This class describes an General Space. A General space can 
 * contain health, which the player can use to heal themselves. It has an 
 * action  member function for handling player interaction with the room. 
*******************************************************************************/ 
#include "General.hpp"
/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, right, name, and item  and passes them to the Space constructor. 
*******************************************************************************/ 
General::General(std::string name,
                  bool hasZombie,
                  bool isLocked,
                  Player::ItemType item,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space(name, hasZombie, isLocked, item, up, down, left, right) 
{
}


/*******************************************************************************
 * Description: This function allows the player to interact with the General 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space (if there is one there).
*******************************************************************************/ 
void General::action(Player* player)
{
    int choice(0);
    std::vector<std::string> options;
    options.push_back("Leave");

    while(choice != 1)
    {
        // Add menu options based on status of Kitchen object.
        if(m_item == Player::HEALTH)
        {
            options.push_back("Pick up health");
        }

        choice = getMenu(options);

        // If the player chooses to leave, do nothing. If they choose
        // to pick up the Health, add it to the player's inventory and remove
        // it from the room.
        switch(choice)
        {
            case 1:
                break;
            case 2:
                player->addHealth(2);
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

#include "Attic.hpp"

/*******************************************************************************
 * Description: This constructor takes arguments for hasZombie, isLocked, up
 * down, left, and right and passes them to the Space constructor. It also
 * passes "Attic" as the value for name and Player::CURE as the value for
 * item.
*******************************************************************************/ 
Attic::Attic(bool hasZombie,
                  bool isLocked,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space("Attic", hasZombie, isLocked, Player::CURE, up, down, left, right) 
{
}


/*******************************************************************************
 * Description: This function allows the player to interact with the Attic 
 * space. It prints a menu that give the player the option of leaving the 
 * Space or picking up the item in the space. 
*******************************************************************************/ 
void Attic::action(Player* player)
{
    int choice(0);
    std::vector<std::string> options;
    options.push_back("Leave");

    while(choice != 1 && !player->hasItem(Player::CURE))
    {
        // Add menu options based on status of Attic object.
        if(m_item == Player::CURE)
        {
            options.push_back("Pick up the cure");
        }

        choice = getMenu(options);

        // If the player chooses to leave, do nothing. If they chose to pick
        // up the cure, add the cure to the player's inventory and remove
        // it from the room.
        switch(choice)
        {
            case 1:
                break;
            case 2:
                player->addItem(Player::CURE);
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

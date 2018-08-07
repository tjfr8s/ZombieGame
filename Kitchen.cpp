#include "Kitchen.hpp"

Kitchen::Kitchen(bool hasZombie,
                  bool isLocked,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space("Kitchen", hasZombie, isLocked, Player::KNIFE, up, down, left, right) 
{
}

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

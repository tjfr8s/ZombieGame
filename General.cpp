#include "General.hpp"

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

        switch(choice)
        {
            case 1:
                break;
            case 2:
                player->addHealth(2);
                break;
        }
        // Remove all options accept for leave 
        for(int i = 0; i < static_cast<int>(options.size() - 1); i++)
        {
            options.pop_back();
        }
    }

}

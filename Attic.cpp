#include "Attic.hpp"

Attic::Attic(bool hasZombie,
                  bool isLocked,
                  Space* up,
                  Space* down,
                  Space* left,
                  Space* right):
    Space("Attic", hasZombie, isLocked, Player::CURE, up, down, left, right) 
{
}

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

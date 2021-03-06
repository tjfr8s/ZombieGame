/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This abstract class describes a generic Space for the zombie
 * game. It has data members for storing its name, its zombie occupation status,
 * an item, and the four surrounding spaces. It has a constructor, virtual
 * destructor, and virtual functions for fighting zombies and interacting
 * with the space.
*******************************************************************************/ 
#include "Space.hpp"
/*******************************************************************************
 * Description: Takes parameters for name, hasZombie, isLocked, item, up, down,
 * left, right and initializes member variables to those values
*******************************************************************************/ 
Space::Space(std::string name,
             bool hasZombie,
             bool isLocked,
             Player::ItemType item,
             Space* up,
             Space* down,
             Space* left,
             Space* right):
    m_name(name),
    m_hasZombie(hasZombie),
    m_isLocked(isLocked),
    m_item(item),
    m_up(up),
    m_down(down),
    m_left(left),
    m_right(right)
{
}

Space::~Space()
{
}

/*******************************************************************************
 * Description: If the player has a knife, they kill the zombie and the knife 
 * breaks. If they don't have a knife, they die.
*******************************************************************************/ 
void Space::fight(Player* player)
{
    if(m_hasZombie && player->hasItem(Player::KNIFE))
    {
        m_hasZombie = false;
        player->removeItem(Player::KNIFE);
    }
    else if(m_hasZombie && !player->hasItem(Player::KNIFE))
    {
        player->die();
    }
}


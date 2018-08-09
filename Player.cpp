/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/07/2018
 * Description: This class describes a Player in the zombie game. The class
 * contains an enum that describest the different items in the game. It has
 * data members for the player's health, their items, and whether they are
 * dead or not. It has member functions for dying, taking damage, adding health
 * adding items, removing items, checking to see if the player has an item,
 * and checking if the player is dead.
*******************************************************************************/ 
#include "Player.hpp"
/*******************************************************************************
 * Description: This constructor takes an integer parameter for health, and
 * initializes the player data members m_health and m_isDead to the passed
 * health value and false respectively.
*******************************************************************************/ 
Player::Player(int health): m_health(health), m_isDead(false)
{
}


Player::~Player()
{
}


/*******************************************************************************
 * Description: Sets m_isDead to true.
*******************************************************************************/ 
void Player::die()
{
    m_isDead = true;
}


/*******************************************************************************
 * Description: Takes an integer parameter called health, and adds that value
 * to m_health
*******************************************************************************/ 
void Player::addHealth(int health)
{
    m_health += health;
}


/*******************************************************************************
 * Description: Decrements the player's m_health member.
*******************************************************************************/ 
void Player::takeDamage()
{
    m_health -= 1;
}


/*******************************************************************************
 * Description: Returns true if the player is dead.
*******************************************************************************/ 
bool Player::isDead()
{
    if(m_health <= 0)
    {
        m_isDead = true;
    }
    return m_isDead;
}


/*******************************************************************************
 * Description: Takes an ItemType parameter and pushes it into the bag vector
*******************************************************************************/ 
void Player::addItem(Player::ItemType item)
{
    m_bag.push_back(item);
}


/*******************************************************************************
 * Description: Takes an item parameter and returns true if the player has
 * that item in their bag.
*******************************************************************************/ 
bool Player::hasItem(Player::ItemType item)
{
    bool hasItem(false);

    auto found = find(m_bag.begin(), m_bag.end(), item);
    if(found != m_bag.end())
    {
        hasItem = true;
    }
    else
    {
        hasItem = false;
    }
    return hasItem;
}


/*******************************************************************************
 * Description: Takes an item parameter and removes it from the bag (if there
 * is one in the bag).
*******************************************************************************/ 
void Player::removeItem(ItemType item)
{
    auto found = find(m_bag.begin(), m_bag.end(), item);
    if(found != m_bag.end())
    {
        m_bag.erase(found);
    }
}


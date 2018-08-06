#include "Player.hpp"
Player::Player(int health): m_health(health), m_isDead(false)
{
}

Player::~Player()
{
}

void Player::die()
{
    m_isDead = true;
}

bool Player::isDead()
{
    return m_isDead;
}

void Player::addItem(Player::ItemType item)
{
    m_bag.push_back(item);
}

bool Player::hasItem(Player::ItemType item)
{
    bool hasItem(false);
    int count = 0;
    while(hasItem == false && count < static_cast<int>(m_bag.size()))
    {
        if(m_bag[count] == item)
        {
            hasItem = true;
        }
        else
        {
            hasItem = false; 
        }
        count++;
    }
    return hasItem;
}

void Player::removeItem(ItemType item)
{}


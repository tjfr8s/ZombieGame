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

void Player::removeItem(ItemType item)
{
    auto found = find(m_bag.begin(), m_bag.end(), item);
    if(found != m_bag.end())
    {
        m_bag.erase(found);
    }
}


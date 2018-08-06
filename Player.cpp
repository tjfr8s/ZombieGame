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

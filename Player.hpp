#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <algorithm>
#include <iostream>

class Player
{
public:
    enum ItemType
    {
        KNIFE,
        KEY,
        HEALTH,
        ANTIDOTE,
        EMPTY
    };

    Player(int health);
    ~Player();
    void die();
    bool isDead();
    void addItem(ItemType item);
    bool hasItem(ItemType item);
    void removeItem(ItemType item);
    void setIsDead(bool isDead){m_isDead = isDead;}
private:
    int m_health;
    std::vector<ItemType> m_bag;
    bool m_isDead;
};

#endif

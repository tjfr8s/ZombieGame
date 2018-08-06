#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
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
private:
    int m_health;
    std::vector<ItemType> m_bag;
    bool m_isDead;
};

#endif

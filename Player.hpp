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
        CURE,
        EMPTY
    };


/*******************************************************************************
 * Description: This constructor takes an integer parameter for health, and
 * initializes the player data members m_health and m_isDead to the passed
 * health value and false respectively.
*******************************************************************************/ 
    Player(int health);


    ~Player();


/*******************************************************************************
 * Description: Sets m_isDead to true.
*******************************************************************************/ 
    void die();


/*******************************************************************************
 * Description: Takes an integer parameter called health, and adds that value
 * to m_health
*******************************************************************************/ 
    void addHealth(int health);


/*******************************************************************************
 * Description: Decrements the player's m_health member.
*******************************************************************************/ 
    void takeDamage();


/*******************************************************************************
 * Description: Takes an ItemType parameter and pushes it into the bag vector
*******************************************************************************/ 
    void addItem(ItemType item);


/*******************************************************************************
 * Description: Returns true if the player is dead.
*******************************************************************************/ 
    bool isDead();


/*******************************************************************************
 * Description: Decrements the player's m_health member.
*******************************************************************************/ 
    int getHealth() {return m_health;}


/*******************************************************************************
 * Description: Takes an item parameter and returns true if the player has
 * that item in their bag.
*******************************************************************************/ 
    bool hasItem(ItemType item);


/*******************************************************************************
 * Description: Takes an item parameter and removes it from the bag (if there
 * is one in the bag).
*******************************************************************************/ 
    void removeItem(ItemType item);


    void setIsDead(bool isDead){m_isDead = isDead;}
private:
    int m_health;
    std::vector<ItemType> m_bag;
    bool m_isDead;
};

#endif

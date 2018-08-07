/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/05/2018
 * Description: This abstract class describes a generic Space for the zombie
 * game. It has data members for storing its name, its zombie occupation status,
 * an item, and the four surrounding spaces. It has a constructor, virtual
 * destructor, and virtual functions for fighting zombies and interacting
 * with the space.
*******************************************************************************/ 
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
#include <algorithm>
#include "Player.hpp"



class Space
{
    std::string m_name;
    bool m_hasZombie;
    bool m_isLocked;
    Player::ItemType m_item;
    Space* m_up;
    Space* m_down;
    Space* m_left;
    Space* m_right;

public:
    Space(std::string name,
          bool hasZombie,
          bool isLocked,
          Player::ItemType item,
          Space* up,
          Space* down,
          Space* left,
          Space* right);

    virtual ~Space();
    virtual void action(Player* player) = 0;
    virtual void fight(Player* player);

    void setUp(Space* up) {m_up = up;}
    void setDown(Space* down) {m_down = down;}
    void setLeft(Space* left) {m_left = left;}
    void setRight(Space* right) {m_right = right;}
    void toggleZombie() {m_hasZombie = !m_hasZombie;}


    Space* getUp() {return m_up;}
    Space* getDown() {return m_down;}
    Space* getLeft() {return m_left;}
    Space* getRight() {return m_right;}
    bool hasZombie() {return m_hasZombie;}







};

#endif

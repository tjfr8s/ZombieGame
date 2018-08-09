/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/07/2018
 * Description: This class descries a ZombieGame. It has a constructor that
 * sets up the board, a destructor that tears it down, and member functions for 
 * playing the game, moving the player and taking a turn.
*******************************************************************************/ 
#ifndef ZOMBIE_GAME_HPP
#define ZOMBIE_GAME_HPP
#include <iostream> 
#include <vector>
#include <string>
#include "Player.hpp"
#include "Space.hpp"
#include "General.hpp"
#include "Kitchen.hpp"
#include "Attic.hpp"
#include "Bedroom.hpp"

class ZombieGame
{
private: 
    Space* m_start;
    Space* m_playerSpace;
    Player m_player;
public:
/*******************************************************************************
 * Description: This constructor creates the game environment by dynamically 
 * allocating spaces and linking them using their Space* data members. 
*******************************************************************************/ 
    ZombieGame();


/*******************************************************************************
 * Description: This destructor is responsible for tearing down the dynamically 
 * allocated game board. It traverses the board using the Space* data members
 * of each space and deallocates each space on the board.
*******************************************************************************/ 
    ~ZombieGame();


/*******************************************************************************
 * Description: This function handles playing the ZombieGame. It prints 
 * instructions for the user and repeatedly letts them take turns until they
 * win or they die.
*******************************************************************************/ 
    void playGame();


/*******************************************************************************
 * Description: This function handles player movement. It builds a menu of
 * movement options based on the links that the player's space has. It then lets
 * the player choose a direction to move. If the door is locked, they player
 * must have a key to access the room.
*******************************************************************************/ 
    void movePlayer();


/*******************************************************************************
 * Description: This function simulates each turn of the game. It prints
 * the player's location, health, and items. If there is a zombie in the space
 * the player is given the option to fight or run. Once any zombies are defeated
 * and the player is in the room, they are given the option to interact with 
 * items in the room, or to leave the room.  
*******************************************************************************/ 
    void takeTurn();

        
};

#endif

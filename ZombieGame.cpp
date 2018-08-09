/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 08/07/2018
 * Description: This class descries a ZombieGame. It has a constructor that
 * sets up the board, a destructor that tears it down, and member functions for 
 * playing the game, moving the player and taking a turn.
*******************************************************************************/ 
#include "ZombieGame.hpp"
/*******************************************************************************
 * Description: This constructor creates the game environment by dynamically 
 * allocating spaces and linking them using their Space* data members. 
*******************************************************************************/ 
 ZombieGame::ZombieGame(): m_playerSpace(nullptr), m_player(7)
{
    m_start = new General("Entrance",
                          false,
                          false,
                          Player::EMPTY,
                          nullptr,
                          nullptr,
                          nullptr,
                          nullptr);
    Space* root = m_start;
    Space* branch(nullptr);
    branch = new General("Foyer",
                          false,
                          false,
                          Player::EMPTY,
                          nullptr,
                          root,
                          nullptr,
                          nullptr);
    root->setUp(branch);

    root = branch;

    branch = new Kitchen(false,
                         false,
                         nullptr,
                         nullptr,
                         nullptr,
                         root);
    root->setLeft(branch);
    branch = new Bedroom(false,
                         false,
                         nullptr,
                         nullptr,
                         root,
                         nullptr);
    root->setRight(branch);
    branch = new General("Stairs",
                          true,
                          false,
                          Player::HEALTH,
                          nullptr,
                          root,
                          nullptr,
                          nullptr);

    root->setUp(branch);
    root = branch;
    branch = new Attic(false,
                      true,
                      nullptr,
                      root,
                      nullptr,
                      nullptr);
    root->setUp(branch);

    m_playerSpace = m_start;
    

   
}


/*******************************************************************************
 * Description: This destructor is responsible for tearing down the dynamically 
 * allocated game board. It traverses the board using the Space* data members
 * of each space and deallocates each space on the board.
*******************************************************************************/ 
ZombieGame::~ZombieGame()
{
    Space* root = m_start->getUp();
    Space* del = m_start;
    delete del;
    del = root->getLeft();
    delete del;
    del = root->getRight();
    delete del;
    del = root;
    root = root->getUp();
    delete del; 
    del = root->getUp();
    delete del;
    delete root;
}


/*******************************************************************************
 * Description: This function handles player movement. It builds a menu of
 * movement options based on the links that the player's space has. It then lets
 * the player choose a direction to move. If the door is locked, they player
 * must have a key to access the room.
*******************************************************************************/ 
void ZombieGame::movePlayer()
{
    // Build menu of movement options.
    std::vector<std::string> options;    
    std::string next;
    if(m_playerSpace->getUp() != nullptr)
    {
        options.push_back(m_playerSpace->getUp()->getName());
    }
    else
    {
        options.push_back("Just a wall here.");
    }
    if(m_playerSpace->getDown() != nullptr)
    {
        options.push_back(m_playerSpace->getDown()->getName());
    }
    else
    {
        options.push_back("Just a wall here.");
    }
    if(m_playerSpace->getLeft() != nullptr)
    {
        options.push_back(m_playerSpace->getLeft()->getName());
    }
    else
    {
        options.push_back("Just a wall here.");
    }
    if(m_playerSpace->getRight() != nullptr)
    {
        options.push_back(m_playerSpace->getRight()->getName());
    }
    else
    {
        options.push_back("Just a wall here.");
    }
    bool moved(false);
    int choice(0);
    
    
    // Get the user's movement choice and execute it.
    while(moved == false && !m_player.hasItem(Player::CURE))
    {
        std::cout << "\nWhere would you like to go? \n";
        choice = getMenu(options);
        
        switch(choice)
        {
            case 1:
                if(m_playerSpace->getUp() != nullptr)
                {
                    if(m_playerSpace->getUp()->isLocked() && !m_player.hasItem(Player::KEY))
                    {
                        std::cout << "The door is locked\n";
                    }
                    else
                    {
                        m_playerSpace = m_playerSpace->getUp();
                        moved = true;
                    }
                }
                break;
            case 2:
                if(m_playerSpace->getDown() != nullptr)
                {
                    if(m_playerSpace->getDown()->isLocked() && !m_player.hasItem(Player::KEY))
                    {
                        std::cout << "The door is locked\n";
                    }
                    else
                    {
                        m_playerSpace = m_playerSpace->getDown();
                        moved = true;
                    }
                }
                break;
            case 3:
                if(m_playerSpace->getLeft() != nullptr)
                {
                    if(m_playerSpace->getLeft()->isLocked() && !m_player.hasItem(Player::KEY))
                    {
                        std::cout << "The door is locked\n";
                    }
                    else
                    {
                        m_playerSpace = m_playerSpace->getLeft();
                        moved = true;
                    }
                }
                break;
            case 4:
                if(m_playerSpace->getRight() != nullptr)
                {
                    if(m_playerSpace->getRight()->isLocked() && !m_player.hasItem(Player::KEY))
                    {
                        std::cout << "The door is locked\n";
                    }
                    else
                    {
                        m_playerSpace = m_playerSpace->getRight();
                        moved = true;
                    }
                }
                break;
        }
    }
    if(!m_player.hasItem(Player::CURE))
    {
        m_player.takeDamage();
    }
}


/*******************************************************************************
 * Description: This function handles playing the ZombieGame. It prints 
 * instructions for the user and repeatedly letts them take turns until they
 * win or they die.
*******************************************************************************/ 
void ZombieGame::playGame()
{
    std::cout << 
        "******************************************************************\n"<<
        "A mansion looms in front of you. A zombie has bitten you \n"
        "and you need the cure, which you know is in the mansion’s \n"
        "attic. Make your way to the attic in order to survive. There may \n"
        "be zombies along the way. Engaging them without the proper equipment\n"
        "means certain death. Your health is low, so you may need a boost\n"
        "to complete the journey.\n" << 
        "******************************************************************\n"<<
        std::endl;
    while(!m_player.isDead() && !m_player.hasItem(Player::CURE))
    {
        takeTurn();
    }

    if(m_player.isDead())
    {
        std::cout << "You died!\n\n";
    }
    else
    {
        std::cout << "You survived! You win!\n\n";
    }
}


/*******************************************************************************
 * Description: This function simulates each turn of the game. It prints
 * the player's location, health, and items. If there is a zombie in the space
 * the player is given the option to fight or run. Once any zombies are defeated
 * and the player is in the room, they are given the option to interact with 
 * items in the room, or to leave the room.  
*******************************************************************************/ 
void ZombieGame::takeTurn()
{
    bool hasRun(false);
    // Display information about the player and their location
    std::cout << "--Location: " << m_playerSpace->getName() << 
        "--" << std::endl;
    std::cout << "Player health: " << m_player.getHealth() << std::endl;
    if(m_player.hasItem(Player::KNIFE))
    {
        std::cout << "The player has a knife\n";
    }
    if(m_player.hasItem(Player::KEY))
    {
        std::cout << "The player has a key\n";
    }

    // Resolve battle if zombie is present.
    if(m_playerSpace->hasZombie())
    {
        std::cout << "There's a Zombie in here!\n";

        std::vector<std::string> options;
        options.push_back("Run");
        options.push_back("Fight");
        int choice = getMenu(options);

        switch(choice)
        {
            case 1:
                std::cout << "You ran away.\n";
                m_playerSpace = m_playerSpace->getDown();
                m_player.takeDamage();
                hasRun = true;
                break;
            case 2:
                m_playerSpace->fight(&m_player);

                if(m_player.isDead())
                {
                    std::cout << "The Zombie killed you!\n";
                }
                else
                {
                    std::cout << "You killed the zombie!\n";
                }
                break;
        }

    }
    else
    {
        std::cout << "This room seems safe...\n";
    } 

    if(!m_player.isDead() && !m_player.hasItem(Player::CURE) && !hasRun)
    {
        m_playerSpace->action(&m_player);
        movePlayer();
    }


}

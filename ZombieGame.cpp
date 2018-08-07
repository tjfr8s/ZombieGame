#include "ZombieGame.hpp"
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


void ZombieGame::movePlayer()
{
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

void ZombieGame::playGame()
{
    while(!m_player.isDead() && !m_player.hasItem(Player::CURE))
    {
        takeTurn();
    }

    if(m_player.isDead())
    {
        std::cout << "You died!\n";
    }
    else
    {
        std::cout << "You survived\n";
    }
}


void ZombieGame::takeTurn()
{
    if(m_playerSpace->getUp() != nullptr)
    {
        std::cout << m_playerSpace->getUp()->isLocked() << std::endl;
    }
    std::cout << "Player health: " << m_player.getHealth() << std::endl;
    if(m_player.hasItem(Player::KNIFE))
    {
        std::cout << "The player has a knife\n";
    }
    if(m_player.hasItem(Player::KEY))
    {
        std::cout << "The player has a key\n";
    }
    if(m_playerSpace->hasZombie())
    {
        std::cout << "There's a Zombie in here!\n";
        m_playerSpace->fight(&m_player);

        if(m_player.isDead())
        {
            std::cout << "The Zombie killed you!\n";
        }
        else
        {
            std::cout << "You killed the zombie!\n";
        }
    }
    else
    {
        std::cout << "This room seems safe...\n";
    } 

    if(!m_player.isDead() && !m_player.hasItem(Player::CURE))
    {
        m_playerSpace->action(&m_player);
        movePlayer();
    }


}

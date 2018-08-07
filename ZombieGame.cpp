#include "ZombieGame.hpp"
 ZombieGame::ZombieGame(): m_playerSpace(nullptr), m_player(5)
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
                          Player::KEY,
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


bool ZombieGame::movePlayer()
{
    std::vector<std::string> options;    
    std::string next;
    if(m_playerSpace->getUp() != nullptr)
    {
        options.push_back(m_playerSpace->getUp()->getName());
    }
    if(m_playerSpace->getDown() != nullptr)
    {
        options.push_back(m_playerSpace->getDown()->getName());
    }
    if(m_playerSpace->getLeft() != nullptr)
    {
        options.push_back(m_playerSpace->getLeft()->getName());
    }
    if(m_playerSpace->getRight() != nullptr)
    {
        options.push_back(m_playerSpace->getRight()->getName());
    }
    int choice = getMenu(options);
    switch(choice)
    {
        case 1:
            m_playerSpace = m_playerSpace->getUp();
            break;
        case 2:
            m_playerSpace = m_playerSpace->getDown();
            break;
        case 3:
            m_playerSpace = m_playerSpace->getLeft();
            break;
        case 4:
            m_playerSpace = m_playerSpace->getRight();
            break;
    }

    return true;
}

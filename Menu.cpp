#include "Menu.hpp"
/************************************************************
 * Author: Tyler Freitas
 * Date: 07/01/2018
 * Description: This file contains a function for printing a
 * menu and getting a selection from the user and a function
 * for controlling the execution of a program using a menu.
************************************************************/


/************************************************************
 * Description:
 * Preconditions:
 *      Call function.
 * Postconditions:
 *      A menu is printed to the console.
 *      The user's choice is read into a variale and returned.
************************************************************/
int getMenu(std::vector<std::string> options)
{
    std::cout << "Choose an option:\n";

    for(int i = 0; i < static_cast<int>(options.size()); i++)
    {
        std::cout << i+1 << ". " << options[i] << std::endl;
    }
    
    int userChoice = intInputValidation(1, options.size());

    return userChoice;
}




/************************************************************
 * Description: This function gets an integer from the user
 * and returns its value. It validates the integer and
 * requests the user enter a different value if they didn't
 * enter an integer.
 * 
 * Preconditions:
 *      - user enters an integer value.
 * Postconditions:
 *      - validated integer value is returned.
 ************************************************************/
#include "IntegerValidation.hpp"


int intInputValidation(int min, int max)
{
    int userInput(0);
    while(!(std::cin >> userInput) || 
            std::cin.peek() != '\n' ||
            userInput < min ||
            userInput > max)
    {
        std::cout << "That is not a valid integer" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an integer between: " << 
            min << " and " << max << std::endl;
    }
    return userInput;
}



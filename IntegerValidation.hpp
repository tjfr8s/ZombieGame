#ifndef INTEGERVALIDATION_HPP
#define INTEGERVALIDATION_HPP
#include <limits>
#include <iostream>

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
int intInputValidation(int min, int max);
#endif

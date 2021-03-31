#include <iostream>
#include "ScrabbleClass.h"
const int MAX = 2048;
int main()
{
    // Creating the ScrabbleClass object, where you play the game
    ScrabbleClass *object = new ScrabbleClass();
    // Creating a variable where to save input data
    char *input;
    while (true)
    {
        // Save space for the input
        input = new char[MAX];
        std::cout << "$ ";
        // Read input from cin
        std::cin.getline(input, MAX, '\n');
        // Show response message
        std::cout << object->decide(input) << std::endl;
        // Free space
        delete[] input;
    }
    // Unnecesary delete
    delete object;
    return 0;
}
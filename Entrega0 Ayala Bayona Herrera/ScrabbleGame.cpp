#include <iostream>
#include "ScrabbleClass.h"
using namespace std;
int main()
{
    // Creating the Scrabble object, where you play the game
    Scrabble *object = new Scrabble;
    // Creating a variable where to save input data
    string input;
    while (true)
    {
        // Save space for the input
        cout << "$ ";

        // Read input from cin
        getline(cin, input, '\n');

        // Show response message
        cout << decide(object, (char*)input.c_str()) << endl;
    }
    return 0;
}
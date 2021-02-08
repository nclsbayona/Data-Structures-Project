#include <bits/stdc++.h>
#include "ScrabbleClass.h"
const int MAX = 150;
using namespace std;
int main()
{
    Scrabble *object = new Scrabble;
    char *input;
    while (true)
    {
        input = new char[MAX];
        cout << "$ ";
        cin.getline(input, MAX, '\n');
        if (!strcmp(input,"salir"))
            return 0;
        cout<<decide(object, input);
        delete[] input;
    }
    return 0;
}
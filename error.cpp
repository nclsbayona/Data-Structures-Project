/*#include <iostream>
#include <fstream>
#include <list>
#include "Palabra.h"
int main()
{
    std::ifstream file;
    std::list<std::string> list;
    file.open("prueba1.txt", std::ios::in);
      if (file.is_open())
        {
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                // Palabra pala(line, 1);
                list.push_back(line);
            }
        }
    return 0;
}*/
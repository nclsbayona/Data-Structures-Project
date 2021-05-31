#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "Palabra.h"
#include <list>
class Diccionario
{
private:
    // Stores the words in a dictionary
    std::list<Palabra> lista_palabras;
    // The file name
    std::string file_name;

public:
    // Default constructor
    Diccionario();
    // Imprimir diccionario
    std::string to_string();
    // Set file_name
    void setFile_name(std::string archive_name);
    //Adds a new word to the list
    void add_word(Palabra word);
    // Checks if an specific word exists in the dictionary
    bool checkWord(std::string word);
    //Clears the word list
    void clear();
    //Checks if the word list is empty
    int size();
    //Return lista_palabras
    std::list<Palabra> getList();
    //Sort
    void sort();
    //Return the file name
    std::string getFile_name();
    //Returns a list with all words that have the specified preffix in the dictionary
    std::list<std::string> wordsByPrefix(std::string prefix);
    //Returns a list with all words that have the specified suffix in the dictionary
    std::list<std::string> wordsBySuffix(std::string suffix);
};
#endif
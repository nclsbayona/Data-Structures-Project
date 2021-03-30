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
    //Checks if words are equal
    static bool compare(Palabra first, Palabra second);
    //Checks if words for order
    static bool order(Palabra first, Palabra second);
public:
    // Default constructor
    Diccionario();
    // Imprimir diccionario
    std::string to_string();
    // Set file_name
    void setFile_name(std::string archive_name);
    //Adds a new word to the list
    void add_word(Palabra word);
    // Makes sure, all words are only 1 time
    void make_unique();
    // Checks if an specific word exists in the dictionary
    bool checkWord(std::string word);
    //Clears the word list
    void clear();
    //Checks if the word list is empty
    int size();
    //Return the file name
    std::string getFile_name();
};


#endif
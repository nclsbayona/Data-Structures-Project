#ifndef DATASTRUCTURESPROJECT
#define DATASTRUCTURESPROJECT
#include <string>
#include <cstring>
#include "Diccionario.h"
#include <fstream>
#include "TreeClass.h"
#include "GraphClass.h"
class ScrabbleClass
{
private:
    int sumScore(std::string word);
    bool find_in_dictionaries(std::string word);
    Diccionario dictionary;
    Diccionario inverse_dictionary;
    TreeClass tree;
    GraphClass graph;

public:
    Diccionario getDictionary();
    Diccionario getInverse_dictionary();
    std::string help(void);
    std::string help(std::string command);
    std::string start(std::string archive_name);
    std::string inverse_start(std::string archive_name);
    std::string score(std::string word);
    void exit();
    std::string start_tree(std::string archive_name);
    std::string start_inverse_tree(std::string archive_name);
    std::string words_by_prefix(std::string prefix);
    std::string words_by_suffix(std::string suffix);
    std::string word_graph();
    std::string possible_words(std::string characters);
    std::string decide(std::string input);
};
#endif
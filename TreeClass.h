#ifndef TREECLASS_H
#define TREECLASS_H
#include "Palabra.h"
#include <set>
#include <map>
#include <iostream>
class TreeClass
{
private:
    std::map<char, std::set<std::string>> words;
    std::string file_name;

public:
    TreeClass();
    std::string printMap();
    std::map<char, std::set<std::string>> getTree();
    void addWord(char, std::string);
    std::string getFile_name();
    void setFile_name(std::string);
    void setTree(std::map<char, std::set<std::string>> pal);
    //Returns a set with all words that have the specified preffix in the dictionary
    std::set<std::string> wordsByPrefix(std::string prefix);
    //Returns a set with all words that have the specified suffix in the dictionary
    std::set<std::string> wordsBySuffix(std::string suffix);
};
#endif
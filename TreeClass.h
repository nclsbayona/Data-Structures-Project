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
};
#endif
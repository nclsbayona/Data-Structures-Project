#include "TreeClass.h"
void TreeClass::printMap()
{
    std::cout << "Printing..." << std::endl;
    std::map<char, std::set<std::string>>::iterator it = this->words.begin();
    std::set<std::string>::iterator it2;
    for (; it != this->words.end(); ++it)
    {
        std::cout << it->first << " - ";
        it2 = it->second.begin();
        for (; it2 != it->second.end(); ++it2)
            std::cout << *it2 << ",";
        std::cout << std::endl;
    }
}
TreeClass::TreeClass()
{
    this->file_name = " ";
    for (int i = 65; i <= 89; ++i)
        words[i];
    for (int i = 97; i <= 122; ++i)
        words[i];
}
std::map<char, std::set<std::string>> TreeClass::getTree()
{
    return this->words;
}
void TreeClass::setTree(std::map<char, std::set<std::string>> pal)
{
    this->words = pal;
}
void TreeClass::setFile_name(std::string name)
{
    this->file_name = name;
}
std::string TreeClass::getFile_name()
{
    return this->file_name;
}
void TreeClass::addWord(char key, std::string value)
{
    std::map<char, std::set<std::string>>::iterator it = this->words.begin();
    for (; it != this->words.end(); it++)
    {
        if (it->first == key)
        {
            it->second.insert(value);
        }
    }
}
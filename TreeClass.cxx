#include "TreeClass.h"
std::string TreeClass::printMap()
{
    std::string ret="Printing...\n";
    std::map<char, std::set<std::string>>::iterator it = this->words.begin();
    std::set<std::string>::iterator it2;
    int tam;
    for (; it != this->words.end(); ++it)
    {
        tam=it->second.size();
        if (tam==0)
            continue;
        ret+= it->first;
        ret+= " - ";
        it2 = it->second.begin();
        for (; it2 != it->second.end(); ++it2){
            ret+=(*it2);
            tam-=1;
            //If there's one more, add ','
            if (tam>0)
                ret+=",";
        }
        ret+='\n';
    }
    return ret;
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
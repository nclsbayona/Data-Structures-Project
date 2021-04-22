#include "NodoClass.h"

NodoClass::NodoClass(char data, bool end)
{
    this->data = data;
    this->end = end;
}
char NodoClass::getData()
{
    return this->data;
}
NodoClass *NodoClass::addChild(char child_data, bool end)
{
    NodoClass *child = new NodoClass(child_data, end);
    this->children.push_back(child);
    return child;
}
void NodoClass::setEnd(bool possible)
{
    this->end = possible;
}
std::vector<NodoClass *> NodoClass::getChildren()
{
    return this->children;
}
NodoClass *NodoClass::childExists(char data)
{
    NodoClass *exists = NULL;
    for (std::vector<NodoClass *>::iterator it = this->children.begin(); it != this->children.end() && !exists; ++it)
    {
        if ((*it)->data == data)
            exists = (*it);
    }
    return exists;
}
bool NodoClass::isEnd()
{
    //In case a word is end and also parent to other (Example: AVE AVESTRUZ, SAL SALADO)
    return this->end;
}

std::string NodoClass::print(int level)
{
    std::string ch = "";
    std::vector<NodoClass *> c = this->getChildren();
    std::string tab = "";
    for (int i = 0; i < level; ++i)
        tab += "\t";
    ch += tab + " --> " + this->getData() + "\n";
    if (!c.size())
        return ch;
    std::vector<NodoClass *>::iterator it;
    for (it = c.begin(); it != c.end(); it++)
    {
        ch += ((*it)->print(level + 1));
    }
    return ch;
}

std::vector<std::string> NodoClass::childWords(std::string before, std::vector<std::string> &palabras)
{
    before += this->data;
    if (this->isEnd())
        palabras.push_back(before);
    if (!this->children.empty())
    {
        typedef std::vector<NodoClass *> vectorNodos;
        vectorNodos::iterator it = this->children.begin();
        for (; it != this->children.end(); ++it)
        {
            (*it)->childWords(before, palabras);
        }
    }
    return palabras;
}
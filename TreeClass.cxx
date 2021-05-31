#include "TreeClass.h"
TreeClass::TreeClass(char head_data, bool end)
{
    //In case word is a single character
    this->head = new NodoClass(head_data, end);
}

NodoClass *TreeClass::getHead()
{
    return this->head;
}

bool TreeClass::addChild(std::string data)
{
    bool ret = false;
    if (!this->wordEnd(data))
    {
        bool end;
        NodoClass *node = this->head;
        if (node->getData() == data[0])
        {
            ret = true;
            int size = data.size();
            for (int i = 1; i < size; ++i)
            {
                if (node->childExists(data[i]))
                {
                    node = node->childExists(data[i]);
                }
                else
                {
                    //Decide if it's or not end at the moment
                    end = (i < size - 1) ? 0 : 1;
                    node = node->addChild(data[i], end);
                }
            }
        }
    }
    else
        ret = true;
    return ret;
}

std::string TreeClass::printTree()
{
    if (this->head)
        return "Tree\n" + this->head->print() + "\n";
    else
        return "Tree\n";
}

std::vector<std::string> TreeClass::wordsByPrefix(std::string prefix)
{
    int tam = prefix.size();
    std::vector<std::string> words;
    bool end = false;
    NodoClass *nodo = this->head;
    if (nodo->getData() == prefix[0])
    {
        //Prefix might go in this tree
        for (int i = 1; i < tam && !end; ++i)
        {
            nodo = nodo->childExists(prefix[i]);
            if (!nodo)
                end = true;
        }
        //I know that if it hasn't finished, it's because the prefix exists, therefore, I have to addWords
        if (!end)
            nodo->childWords(prefix.substr(0, tam - 1), words);
    }
    return words;
}

std::vector<std::string> TreeClass::wordsBySuffix(std::string suffix)
{
    int tam = suffix.size();
    std::vector<std::string> words;
    bool end = false;
    //Reverse suffix
    std::string copy = suffix;
    for (int i = 0; i < tam; ++i)
        suffix[i] = copy[tam - 1 - i];
    //
    NodoClass *nodo = this->head;
    if (nodo->getData() == suffix[0])
    {
        //Suffix might go in this tree
        for (int i = 1; i < tam && !end; ++i)
        {
            nodo = nodo->childExists(suffix[i]);
            if (!nodo)
                end = true;
        }
        //I know that if it hasn't finished, it's because the suffix exists, therefore, I have to addWords
        if (!end)
            nodo->childWords(suffix.substr(0, tam - 1), words);
    }
    return words;
}

bool TreeClass::wordEnd(std::string word)
{
    //Iterate through tree looking for word
    //If word exists, end=true
    NodoClass *node = this->head;
    bool possible = true;
    int i = 0;
    std::string acum = "";
    if (node && node->getData() == word[i])
    {
        acum += node->getData();
        while (acum != word && possible)
        {
            node = node->childExists(word[++i]);
            if (node == NULL)
                possible = false;
            else
                acum += node->getData();
        }
        if (possible && !node->isEnd())
            node->setEnd(true);
    }
    return possible;
}
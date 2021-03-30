#include "Diccionario.h"
#include <fstream>
#include <cstring>
bool Diccionario::checkWord(std::string word)
{
    std::list<Palabra>::iterator it = this->lista_palabras.begin();
    for (; it != this->lista_palabras.end(); it++)
    {
        if ((*it).getWord() == word)
            return true;
    }
    return false;
}
bool Diccionario::compare(Palabra first, Palabra second)
{
    return !strcmp((char*)first.getWord().c_str(), (char*)second.getWord().c_str());
}
bool Diccionario::order(Palabra first, Palabra second)
{
    return strcmp((char*)first.getWord().c_str(), (char*)second.getWord().c_str())<0;
}
void Diccionario::make_unique()
{
    this->lista_palabras.sort(Diccionario::order);
    this->lista_palabras.unique(Diccionario::compare);
}
std::string Diccionario::to_string()
{
    std::string retorno;
    std::list<Palabra>::iterator it = this->lista_palabras.begin();
    for (; it != this->lista_palabras.end(); it++)
        retorno += (*it).getWord() + "\n";
    return retorno;
}
Diccionario::Diccionario()
{
    this->file_name = "";
}
void Diccionario::clear()
{
    this->lista_palabras.clear();
}
int Diccionario::size()
{
    return !this->lista_palabras.empty();
}
std::string Diccionario::getFile_name()
{
    return this->file_name;
}
void Diccionario::add_word(Palabra word)
{
    this->lista_palabras.push_back(word);
}
void Diccionario::setFile_name(std::string archive_name)
{
    this->file_name = archive_name;
}
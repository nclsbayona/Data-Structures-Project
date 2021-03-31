#include "Diccionario.h"
#include <fstream>
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
    this->file_name = file_name;
}
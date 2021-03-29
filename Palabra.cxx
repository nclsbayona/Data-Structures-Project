#include "Palabra.h"
// Returns true if all characters of a word are alphabetic characters
bool Palabra::check_character(std::string line)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (!((line[i]>64 && line[i]<92)||(line[i]>96 && line[i]<123)))
            return false;
    }
    return true;
}
//Returs a word in inverse order
std::string Palabra::inverse_characters(std::string line)
{
    std::string retorno;
    for (int i = line.size() - 1; i >= 0; i--)
    {
        retorno += line[i];
    }
    return retorno;
}
Palabra::Palabra(std::string word, bool order)
{
    if (this->check_character(word))
        this->word = (order) ? word : this->inverse_characters(word);
}
std::string Palabra::getWord()
{
    return this->word;
}
std::string Palabra::invertOrder()
{
    return this->inverse_characters(this->word);
}
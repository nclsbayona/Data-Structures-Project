#include "Palabra.h"
// Returns true if all characters of a word are alphabetic characters
bool Palabra::check_character(std::string line)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (!((line[i] > 64 && line[i] < 92) || (line[i] > 96 && line[i] < 123)))
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
bool Palabra::prefixInWord(std::string prefix)
{
    int size = prefix.size();
    if (word.size() < size)
        return false;
    for (int i = 0; i < size; ++i)
    {
        if (this->word[i] != prefix[i])
            return false;
    }
    return true;
}
bool Palabra::suffixInWord(std::string suffix)
{
    int size = suffix.size(), word_size = this->word.size();
    if (word_size < size)
        return false;
    for (int i = word_size - size, j = 0; i < word_size && j < size; ++i, ++j)
    {
        if (this->word[i] != suffix[j])
            return false;
    }
    return true;
}
std::string Palabra::to_string()
{
    return "Palabra: " + this->word + "longitud " + std::to_string(this->word.size()) + '\n';
}
bool Palabra::operator==(const Palabra &p)
{
    return this->word==((Palabra)(p)).getWord();
}
 bool Palabra::operator<(const Palabra &p)
{
    return this->word<((Palabra)(p)).getWord();
}
bool Palabra::oneCharacterDifference(Palabra &p)
{
    bool retorno = false;
    
    return retorno;
}
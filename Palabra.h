#ifndef PALABRA_H
#define PALABRA_H
#include <string>
#include <cstring>
class Palabra
{
private:
    // Word
    std::string word;
    // Checks if word has no invalid characters
    bool check_character(std::string line);
    // Returns word passed by argument in inverse order
    std::string inverse_characters(std::string line);

public:
    // Initializes word 1 normal order, 0 inverse order
    Palabra(std::string word, bool order);
    std::string getWord();
    std::string invertOrder();
    bool oneCharacterDifference(Palabra &p);
    bool suffixInWord(std::string suffix);
    bool prefixInWord(std::string prefix);
    std::string to_string();
    bool operator==(const Palabra &p);
    bool operator<(const Palabra &p);
};
#endif
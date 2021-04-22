#include "NodoClass.h"
class TreeClass{
    private:
        NodoClass* head;
    public:
        TreeClass (char head_data, bool end);
        bool addChild(std::string data);
        NodoClass* getHead();
        std::string printTree();
        std::vector<std::string> wordsByPrefix(std::string prefix);
        std::vector<std::string> wordsBySuffix(std::string suffix);
        bool wordEnd(std::string word);
};
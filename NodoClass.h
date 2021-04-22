#include <vector>
#include <string>
class NodoClass{
    private:
        char data;
        bool end;
        std::vector<NodoClass*> children;
    public:
        NodoClass(char data, bool end);
        char getData();
        NodoClass* addChild(char child, bool end);
        NodoClass* childExists(char data);
        std::vector<NodoClass*> getChildren();
        bool isEnd();
        std::string print(int level=0);
        std::vector<std::string> childWords(std::string before, std::vector<std::string>& palabras);
        void setEnd(bool possible);
};
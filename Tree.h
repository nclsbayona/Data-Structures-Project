#include "TreeClass.h"

class Tree
{
private:
    std::string file_name;
    std::vector<TreeClass *> trees;

public:
    TreeClass *treeExists(char data);
    TreeClass *addTree(char data, bool end = false);
    void addDataToTree(std::string data);
    std::string getFile_name();
    void setFile_name(std::string file_name);
    std::string printTree();
    std::vector<std::string> wordsByPrefix(std::string prefix);
    std::vector<std::string> wordsBySuffix(std::string suffix);
};
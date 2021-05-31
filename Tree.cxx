#include "Tree.h"

std::string Tree::getFile_name()
{
    return this->file_name;
}

void Tree::setFile_name(std::string file_name)
{
    this->file_name = file_name;
}

std::vector<std::string> Tree::wordsByPrefix(std::string prefix)
{
    TreeClass *tree = this->treeExists(prefix[0]);
    std::vector<std::string> words;
    if (tree != NULL)
        words = tree->wordsByPrefix(prefix);
    return words;
}

std::string Tree::printTree()
{
    std::string retorno = "";
    std::vector<TreeClass *>::iterator it = this->trees.begin();
    for (; it != this->trees.end(); ++it)
    {
        retorno += (*it)->printTree();
        retorno += "\n\n";
    }
    return retorno;
}

std::vector<std::string> Tree::wordsBySuffix(std::string suffix)
{
    TreeClass *tree = this->treeExists(suffix[suffix.size() - 1]);
    std::vector<std::string> words;
    if (tree != NULL)
        words = tree->wordsBySuffix(suffix);
    return words;
}

TreeClass *Tree::treeExists(char data)
{
    TreeClass *exists = NULL;
    std::vector<TreeClass *>::iterator it = this->trees.begin();
    for (; it != this->trees.end() && !exists; ++it)
    {
        if ((*it)->getHead()->getData() == data)
            exists = (*it);
    }
    return exists;
}

TreeClass *Tree::addTree(char data, bool end)
{
    TreeClass *tree = new TreeClass(data, end);
    this->trees.push_back(tree);
    return tree;
}

void Tree::addDataToTree(std::string data)
{
    TreeClass *tree = this->treeExists(data[0]);
    if (tree == NULL)
        tree = this->addTree(data[0]);
    tree->addChild(data);
}
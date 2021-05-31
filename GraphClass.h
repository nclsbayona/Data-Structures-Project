#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include <string>
#include <vector>
#include <map>
class GraphClass
{
private:
    bool dirigido;
    std::vector<std::string> values;
    std::map<int, std::map<int, int>> vertices_aristas;

public:
    std::string printGraph();
    GraphClass(bool dirigido=0);
    bool agregarArista(std::string start, std::string end, char value_startend, char value2_endstart);
    bool agregarVertice(std::string start);
    bool buscarVertice(std::string start);
    int indexOf(std::string start);
};
#endif
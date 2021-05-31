#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H
#include "Palabra.h"
#include <vector>
#include <map>
class GraphClass
{
private:
bool dirigido;
        std::vector<Palabra> values;
        std::map<int,std::map<int, char>> vertices_aristas;
public:
    std::string printGraph();
    GraphClass(bool dirigido);
    bool agregarArista(Palabra start, Palabra end, char value, int directed);
    bool agregarVertice(Palabra start);
    bool buscarVertice(Palabra start);
    int indexOf(Palabra start);
};
#endif
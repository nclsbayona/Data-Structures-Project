#include "GraphClass.h"
#include <algorithm>

GraphClass::GraphClass(bool dirigido)
{
    this->dirigido = dirigido;
}

std::string GraphClass::printGraph()
{
    std::string printing = "\nPeso 0 implica que no tiene peso, una lista vacía significa que es un nodo isla o un nodo sumidero\n\n";
    typedef std::map<int, int> W;
    typename std::map<int, W>::iterator it_vertices = this->vertices_aristas.begin();
    typename W::iterator it_aristas;
    printing += "{\n\t[";
    for (; it_vertices != this->vertices_aristas.end(); it_vertices++)
    {
        printing += "\n\t\t{\n\t\t\t" + this->values[it_vertices->first] + ":\n";
        printing += "\t\t\t[\n";
        for (it_aristas = it_vertices->second.begin(); it_aristas != it_vertices->second.end(); it_aristas++)
        {
            printing += "\t\t\t\t" + this->values[it_aristas->first] + ": [";
            printing += " ";
            printing += std::to_string(it_aristas->second);
            printing += " ]\n";
        }
        printing += "\t\t\t]\n\t\t}\n";
    }
    printing += "\t]\n}\n\n";
    return printing;
}

//Vertice

bool GraphClass::agregarVertice(std::string start)
{
    bool done = false;
    if (!this->buscarVertice(start))
    {
        this->values.push_back(start);

        this->vertices_aristas[this->indexOf(start)];
        done = true;
    }
    return done;
}

bool GraphClass::buscarVertice(std::string start)
{
    return std::find(this->values.begin(), this->values.end(), start) != this->values.end();
}

int GraphClass::indexOf(std::string start)
{
    int val = -1;
    if (this->buscarVertice(start))
        val = std::find(this->values.begin(), this->values.end(), start) - this->values.begin();
    return val;
}

//Aristas
bool GraphClass::agregarArista(std::string start, std::string end, char value_startend, char value2_endstart)
{
    bool valid = 0;
    try
    {
        if (!this->buscarVertice(start))
            this->agregarVertice(start);
        if (!this->buscarVertice(end))
            this->agregarVertice(end);
        this->vertices_aristas[this->indexOf(end)][this->indexOf(start)] = (value2_endstart);
        this->vertices_aristas[this->indexOf(start)][this->indexOf(end)] = (value_startend);
        valid = 1;
    }
    catch (...)
    {
        valid = 0;
    }
    return valid;
}

std::vector<std::string> GraphClass::possibleWords(std::string pattern)
{
    std::vector<std::string> retorno;
    bool valido = true;
    const char caracter_comodin='?';
    int patSize = pattern.size();
    int pos=-1;
    for (std::vector<std::string>::iterator it = this->values.begin(); it != this->values.end() && retorno.empty() && valido; ++it)
    {
        //Verificar aquí que cumpla con el patron que llega como parámetro
        if (patSize == it->size())
        {
            for (int i = 0; i < patSize && valido; ++i)
            {
                if (pattern[i]==caracter_comodin)
                    pos=i;
                else if (pattern[i] != caracter_comodin && pattern[i] != (*it)[i])
                    valido = false;
            }
            if (valido)
            {
                retorno.push_back(*it);
                if (pos!=-1)
                    for (std::map<int, int>::iterator it_arista=this->vertices_aristas[this->indexOf(*it)].begin();it_arista!=this->vertices_aristas[this->indexOf(*it)].end(); ++it_arista){
                        if (it_arista->second==pos)
                            retorno.push_back(this->values[it_arista->first]);
                    }
            }
            valido = true;
        }
        else if (patSize < it->size())
            valido = false;
    }
    return retorno;
}

void GraphClass::clearGraph()
{
    this->values.clear();
    this->vertices_aristas.clear();
}

bool GraphClass::dataOnIt()
{
    return !this->values.empty();
}
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include "ScrabbleClass.h"
using namespace std;

// Function that shows all available functions
std::string ScrabbleClass::help()
{
    std::string cmd;
    cmd = "- inicializar\n- iniciar_inverso\n- puntaje\n- salir\n- iniciar_arbol\n- iniciar_arbol_inverso\n- palabras_por_prefijo\n- palabras_por_sufijo\n- grafo_de_palabras\n- posibles_palabras\n ";
    return cmd;
}

// Function that shows each available command information
std::string ScrabbleClass::help(std::string command)
{
    std::string cmd_help;
    if (command == "inicializar")
        cmd_help = "NOMBRE\ninicializar\nSINOPSIS\ninicializar [NOMBRE_ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo cuyo nombre es pasado como parámetro a la funcion (Ejemplo: inicializar diccionario.txt), que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego). El comando almacena las palabras del archivo de forma que sea fácil recuperarlas posteriormente. Las palabras deben ser verificadas para no almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación)\nMENSAJES DE SALIDA\n(Diccionario ya inicializado) El diccionario ya ha sido inicializado.(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El diccionario se ha inicializado correctamente.\n\n";

    else if (command == "iniciar_inverso")
        cmd_help = "NOMBRE\niniciar_inverso\nSINOPSIS\niniciar_inverso [NOMBRE_ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de\npalabras aceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar,\neste comando almacena las palabras en sentido inverso (leídas de derecha a izquierda), teniendo en cuenta\nque sea fácil recuperarlas posteriormente. Las palabras también deben ser verificadas para no almacenar\naquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación\nMENSAJES DE SALIDA\n(Diccionario ya inicializado) El diccionario inverso ya ha sido inicializado.\n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El diccionario inverso se ha inicializado correctamente.\n\n";

    else if (command == "puntaje")
        cmd_help = "NOMBRE\npuntaje\nSINOPSIS\npuntaje [PALABRA]\nDESCRIPCION\nEl comando permite conocer la puntuación que puede obtenerse con una palabra dada de acuerdo a la tabla de puntuación de cada letra presentada anteriormente. Sin embargo, el comando debe verificar que la palabra sea válida, es decir, que exista en el diccionario (tanto original como en sentido inverso)\n, y que esté escrita con símbolos válidos.\n\n";

    else if (command == "salir")
        cmd_help = "NOMBRE\nsalir\nSINOPSIS\nsalir\nDESCRIPCION\nTermina la ejecución de la aplicación.\n\n";

    else if (command == "iniciar_arbol")
        cmd_help = "NOMBRE\niniciar_arbol\nSINOPSIS\niniciar_arbol [NOMBRE ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras\naceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar, este comando almacena\nlas palabras en uno o más árboles de letras (como se considere conveniente). Las palabras deben ser verificadas para\nno almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación).\nMENSAJES DE SALIDA:\n(Árbol ya  inicializado)  El  árbol  del  diccionario  ya  ha  sido  inicializado. \n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente.\n\n";

    else if (command == "iniciar_arbol_inverso")
        cmd_help = "NOMBRE\niniciar_arbol_inverso\nSINOPSIS\niniciar_arbol_inverso [NOMBRE ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de pala-\nbras aceptadas en el idioma inglés (idioma original del juego). A diferencia de los comandos iniciar_inverso\ne iniciar_arbol, este comando almacena las palabras en uno o más árboles de letras, pero en sentido inverso \n(leídas de derecha a izquierda). Las palabras también deben ser verificadas para no almacenar aquellas\nque incluyen símbolos inválidos (como guiones, números y signos de puntuación).\nMENSAJES DE SALIDA\n(Árbol ya inicializado) El árbol del diccionario inverso ya ha sido inicializado.\n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El árbol del diccionario inverso se ha inicializado correctamente.\n\n";

    else if (command == "palabras_por_prefijo")
        cmd_help = "NOMBRE\npalabras_por_prefijo\nSINOPSIS\npalabras_por_prefijo [PALABRA]\nDESCRIPCION\nDado un prefijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el \ncomando iniciar_arbol) para ubicar todas las palabras posibles a construir a partir de ese prefijo. A partir del \nrecorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuación \nque cada una puede obtener.\nMENSAJES DE SALIDA\n(Prefijo inválido) Prefijo prefijo no pudo encontrarse en el diccionario.\n(Resultado exitoso) Las palabras que inician con este prefijo son:\n\n";

    else if (command == "palabras_por_sufijo")
        cmd_help = "NOMBRE\npalabras_por_sufijo\nSINOPSIS\npalabras_por_sufijo [PALABRA]\nDESCRIPCION\nDado un sufijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el\ncomando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan con ese sufijo.\nA partir del recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y\nla puntuación que cada una puede obtener.\nMENSAJES DE SALIDA\n(Sufijo inválido) Sufijo sufijo no pudo encontrarse en el diccionario.\n(Resultado exitoso) Las palabras que terminan con este sufijo son:\n\n";
    else if (command == "grafo_de_palabras")
        cmd_help = "NOMBRE\ngrafo_de_palabras\nSINOPSIS\ngrafo_de_palabras []\nDESCRIPCION\nCon las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde \ncada palabra se conecta a las demás si y sólo sí difieren en un única letra (con las demás letras iguales y en las \nmismas posiciones).\nMENSAJES DE SALIDA\n(Resultado exitoso) Grafo construído correctamente.\n\n";

    else if (command == "posibles_palabras")
        cmd_help = "NOMBRE\nposibles_palabras\nSINOPSIS\nposibles_palabras [LETRAS]\nDESCRIPCION\nDadas ciertas letras en una cadena de caracteres (sin importar su orden), el comando debe presentar en pantalla todas las posibles palabras válidas a construir, indicando la longitud de cada una y la puntuación que se puede obtener con cada una. En las letras de la cadena de caracteres, puede admitirse un único símbolo comodín (?), el cual representará una letra desconocida y permitirá generar mayores posibilidades de palabras a construir. Para este propósito, el comando debe hacer uso del grafo de palabras construído con el comando grafo_de_palabras\nMENSAJES DE SALIDA\n(Letras inválidas) La cadena letras contiene símbolos inválidos.\n(Resultado exitoso) Las posibles palabras a construir con las letras letras son:\n\n";

    else
        cmd_help = "No existe el comando especificado\n\n";

    return cmd_help;
}

//Returns a word in only lower_case
std::string ScrabbleClass::wordToLower(std::string word)
{
    for (int i = 0; i < word.size(); i++)
        word[i] = tolower(word[i]);
    return word;
}
//Reads a file in txt format and load the words in a list to initialize the dictionary
std::string ScrabbleClass::start(std::string archive_name)
{
    int m = 0;
    if (this->dictionary.size())
        this->dictionary.clear();
    std::ifstream file;
    std::string retorno;
    if (strcmp((char *)archive_name.c_str(), (char *)this->dictionary.getFile_name().c_str()))
    {
        file.open(archive_name, std::ios::in);
        if (file.is_open())
        {
            this->dictionary.setFile_name(archive_name);
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                Palabra word(line, 1);
                if (word.getWord() != "")
                    this->dictionary.add_word(word);
                else if (m == 0)
                {

                    retorno += "No se agrego una(s) palabra ya que contiene caracteres invalido(s) o esta vacia\n";
                    m++;
                }
            }
            retorno += "El diccionario se ha inicializado correctamente";
        }
        else if (!file.is_open())
        {
            retorno += "El archivo ";
            retorno += archive_name;
            retorno += "No existe o no puede ser leido";
        }
    }
    else
        retorno += "El diccionario ya ha sido inicializado\n";
    this->dictionary.sort();
    return retorno;
}

//Reads a file in format txt and loads the words in a list to initialize the inverse dictionary
std::string ScrabbleClass::inverse_start(std::string archive_name)
{
    int m = 0;
    if (!this->inverse_dictionary.size())
        this->inverse_dictionary.clear();
    std::ifstream file;
    std::string retorno;
    if (strcmp((char *)archive_name.c_str(), (char *)this->inverse_dictionary.getFile_name().c_str()))
    {
        file.open(archive_name, std::ios::in);
        if (file.is_open())
        {
            this->inverse_dictionary.setFile_name(archive_name);
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                Palabra word(line, 0);
                if (word.getWord() != "")
                    this->inverse_dictionary.add_word(word);
                else if (m == 0)
                {
                    retorno += "No se agrego una palabra ya que contiene caracteres invalido(s) o esta vacia\n";
                    m++;
                }
            }
            retorno += "El diccionario invertido se ha inicializado correctamente";
        }
        else if (!file.is_open())
        {
            retorno += "El archivo ";
            retorno += archive_name;
            retorno += " no existe o no puede ser leido";
        }
    }
    else
        retorno += "El diccionario invertido ya ha sido inicializado\n";
    this->inverse_dictionary.sort();
    return retorno;
}

// Returns score of a word in char* format
std::string ScrabbleClass::score(std::string word)
{
    std::string palabra, retorno;
    palabra = word;
    std::string retorn;

    if (this->find_in_dictionaries(word))
    {
        retorno = "La palabra tiene un puntaje de " + std::to_string(this->sumScore(word));
        retorn += retorno;
        return retorn;
    }
    retorn = "La palabra ";
    retorn += retorno;
    retorn += " no existe en el diccionario\n";
    return retorn;
}
//Returns true if the word is in the list
bool ScrabbleClass::find_in_dictionaries(std::string word)
{
    Palabra pal(word, 1);
    if (this->dictionary.checkWord(pal.getWord()) && this->inverse_dictionary.checkWord(pal.invertOrder()))
        return true;
    if (this->dictionary.checkWord(pal.invertOrder()) && this->inverse_dictionary.checkWord(pal.getWord()))
        return true;
    return false;
}
//Returns a word's punctuation
int ScrabbleClass::sumScore(std::string word)
{
    int score = 0;
    for (int i = 0; i < word.size(); i++)
    {
        switch (std::toupper(word[i]))
        {
        case 'E':
        case 'A':
        case 'I':
        case 'O':
        case 'N':
        case 'R':
        case 'T':
        case 'L':
        case 'S':
        case 'U':
            score++;
            break;
        case 'D':
        case 'G':
            score += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            score += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            score += 4;
            break;
        case 'K':
            score += 5;
            break;
        case 'J':
        case 'X':
            score += 8;
            break;
        case 'Q':
        case 'Z':
            score += 10;
            break;

        default:
            break;
        }
    }

    return score;
}
void ScrabbleClass::exit()
{
    // Exit command that ends execution
    std::exit(0);
}
std::string ScrabbleClass::start_tree(std::string file_name)
{
    ifstream file;
    std::string retorno;
    file.open(file_name, std::ios::in);
    bool flag = false;

    if (file_name != this->tree.getFile_name())
    {
        if (file.is_open())
        {
            this->tree.setFile_name(file_name);
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                Palabra word(line, 1);
                std::string tmp = word.getWord();
                if (word.getWord() != "")
                    this->tree.addDataToTree(this->wordToLower(tmp));
                else
                    flag = true;
            }
            if (!flag)
                retorno += "Se ha inicializado correctamente el arbol";
            else
                retorno += "No se agrego una(s) palabra(s) ya que contiene caracteres invalido(s) o esta vacia\nEl arbol se ha inicializado correctamente";
        }
        else if (!file.is_open())
        {
            retorno += "El archivo ";
            retorno += file_name;
            retorno += " no existe o no puede ser leido";
        }
    }
    else
        retorno += "El arbol ya ha sido inicializado con el mismo nombre\n";
    return retorno;
}
std::string ScrabbleClass::start_inverse_tree(std::string file_name)
{
    ifstream file;
    std::string retorno;
    file.open(file_name, std::ios::in);
    bool flag = false;
    if (file_name != this->inverse_tree.getFile_name())
    {
        if (file.is_open())
        {
            this->inverse_tree.setFile_name(file_name);
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                //Normal order
                Palabra word(line, 0);
                std::string tmp = word.getWord();
                if (word.getWord() != "")
                    this->inverse_tree.addDataToTree(this->wordToLower(tmp));
                else
                    flag = true;
            }
            if (!flag)
                retorno += "Se ha inicializado correctamente el arbol";
            else
                retorno += "No se agrego una(s) palabra(s) ya que contiene caracteres invalido(s) o esta vacia\nEl arbol se ha inicializado correctamente";
        }
        else if (!file.is_open())
        {
            retorno += "El archivo ";
            retorno += file_name;
            retorno += " no existe o no puede ser leido";
        }
    }
    else
        retorno += "El arbol inverso ya ha sido inicializado con el mismo nombre\n";
    return retorno;
}
std::string ScrabbleClass::possible_words(std::string letras)
{
    std::string retorno = this->help("palabras_posibles");
    return retorno;
}

std::string ScrabbleClass::word_graph()
{
    std::string retorno = "Grafo inicializado correctamente";
    try
    {
        std::set<std::pair<int, std::string>> setPairs;
        std::list<Palabra>::iterator it;
        std::list<Palabra> lista = this->dictionary.getList();
        for (it = lista.begin(); it != lista.end(); it++)
            setPairs.insert(std::make_pair(it->getWord().size(), it->getWord()));
        /* To print the set, uncomment 
        for (std::set<std::pair<int,std::string>>::iterator it=setPairs.begin();it!=setPairs.end(); ++it)
            std::cout<<std::to_string(it->first)<<" "<<it->second<<'\n';
        */
        std::set<std::pair<int, std::string>>::iterator it_max_size;
        int maxSize = -1, difference;
        char valorstartend, valorendstart;
        for (std::set<std::pair<int, std::string>>::iterator it = setPairs.begin(); it != setPairs.end(); ++it)
        {
            if (maxSize < it->first - 1)
            {
                maxSize = it->first;
                it_max_size = it;
            }
            else
            {
                for (std::set<std::pair<int, std::string>>::iterator it2 = it_max_size; it2 != it; it2++)
                {
                    difference = abs(it2->first - it->first);
                    if (difference == 1)
                    {
                        if (it2->first > it->first)
                            valorendstart=valorstartend = it->first;
                        else
                            valorstartend=valorendstart = it2->first;
                    }
                    //std::cout<<"Here\n";
                    for (int i = 0; i < it2->first && i < it->first && difference < 2; ++i)
                        if (it2->second[i] != it->second[i])
                        {
                            valorstartend = i;
                            valorendstart = i;
                            difference += 1;
                        }
                    if (difference == 1)
                    {
                        this->graph.agregarArista(it2->second, it->second, valorstartend, valorendstart);
                    }
                }
            }
        }
    }
    catch (...)
    {
        retorno = "Ha ocurrido un error, intentelo de nuevo";
    }
    return retorno;
}

Tree ScrabbleClass::getTree()
{
    return this->tree;
}
Tree ScrabbleClass::getInverseTree()
{
    return this->inverse_tree;
}
Diccionario ScrabbleClass::getInverse_dictionary()
{
    return this->inverse_dictionary;
}

Diccionario ScrabbleClass::getDictionary()
{
    return this->dictionary;
}

std::string ScrabbleClass::words_by_prefix(std::string prefix)
{
    std::string retorno = "Prefijo " + prefix + " no pudo encontrarse en el diccionario (arbol).";
    typedef std::vector<std::string> vector;
    vector my_set = this->tree.wordsByPrefix(prefix);
    int tam = my_set.size();
    if (tam > 0)
    {
        vector::iterator it = my_set.begin();
        retorno = "Las palabras que inician con este prefijo " + prefix + " son:\n";
        for (; it != my_set.end(); ++it)
        {
            retorno += (*it);
            retorno += (" longitud: ");
            retorno += std::to_string((*it).size());
            retorno += (" puntaje: ");
            retorno += std::to_string(this->sumScore(*it));
            if (--tam > 0)
                retorno += ',';
            retorno += '\n';
        }
    }
    return retorno;
}

std::string ScrabbleClass::words_by_suffix(std::string suffix)
{
    std::string retorno = "Sufijo " + suffix + " no pudo encontrarse en el diccionario (arbol).";
    typedef std::vector<std::string> vector;
    vector my_vec = this->inverse_tree.wordsBySuffix(suffix);
    std::string copy;
    int tam = my_vec.size(), tam2;
    if (tam > 0)
    {
        vector::iterator it = my_vec.begin();
        retorno = "Las palabras que terminan con este sufijo " + suffix + " son:\n";
        for (; it != my_vec.end(); ++it)
        {
            //Reverse word
            copy = "";
            tam2 = (*it).size();
            for (int i = 0; i < tam2; ++i)
                copy += (*it)[tam2 - 1 - i];
            //retorno += copy;
            // If you want it reversed, comment the next line and uncomment the above block
            retorno += (*it);
            retorno += (" longitud: ");
            retorno += std::to_string(tam2);
            retorno += (" puntaje: ");
            retorno += std::to_string(this->sumScore(*it));
            if (--tam > 0)
                if (--tam > 0)
                    retorno += ',';
            retorno += '\n';
        }
    }
    return retorno;
}
// Function to decide which command to execute
std::string ScrabbleClass::decide(std::string input)
{
    // Initializes return message
    std::string retorno;
    retorno = "Comando invalido\n\n";

    // Compares input with a value and returns its corresponding message
    if (input == "ayuda")
        retorno = this->help();
    // Compares input with a value and returns its corresponding message
    else if (input == "salir")
        this->exit();
    // Compares input with a value and returns its corresponding message
    else if (input == "grafo_de_palabras")
        retorno = this->word_graph();
    // Compares input with a value and returns its corresponding message
    else if (input == "imprimir_diccionario")
        retorno = this->getDictionary().to_string();
    // Compares input with a value and returns its corresponding message
    else if (input == "imprimir_diccionario_inverso")
        retorno = this->getInverse_dictionary().to_string();
    // Compares input with a value and returns its corresponding message
    else if (input == "imprimir_arbol")
        retorno = this->tree.printTree();
    // Compares input with a value and returns its corresponding message
    else if (input == "imprimir_arbol_inverso")
        retorno = this->inverse_tree.printTree();
    // Compares input with a value and returns its corresponding message
    else if (input == "imprimir_grafo")
        retorno = this->graph.printGraph();
    else if (input.size() >= 7)
    {
        int k = 0;
        std::string *words = new std::string[2];
        char *token;
        token = strtok((char *)input.c_str(), " ");
        while (token != NULL && k < 2)
        {
            words[k++] = token;
            token = strtok(NULL, " ");
        }
        if (k == 2)
        {
            if (words[0] == "ayuda")
                retorno = this->help(words[1]);
            else if (words[0] == "posibles_palabras")
                retorno = this->possible_words(words[1]);
            else if (words[0] == "inicializar")
                retorno = this->start(words[1]);
            else if (words[0] == "iniciar_inverso")
                retorno = this->inverse_start(words[1]);
            else if (words[0] == "puntaje")
                retorno = this->score(words[1]);
            else if (words[0] == "iniciar_arbol")
                retorno = this->start_tree(words[1]);
            else if (words[0] == "iniciar_arbol_inverso")
                retorno = this->start_inverse_tree(words[1]);
            else if (words[0] == "palabras_por_prefijo")
                retorno = this->words_by_prefix(words[1]);
            else if (words[0] == "palabras_por_sufijo")
                retorno = this->words_by_suffix(words[1]);
            else if (words[0] == "posibles_palabras")
                retorno = this->possible_words(words[1]);
        }
    }
    return retorno;
}

#include <cstdlib>
#include <ctype.h>
#include "ScrabbleClass.h"
#define MAXBUFFER 2048
using namespace std;

// Function that shows all available functions
char *ScrabbleClass::help()
{
    char *cmd = new char[MAXBUFFER];
    strcpy(cmd, "- inicializar\n- iniciar_inverso\n- puntaje\n- salir\n- iniciar_arbol\n- iniciar_arbol_inverso\n- palabras_por_prefijo\n- palabras_por_sufijo\n- grafo_de_palabras\n- posibles_palabras\n ");

    return cmd;
}

// Function that shows each available command information
char *ScrabbleClass::help(char *command)
{
    char *cmd_help = new char[MAXBUFFER];
    if (!strcmp(command, "inicializar"))
        strcpy(cmd_help, "NOMBRE\ninicializar\nSINOPSIS\ninicializar [NOMBRE_ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo cuyo nombre es pasado como parámetro a la funcion (Ejemplo: inicializar diccionario.txt), que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego). El comando almacena las palabras del archivo de forma que sea fácil recuperarlas posteriormente. Las palabras deben ser verificadas para no almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación)\nMENSAJES DE SALIDA\n(Diccionario ya inicializado) El diccionario ya ha sido inicializado.(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El diccionario se ha inicializado correctamente.\n\n");

    else if (!strcmp(command, "iniciar_inverso"))
        strcpy(cmd_help, "NOMBRE\niniciar_inverso\nSINOPSIS\niniciar_inverso [NOMBRE_ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de\npalabras aceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar,\neste comando almacena las palabras en sentido inverso (leídas de derecha a izquierda), teniendo en cuenta\nque sea fácil recuperarlas posteriormente. Las palabras también deben ser verificadas para no almacenar\naquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación\nMENSAJES DE SALIDA\n(Diccionario ya inicializado) El diccionario inverso ya ha sido inicializado.\n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El diccionario inverso se ha inicializado correctamente.\n\n");

    else if (!strcmp(command, "puntaje"))
        strcpy(cmd_help, "NOMBRE\npuntaje\nSINOPSIS\npuntaje [PALABRA]\nDESCRIPCION\nEl comando permite conocer la puntuación que puede obtenerse con una palabra dada de acuerdo a la tabla de puntuación de cada letra presentada anteriormente. Sin embargo, el comando debe verificar que la palabra sea válida, es decir, que exista en el diccionario (tanto original como en sentido inverso)\n, y que esté escrita con símbolos válidos.\n\n");

    else if (!strcmp(command, "salir"))
        strcpy(cmd_help, "NOMBRE\nsalir\nSINOPSIS\nsalir\nDESCRIPCION\nTermina la ejecución de la aplicación.\n\n");

    else if (!strcmp(command, "iniciar_arbol"))
        strcpy(cmd_help, "NOMBRE\niniciar_arbol\nSINOPSIS\niniciar_arbol [NOMBRE ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras\naceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar, este comando almacena\nlas palabras en uno o más árboles de letras (como se considere conveniente). Las palabras deben ser verificadas para\nno almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación).\nMENSAJES DE SALIDA:\n(Árbol ya  inicializado)  El  árbol  del  diccionario  ya  ha  sido  inicializado. \n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente.\n\n");

    else if (!strcmp(command, "iniciar_arbol_inverso"))
        strcpy(cmd_help, "NOMBRE\niniciar_arbol_inverso\nSINOPSIS\niniciar_arbol_inverso [NOMBRE ARCHIVO]\nDESCRIPCION\nInicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de pala-\nbras aceptadas en el idioma inglés (idioma original del juego). A diferencia de los comandos iniciar_inverso\ne iniciar_arbol, este comando almacena las palabras en uno o más árboles de letras, pero en sentido inverso \n(leídas de derecha a izquierda). Las palabras también deben ser verificadas para no almacenar aquellas\nque incluyen símbolos inválidos (como guiones, números y signos de puntuación).\nMENSAJES DE SALIDA\n(Árbol ya inicializado) El árbol del diccionario inverso ya ha sido inicializado.\n(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.\n(Resultado exitoso) El árbol del diccionario inverso se ha inicializado correctamente.\n\n");

    else if (!strcmp(command, "palabras_por_prefijo"))
        strcpy(cmd_help, "NOMBRE\npalabras_por_prefijo\nSINOPSIS\npalabras_por_prefijo [PALABRA]\nDESCRIPCION\nDado un prefijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el \ncomando iniciar_arbol) para ubicar todas las palabras posibles a construir a partir de ese prefijo. A partir del \nrecorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuación \nque cada una puede obtener.\nMENSAJES DE SALIDA\n(Prefijo inválido) Prefijo prefijo no pudo encontrarse en el diccionario.\n(Resultado exitoso) Las palabras que inician con este prefijo son:\n\n");

    else if (!strcmp(command, "palabras_por_sufijo"))
        strcpy(cmd_help, "NOMBRE\npalabras_por_sufijo\nSINOPSIS\npalabras_por_sufijo [PALABRA]\nDESCRIPCION\nDado un sufijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el\ncomando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan con ese sufijo.\nA partir del recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y\nla puntuación que cada una puede obtener.\nMENSAJES DE SALIDA\n(Sufijo inválido) Sufijo sufijo no pudo encontrarse en el diccionario.\n(Resultado exitoso) Las palabras que terminan con este sufijo son:\n\n");

    else if (!strcmp(command, "grafo_de_palabras"))
        strcpy(cmd_help, "NOMBRE\ngrafo_de_palabras\nSINOPSIS\ngrafo_de_palabras []\nDESCRIPCION\nCon las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde \ncada palabra se conecta a las demás si y sólo sí difieren en un única letra (con las demás letras iguales y en las \nmismas posiciones).\nMENSAJES DE SALIDA\n(Resultado exitoso) Grafo construído correctamente.\n\n");

    else if (!strcmp(command, "posibles_palabras"))
        strcpy(cmd_help, "NOMBRE\nposibles_palabras\nSINOPSIS\nposibles_palabras [LETRAS]\nDESCRIPCION\nDadas ciertas letras en una cadena de caracteres (sin importar su orden), el comando debe presentar en pantalla todas las posibles palabras válidas a construir, indicando la longitud de cada una y la puntuación que se puede obtener con cada una. En las letras de la cadena de caracteres, puede admitirse un único símbolo comodín (?), el cual representará una letra desconocida y permitirá generar mayores posibilidades de palabras a construir. Para este propósito, el comando debe hacer uso del grafo de palabras construído con el comando grafo_de_palabras\nMENSAJES DE SALIDA\n(Letras inválidas) La cadena letras contiene símbolos inválidos.\n(Resultado exitoso) Las posibles palabras a construir con las letras letras son:\n\n");

    else
        strcpy(cmd_help, "No existe el comando especificado\n\n");

    return cmd_help;
}

//Reada a file in txt format and load the words in a list to initialize the dictionary
char *ScrabbleClass::start(char *archive_name)
{
    std::ifstream file;
    char *retorno = new char[MAXBUFFER];
    memset(retorno, 0, sizeof(retorno));
    if (archive_name != this->file_name)
    {
        file.open(archive_name, std::ios::in);
        if (file.is_open())
        {
            this->dictionary.clear();
            this->file_name = archive_name;
            std::string line;
            while (!file.eof())
            {
                getline(file, line);
                if (this->check_character(line))
                    this->dictionary.push_back(line);
            }
            strcat(retorno, "El diccionario se ha inicializado correctamente");
        }
        else if (!file.is_open())
        {
            strcat(retorno, "El archivo ");
            strcat(retorno, archive_name);
            strcat(retorno, " no existe o no puede ser leido");
        }
    }
    else
        strcpy(retorno, "El diccionario ya ha sido inicializado\n");
    return retorno;
}

// Returns true if all characters of a word are alphabetic characters
bool ScrabbleClass::check_character(std::string line)
{
    char *txt = new char[strlen(line.c_str())];
    strcpy(txt, line.c_str());
    for (int i = 0; i < strlen(txt); i++)
    {
        if (!std::isalpha(txt[i]))
            return false;
    }
    return true;
}

// Returns word passed by argument in inverse order
std::string ScrabbleClass::inverse_characters(std::string line)
{
    std::string retorno;
    for (int i = strlen(line.c_str()) - 1; i >= 0; i--)
    {
        retorno += line[i];
    }
    return retorno;
}

//Reads a file in format txt and loads the words in a list to initialize the inverse dictionary
char *ScrabbleClass::inverse_start(char *archive_name)
{
    std::ifstream file;
    char *retorno = new char[MAXBUFFER];
    memset(retorno, 0, sizeof(retorno));
        file.open(archive_name, std::ios::in);
    if (file.is_open())
    {
        this->inverse_dictionary.clear();
        std::string line;
        while (!file.eof())
        {
            getline(file, line);
            if (this->check_character(line))
            {
                std::string inversedLine = this->inverse_characters(line);
                this->inverse_dictionary.push_back(inversedLine);
            }
        }
        strcat(retorno, "El diccionario invertido se ha inicializado correctamente");
    }
    else if (!file.is_open())
    {
        strcat(retorno, "El archivo ");
        strcat(retorno, archive_name);
        strcat(retorno, " no existe o no puede ser leido");
    }
    else
        strcpy(retorno, "El diccionario invertido ya ha sido inicializado\n");
    return retorno;
}

// Returns score of a word in char* format
char *ScrabbleClass::score(char *word)
{
    std::string palabra, retorno;
    palabra.assign(word);
    char *retorn = new char[MAXBUFFER];

    if (this->find_in_dictionaries(word, this->dictionary) && this->find_in_dictionaries(this->inverse_characters(word), this->inverse_dictionary))
    {
        retorno = "La palabra tiene un puntaje de " + std::to_string(sumScore(word));
        strcpy(retorn, retorno.c_str());
        return retorn;
    }
    retorno = "La palabra no existe en el diccionario\n";
    strcpy(retorn, retorno.c_str());
    return retorn;
}

//Returns true if the word is in the list
bool ScrabbleClass::find_in_dictionaries(std::string word, std::list<std::string> list)
{
    std::list<std::string>::iterator listI;
    for (listI = list.begin(); listI != list.end(); listI++)
    {
        if (*listI == word)
        {
            return true;
        }
    }
    return false;
}

//Returns a word's punctuation
int ScrabbleClass::sumScore(char *word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
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

char *ScrabbleClass::start_tree(char *archive_name)
{
    char *retorno = this->help("iniciar_arbol");
    return retorno;
}

char *ScrabbleClass::possible_words(char *letras)
{
    char *retorno = this->help("palabras_posibles");
    return retorno;
}

char *ScrabbleClass::words_by_suffix(char *suffix)
{
    char *retorno = this->help("palabras_posibles");
    return retorno;
}

char *ScrabbleClass::word_graph()
{
    char *retorno = this->help("grafo_de_palabras");
    return retorno;
}

char *ScrabbleClass::start_inverse_tree(char *archive_name)
{
    char *retorno = this->help("iniciar_arbol_inverso");
    return retorno;
}

char *ScrabbleClass::words_by_prefix(char *prefix)
{
    char *retorno = this->help("palabras_por_prefijo");
    return retorno;
}

// Function to decide which command to execute
char *decide(ScrabbleClass *obj, char *input)
{
    // Initializes return message
    char *retorno = new char[19];
    strcpy(retorno, "Comando invalido\n\n");

    // Compares input with a value and returns its corresponding message
    if (!strcmp(input, "ayuda"))
    {
        delete[] retorno;
        retorno = obj->help();
    }

    // Compares input with a value and returns its corresponding message
    else if (!strcmp(input, "salir"))
    {
        obj->exit();
    }

    // Compares input with a value and returns its corresponding message
    else if (!strcmp(input, "grafo_de_palabras"))
    {
        delete[] retorno;
        retorno = obj->word_graph();
    }

    else if (strlen(input) >= 7)
    {
        //Implementation of this part with char**
        char *token;
        int k = 0;
        char **words = new char *[2];
        token = strtok(input, " ");
        while (token != NULL && k < 2)
        {
            words[k] = new char[strlen(token) + 1];
            strcpy(words[k++], token);
            token = strtok(NULL, " ");
        }

        if (k == 2)
        {
            if ((!strcmp(words[0], "ayuda")))
            {
                delete[] retorno;
                retorno = obj->help(words[1]);
            }

            else if (!strcmp(words[0], "posibles_palabras"))
            {
                delete[] retorno;
                retorno = obj->possible_words(words[1]);
            }

            else if (!strcmp(words[0], "inicializar"))
            {
                delete[] retorno;
                retorno = obj->start(words[1]);
            }

            else if (!strcmp(words[0], "iniciar_inverso"))
            {
                delete[] retorno;
                retorno = obj->inverse_start(words[1]);
            }

            else if (!strcmp(words[0], "puntaje"))
            {
                delete[] retorno;
                retorno = obj->score(words[1]);
            }

            else if (!strcmp(words[0], "iniciar_arbol"))
            {
                delete[] retorno;
                retorno = obj->start_tree(words[1]);
            }

            else if (!strcmp(words[0], "iniciar_arbol_inverso"))
            {
                delete[] retorno;
                retorno = obj->start_inverse_tree(words[1]);
            }

            else if (!strcmp(words[0], "palabras_por_prefijo"))
            {
                delete[] retorno;
                retorno = obj->words_by_prefix(words[1]);
            }

            else if (!strcmp(words[0], "palabras_por_sufijo"))
            {
                delete[] retorno;
                retorno = obj->words_by_suffix(words[1]);
            }

            else if (!strcmp(words[0], "possibles_palabras"))
            {
                delete[] retorno;
                retorno = obj->possible_words(words[1]);
            }
        }

        for (int i = 0; i < k; ++i)
        {
            delete[] words[i];
        }
        delete words;
    }
    return retorno;
}

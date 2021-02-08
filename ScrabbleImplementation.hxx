#include <iostream>
#include <string.h>
#include "ScrabbleClass.h"
#define MAXBUFFER 1024
using namespace std;
char *decide(Scrabble *obj, char *input)
{
    char *retorno;
    strcpy(retorno, "Comando invalido");
    if (!strcmp(input, "ayuda"))
    {
        return obj->help();
    }
    else if (strlen(input) >= 7)
    {
        char *token;
        int k = 0;
        std::string *words = new std::string[2];
        token = strtok(input, " ");
        while (token != NULL && k < 2)
        {
            words[k] = token;
            k++;
            token = strtok(NULL, " ");
        }
        strcpy(retorno, obj->help((char*)words[1].c_str()));
    }
    return retorno;
}

char *Scrabble::help()
{
    char *cmd = new char[MAXBUFFER];
    strcpy(cmd, "- inicializar\n- iniciar_inverso\n- puntaje\n- salir\n- iniciar_arbol\n- iniciar_arbol_inverso\n- palabras_por_prefijo\n- palabras_por_sufijo\n- grafo_de_palabras\n- posibles_palabras\n ");

    return cmd;
}

char *Scrabble::help(char *command)
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
        strcpy(cmd_help, "No existe\n\n");

    return cmd_help;
}
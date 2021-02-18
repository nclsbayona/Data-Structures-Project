#ifndef DATASTRUCTURESPROJECT
#define DATASTRUCTURESPROJECT
//Codigo relevante
/*
Lista de Comandos:

comando: inicializar diccionario.txt
posibles salidas en pantalla:
(Diccionario ya inicializado) El diccionario ya ha sido inicializado.
(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.
(Resultado exitoso) El diccionario se ha inicializado correctamente.
descripción: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras
aceptadas en el idioma inglés (idioma original del juego). El comando debe almacenar las palabras del archivo de forma
que sea fácil recuperarlas posteriormente. Las palabras deben ser verificadas para no almacenar aquellas que 
incluyen símbolos inválidos (como guiones, números y signos de puntuación).

comando: iniciar_inverso diccionario.txt
posibles salidas en pantalla:
(Diccionario ya inicializado) El diccionario inverso ya ha sido inicializado.
(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.
(Resultado exitoso) El diccionario inverso se ha inicializado correctamente.
descripción: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de
palabras aceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar,
este comando almacena las palabras en sentido inverso (leídas de derecha a izquierda), teniendo en cuenta
que sea fácil recuperarlas posteriormente. Las palabras también deben ser verificadas para no almacenar
aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación).

comando:  puntaje  palabra
posibles salidas en  pantalla:
(Palabra no existe) La palabra no existe en el diccionario.
(Letras inválidas) La palabra contiene símbolos inválidos.
(Resultado exitoso) La palabra tiene un puntaje de puntaje .
descripción: El comando permite conocer la puntuación que puede obtenerse con una palabra dada, de
acuerdo a la tabla de puntuación de cada letra presentada anteriormente. Sin embargo, el comando debe verificar que
la palabra sea válida, es decir, que exista en el diccionario (tanto original como en sentido inverso), y que esté 
escrita con símbolos válidos.

comando: salir
posibles salidas en pantalla:
(No tiene salida por pantalla)
descripción: Termina la ejecución de la aplicación.

comando: iniciar_arbol diccionario.txt
posibles salidas en pantalla:
(Árbol ya  inicializado)  El  árbol  del  diccionario  ya  ha  sido  inicializado. 
(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.
(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente.
descripción: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras
aceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar, este comando almacena
las palabras en uno o más árboles de letras (como se considere conveniente). Las palabras deben ser verificadas para
no almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación).

comando: iniciar_arbol_inverso diccionario.txt
posibles salidas en pantalla:
(Árbol ya inicializado) El árbol del diccionario inverso ya ha sido inicializado.
(Archivo no existe) El archivo diccionario.txt no existe o no puede ser leído.
(Resultado exitoso) El árbol del diccionario inverso se ha inicializado correctamente.
descripción: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de pala-
bras aceptadas en el idioma inglés (idioma original del juego). A diferencia de los comandos iniciar_inverso
e iniciar_arbol, este comando almacena las palabras en uno o más árboles de letras, pero en sentido inverso 
(leídas de derecha a izquierda). Las palabras también deben ser verificadas para no almacenar aquellas
que incluyen símbolos inválidos (como guiones, números y signos de puntuación).

comando: palabras_por_prefijo prefijo
salida en pantalla:
(Prefijo inválido) Prefijo prefijo no pudo encontrarse en el diccionario.
(Resultado exitoso) Las palabras que inician con este prefijo son:
descripción: Dado un prefijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el 
comando iniciar_arbol) para ubicar todas las palabras posibles a construir a partir de ese prefijo. A partir del 
recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuación 
que cada una puede obtener.

comando: palabras_por_sufijo sufijo
salida en pantalla:
(Sufijo inválido) Sufijo sufijo no pudo encontrarse en el diccionario.
(Resultado exitoso) Las palabras que terminan con este sufijo son:
descripción: Dado un sufijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el
comando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan con ese sufijo.
A partir del recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y
la puntuación que cada una puede obtener.

comando: grafo_de_palabras
salida en pantalla:
(Resultado exitoso) Grafo construído correctamente.
descripción: Con las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde 
cada palabra se conecta a las demás si y sólo sí difieren en un única letra (con las demás letras iguales y en las 
mismas posiciones).

comando: posibles_palabras letras
salida en pantalla:
(Letras inválidas) La cadena letras contiene símbolos inválidos.
(Resultado  exitoso)  Las  posibles  palabras  a  construir  con  las   letras   letras son: descripción: Dadas ciertas letras en una cadena de caracteres (sin importar su orden), el comando debe presentar en pantalla todas las posibles palabras válidas a construir, indicando la longitud de cada una y la puntuación que se puede obtener con cada una. En las letras de la cadena de caracteres, puede admitirse un único símbolo comodín (?), el cual representará una letra desconocida y permitirá generar mayores posibilidades de palabras a construir. Para este propósito, el comando debe hacer uso del grafo de palabras construído con el comando grafo_de_palabras.
*/
class Scrabble
{
    //RECORDAR
    // ayuda -> help
    // inicializar -> start
    // iniciar_inverso -> inverse_start
    // puntaje -> score
    // salir -> exit
    // iniciar_arbol -> start_tree
    // iniciar_arbol_inverso -> start_inverse_tree
    // palabras_por_prefijo -> words_by_prefix
    // palabras_por_sufijo -> words_by_suffix
    // grafo_de_palabras -> word_graph
    // posibles_palabras -> possible_words
    
    public:
        char* help(void);
        char* help(char *command);
        char* start(char* archive_name);
        char* inverse_start(char* archive_name);
        char* score(char* word);
        void exit();
        char* start_tree(char* archive_name);
        char* start_inverse_tree(char* archive_name);
        char* words_by_prefix(char* prefix);
        char* words_by_suffix(char* suffix);
        char* word_graph();
        char* possible_words(char* characters);
};
char *decide(Scrabble *obj, string input);
#include "ScrabbleImplementation.hxx"
#endif
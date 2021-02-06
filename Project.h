#ifndef PROJECT
#define PROJECT
class ScrabbleGame{
    private:

    protected:

    private:
        //First
        char* start(char* file);
        char* inverse_start(char* file);
        char* score(char* word);
        int exit();
        //Second
        char* tree_start(char* file);
        char* inverse_tree_start(char* file);
        char* word_by_prefix(char* prefix);
        char* word_by_suffix(char* prefix);
        //Third
        char* word_graph();
        char* possible_words(char* letters);
        //Helping User
        char* help();
        char* help(char* command);
};
#endif
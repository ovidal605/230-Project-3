#include "dictionary.h"


Dictionary *dict_create(char *w, int c, Dictionary *n)
{
    
    char *wordCopy = malloc(strlen(w));
    strcpy(wordCopy, w);

    Dictionary *newDict = (Dictionary *)malloc(sizeof(Dictionary));

    newDict->word = wordCopy;
    newDict->count = c;
    newDict->next = n;

    return newDict;
}

void word_increase(Dictionary *currWord)
{
    ++(currWord->count);
}

char *get_word(Dictionary *dict)
{
    return dict->word;
}

int get_int(Dictionary *dict)
{
    return dict->count;
}

Dictionary *get_next(Dictionary *dict)
{
    return dict->next;
}
void set_next(Dictionary *dict, Dictionary *next){
    dict->next = next;
}

void add_word(char *word, Dictionary *dict)
{
    if(get_next(dict) == NULL){
        Dictionary *newWord = dict_create(word, 1, NULL);
        set_next(dict, newWord);
    }
    else{
        Dictionary *currWord = get_next(dict);

        while (get_next(currWord) != NULL){
            if (strcmp(currWord->word, word) == 0)
            {
                word_increase(currWord);
                return;
            }
            currWord = get_next(currWord);
        }

        Dictionary *newWord = dict_create(word, 1, NULL);

        set_next(currWord, newWord);

    }
}

void print_dict(Dictionary *dict){
    dict = get_next(dict);

    while (get_next(dict) != NULL)
    {
        printf("%s: %i\n", dict->word, get_int(dict));
        dict = get_next(dict);
    }
}

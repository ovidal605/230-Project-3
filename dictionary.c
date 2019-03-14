#include "dictionary.h"

Dictionary *dict_create(char *w, int c, Dictionary *n)
{
    char *wordCopy = malloc(strlen(w));

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

void add_word(char word[], Dictionary *dict)
{
    Dictionary *currWord = dict;

    while (currWord->next != NULL)
    {
        if (strcmp(dict->word, word) == 0)
        {
            ++dict->count;
            return;
        }
    }

    Dictionary *newWord = malloc(sizeof(Dictionary));
    newWord->word = word;
    newWord->count = 1;
    newWord->next = NULL;

    currWord->next = newWord;
}

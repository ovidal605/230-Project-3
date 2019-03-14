#ifndef __DICTIONARY_H
#define __DICTIONARY_H

typedef struct Dictionary{
    char *word;
    int count; 
    struct Dictionary *next;
} Dictionary;

Dictionary *dict_create(char *w, int c, Dictionary *n);
void word_increase(Dictionary *currWord);
void word_add(Dictionary *dict, Dictionary *word);

char *get_word(Dictionary *dict);
int get_int(Dictionary *dict);
Dictionary *get_next(Dictionary *dict);

void add_word(char word[], Dictionary *dict);

#endif
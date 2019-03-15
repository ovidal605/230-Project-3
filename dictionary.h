#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Dictionary
{
    char *word;
    int count;
    struct Dictionary *next;
} Dictionary;

Dictionary *dict_create(char *w, int c, Dictionary *n);
void word_increase(Dictionary *currWord);
void word_add(Dictionary *dict, Dictionary *word);
void set_next(Dictionary *dict, Dictionary *next);

char *get_word(Dictionary *dict);
int get_int(Dictionary *dict);
Dictionary *get_next(Dictionary *dict);

void add_word(char *word, Dictionary *dict);

void print_dict(Dictionary *dict);

#endif
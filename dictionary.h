#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "printer.h"

//Dictionary struct
typedef struct Dictionary
{
    char *word;
    int count;
    struct Dictionary *next;
} Dictionary;

//Prototypes
void word_increase(Dictionary *currWord);
void word_add(Dictionary *dict, Dictionary *word);
void set_next(Dictionary *dict, Dictionary *next);
void setWord(Dictionary *dict, char *word);
void setCount(Dictionary *dict, int count);
void add_word(char *word, Dictionary *dict);
void print_dict(Dictionary *dict);
void free_dict(Dictionary *dict);

Dictionary *get_next(Dictionary *dict);
Dictionary *dict_create(char *w, int c, Dictionary *n);

char *get_word(Dictionary *dict);

int get_int(Dictionary *dict);
#endif
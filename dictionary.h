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
void wordIncrease(Dictionary *currWord);
void setNext(Dictionary *dict, Dictionary *next);
void setWord(Dictionary *dict, char *word);
void setCount(Dictionary *dict, int count);
void addWord(char *word, Dictionary *dict);
void printDict(Dictionary *dict);
void freeDict(Dictionary *dict);

Dictionary *getNext(Dictionary *dict);
Dictionary *dictCreate(char *w, int c, Dictionary *n);

char *getWord(Dictionary *dict);

int getCount(Dictionary *dict);
#endif
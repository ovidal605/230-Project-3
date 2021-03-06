#ifndef __PRINTER_H
#define __PRINTER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

//Prototypes
void printCharArr(char *arr, int length);
void printStr(char *string);
void printErr(int err);
void printKeyValuePair(char *key, int value, int whitespace);
#endif
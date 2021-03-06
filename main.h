#ifndef __MAIN_H
#define __MAIN_H

/* Unused
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
*/

#include <unistd.h>
#include <stdbool.h>
#include "fileReader.h"
#include "printer.h"
#include "dictionary.h"

//Prototypes
void readStdIn(Dictionary *dict);
void readCmdLine(Dictionary *dict, int argc, char *argv[]);
void readEnv(Dictionary *dict);
void readFile(Dictionary *dict, char *path);
void parseFile(Dictionary *dict, FileReader *reader);

char toLower(char c);

bool isLetter(char c);
#endif
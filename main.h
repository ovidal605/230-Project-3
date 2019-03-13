#ifndef __MAIN_H
#define __MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "file.h"

void readStdIn();
void readCmdLine(int argc, char *argv[]);
void readEnv();
void readFile(char *path);

void parseOpenFile();
char toLower(char c);
bool isLetter(char c);

#endif
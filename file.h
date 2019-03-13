#ifndef __FILE_H
#define __FILE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define END 3

int openFile(char *path);
void setFile(int fd);

char getNextChar();

int closeFile();

#endif
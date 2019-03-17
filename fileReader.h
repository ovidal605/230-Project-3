#ifndef __FILE_READER_H
#define __FILE_READER_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "printer.h"

#define BUF_SIZE 1024
#define END 3

//FileReader struct
typedef struct
{
  int fd;
  int unsigned offset;
  char *buffer;
} FileReader;

//Prototypes
void setFileReaderFD(FileReader *reader, int fd);
void setFileReaderOffset(FileReader *reader, int offset);

FileReader *createReader(int fd);
FileReader *openFile(char *path);

int closeReader(FileReader *reader);
int getFileReaderFD(FileReader *reader);
int getFileReaderOffset(FileReader *reader);

char getNextChar(FileReader *reader);
char *getFileReaderBuffer(FileReader *reader);
#endif
#include "fileReader.h"

//Sets the static variables 
static int fd = -1;
static char buffer[BUF_SIZE];
static unsigned int offset = 0;

//Returns a pointer to the FileReader
FileReader *createReader(int fd)
{
  //Creates and allocates space for a FileReader struct
  FileReader *reader = malloc(sizeof(FileReader));

  //Allocates space for the buffer
  reader->buffer = malloc(BUF_SIZE * sizeof(char));

  //Sets the File reader and the offset
  setFileReaderFD(reader, fd);
  setFileReaderOffset(reader, BUF_SIZE);

  return reader;
}

//Returns the FileReader
FileReader *openFile(char *path)
{
  //Attempts to open the file in read only mode
  fd = open(path, O_RDONLY);

  //If there is an error print the error and exit the program
  if (fd == -1)
  {
    printErr(errno);
    exit(0);
  }

  return createReader(fd);
}

//Closes and frees the FileReader
int closeReader(FileReader *reader)
{
  if (!reader)
    return 0;

  // Refuse to close standard io files and check for close errors
  if (getFileReaderFD(reader) > 2 && close(getFileReaderFD(reader)) == -1)
  {
    printErr(errno);
    exit(0);
  }

  // Free the memory associated with the file
  free(reader->buffer);
  free(reader);

  return 0;
}

//Gets the next character
char getNextChar(FileReader *reader)
{
  int fd = getFileReaderFD(reader);
  int offset = getFileReaderOffset(reader);
  char *buffer = getFileReaderBuffer(reader);

  // If we have reached the end of the buffer, read more character
  if (offset >= BUF_SIZE)
  {

    ssize_t bytesRead = read(fd, buffer, BUF_SIZE);

    if (bytesRead == -1)
    {
      printErr(errno);
      exit(0);
    }

    // If we have reached the end of the file add an end of file charater
    if (bytesRead < BUF_SIZE)
    {
      buffer[bytesRead] = END;
    }

    offset = 0;
    setFileReaderOffset(reader, offset);
  }

  // Return the next character in the buffer and increment the offset
  setFileReaderOffset(reader, offset + 1);

  return buffer[offset];
}

//Gets the FileReader
int getFileReaderFD(FileReader *reader)
{
  return reader->fd;
}

//Gets the offset
int getFileReaderOffset(FileReader *reader)
{
  return reader->offset;
}

//Gets a pointer to the buffer
char *getFileReaderBuffer(FileReader *reader)
{
  return reader->buffer;
}

//Sets the FileReader
void setFileReaderFD(FileReader *reader, int fd)
{
  reader->fd = fd;
}

//Sets the offset
void setFileReaderOffset(FileReader *reader, int offset)
{
  reader->offset = offset;
}
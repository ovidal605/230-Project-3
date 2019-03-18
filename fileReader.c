#include "fileReader.h"

/*
 * Returns a new Filereader from an open file descriptor
 */
FileReader *createReader(int fd)
{
  // Creates and allocates space for a FileReader struct
  FileReader *reader = malloc(sizeof(FileReader));

  // Allocates space for the buffer
  reader->buffer = malloc(BUF_SIZE * sizeof(char));

  // Sets the File reader and the offset
  setFileReaderFD(reader, fd);
  setFileReaderOffset(reader, BUF_SIZE);

  return reader;
}

/*
 * Returns a new FileReader from a file at the given path
 */
FileReader *openFile(char *path)
{
  // Attempts to open the file in read only mode
  int fd = open(path, O_RDONLY);

  // If there is an error print the error and exit the program
  if (fd == -1)
  {
    printErr(errno);
    exit(0);
  }

  return createReader(fd);
}

/*
 * Closes and frees a FileReader
 */
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

/*
 * Gets the next character the FileReaders buffer.
 * If the offset is at the end of the buffer, read more character into the buffer.
 * If no characters are left to read, add an end of file character 
 */
char getNextChar(FileReader *reader)
{
  int fd = getFileReaderFD(reader);
  int offset = getFileReaderOffset(reader);
  char *buffer = getFileReaderBuffer(reader);

  // If we have reached the end of the buffer, read more characters
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

/*
 * Gets the file descriptor from a FileReader
 */
int getFileReaderFD(FileReader *reader)
{
  return reader->fd;
}

/*
 * Gets the offset from a FileReader
 */
int getFileReaderOffset(FileReader *reader)
{
  return reader->offset;
}

/*
 * Gets the buffer from a FileReader
 */
char *getFileReaderBuffer(FileReader *reader)
{
  return reader->buffer;
}

/*
 * Sets the file descriptor of a FileReader
 */
void setFileReaderFD(FileReader *reader, int fd)
{
  reader->fd = fd;
}

/*
 * Sets the offset of a FileReader
 */
void setFileReaderOffset(FileReader *reader, int offset)
{
  reader->offset = offset;
}
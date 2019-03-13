#include "fileReader.h"

static int fd = -1;
static char buffer[BUF_SIZE];
static unsigned int offset = 0;

FileReader *createReader(int fd)
{
  FileReader *reader = malloc(sizeof(FileReader));

  reader->buffer = malloc(BUF_SIZE * sizeof(char));

  setFileReaderFD(reader, fd);
  setFileReaderOffset(reader, BUF_SIZE);

  return reader;
}

FileReader *openFile(char *path)
{
  fd = open(path, O_RDONLY);

  if (fd == -1)
  {
    return NULL;
  }

  return createReader(fd);
}

int closeReader(FileReader *reader)
{
  if (!reader)
    return 0;

  // refuse to close standard io files
  if (getFileReaderFD(reader) > 2)
    return close(fd);

  free(reader->buffer);
  free(reader);

  return 0;
}

char getNextChar(FileReader *reader)
{
  int fd = getFileReaderFD(reader);
  int offset = getFileReaderOffset(reader);
  char *buffer = getFileReaderBuffer(reader);

  // if we have reached the end of the buffer, read more character
  if (offset >= BUF_SIZE)
  {

    ssize_t bytesRead = read(fd, buffer, BUF_SIZE);

    // if we have reached the end of the file add an end of file charater
    if (bytesRead < BUF_SIZE)
    {
      buffer[bytesRead] = END;
    }

    offset = 0;
    setFileReaderOffset(reader, offset);
  }

  // return the next character in the buffer and increment the offset
  setFileReaderOffset(reader, offset + 1);

  return buffer[offset];
}

int getFileReaderFD(FileReader *reader)
{
  return reader->fd;
}

int getFileReaderOffset(FileReader *reader)
{
  return reader->offset;
}

char *getFileReaderBuffer(FileReader *reader)
{
  return reader->buffer;
}

void setFileReaderFD(FileReader *reader, int fd)
{
  reader->fd = fd;
}

void setFileReaderOffset(FileReader *reader, int offset)
{
  reader->offset = offset;
}
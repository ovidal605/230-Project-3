#include "file.h"

static int fd = -1;
static char buffer[BUF_SIZE];
static unsigned int offset = 0;

int openFile(char *path)
{
  fd = open(path, O_RDONLY);
  offset = BUF_SIZE;
  return fd;
}

void setFile(int _fd)
{
  fd = _fd;
  offset = BUF_SIZE;
}

char getNextChar()
{
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
  }

  // return the next character in the buffer then increment the offset
  return buffer[offset++];
}

int closeFile()
{
  // refuse to close standard io files
  if (fd > 2)
    return close(fd);

  return 0;
}
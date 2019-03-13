#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main(int argc, char *argv[], char *envp[])
{

  if (argc == 1) // Read from STDIN
  {
    readStdIn();
  }
  else if (argc > 1) // Read from commandline arguments
  {
    readCmdLine(argc, argv);
  }

  // Read from environment variable
  readEnv();

  return 0;
}

char toLower(char c)
{
  if (c >= 65 && c <= 90)
  {
    return c + 32;
  }

  return c;
}

bool isLetter(char c)
{
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

void readStdIn()
{
  setFile(STDIN_FILENO);
  parseOpenFile();
}

void readCmdLine(int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    readFile(argv[i]);
  }
}

void readEnv()
{
  char *value = getenv("WORD_FREAK");
  if (value)
  {
    readFile(value);
  }
}

void readFile(char *path)
{
  int fd = openFile(path);

  if (fd == -1)
  {
    // REPLACE WITH SYSTEM CALL
    printf("File %s not found.\n", path);
    exit(0);
  }

  parseOpenFile();

  closeFile(fd);
}

void parseOpenFile()
{
  // current word being built
  char *word = malloc(100 * sizeof(char));

  // current character from the file
  char c;
  // current index of next character for the word being build
  int pos = 0;

  // while we are not at the end of the file, build words
  while ((c = getNextChar()) != END)
  {

    // if the next char is a letter add it to the word
    if (isLetter(c))
    {
      word[pos] = toLower(c);
      pos++;
    }
    // else save the last word and clear vars to build the next word
    else
    {
      if (pos > 0)
      {
        // add the null character to make it a string
        word[pos] = '\0';

        printf("%s\n", word); // REPLACE WITH ADDING TO DICTIONARY

        free(word);
        word = malloc(100 * sizeof(char));
        pos = 0;
      }
    }
  }

  // Add the last word that was being built
  word[pos] = '\0';

  printf("%s\n", word); // REPLACE WITH ADDING TO DICTIONARY

  free(word);
}

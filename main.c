#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dictionary.h"
#include "main.h"
#include "printer.h"

int main(int argc, char *argv[], char *envp[])
{

  printStr("Word Freak Text Analyzer\n");
  printStr("------------------------\n");

  Dictionary *dict = dict_create("HEAD", 0, NULL);

  if (argc == 1) // Read from STDIN
  {
    readStdIn(dict);
  }
  else if (argc > 1) // Read from commandline arguments
  {
    readCmdLine(dict, argc, argv);
  }

  // Read from environment variable
  readEnv(dict);

  print_dict(dict);

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

void readStdIn(Dictionary *dict)
{
  FileReader *reader = createReader(STDIN_FILENO);
  parseFile(dict, reader);
  closeReader(reader);
}

void readCmdLine(Dictionary *dict, int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    readFile(dict, argv[i]);
  }
}

void readEnv(Dictionary *dict)
{
  char *value = getenv("WORD_FREAK");
  if (value)
  {
    readFile(dict, value);
  }
}

void readFile(Dictionary *dict, char *path)
{
  FileReader *reader = openFile(path);

  if (!reader)
  {
    // REPLACE WITH SYSTEM CALL
    printStr("Invalid input file. Skipping.\n");
    closeReader(reader);
    return;
  }

  parseFile(dict, reader);

  closeReader(reader);
}

void parseFile(Dictionary *dict, FileReader *reader)
{

  // current word being built
  char *word = malloc(100 * sizeof(char));

  // current character from the file
  char c;
  // current index of next character for the word being build
  int pos = 0;

  // while we are not at the end of the file, build words
  while ((c = getNextChar(reader)) != END)
  {

    // if the next char is a letter add it to the word
    if (isLetter(c) || c == '\'')
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

        add_word(word, dict);

        free(word);
        word = malloc(100 * sizeof(char));
        pos = 0;
      }
    }
  }

  if (pos > 0)
  {
    // Add the last word that was being built
    word[pos] = '\0';

    add_word(word, dict);

    free(word);
  }
}

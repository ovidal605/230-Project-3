#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dictionary.h"
#include "main.h"
#include "printer.h"

int main(int argc, char *argv[], char *envp[])
{
  // Title
  printStr("Word Freak Text Analyzer\n");
  printStr("------------------------\n");

  // Creates Dictionary
  Dictionary *dict = dictCreate("HEAD", 0, NULL);

  // If there are no command line arguments read from STDIN
  if (argc == 1)
  {
    readStdIn(dict);
    printStr("\n");
  }
  // If there are more than one command line arguments read from commandline arguments
  else if (argc > 1)
  {
    readCmdLine(dict, argc, argv);
  }

  // Read from environment variable
  readEnv(dict);

  //Print the Dictionary
  printDict(dict);

  return 0;
}

/*
 * Returns the given character as the lowercase version if the given character is an Uppercase letter
 */
char toLower(char c)
{
  if (c >= 65 && c <= 90)
  {
    return c + 32;
  }

  return c;
}

/*
 * Returns true if the given character is a letter (uppercase or lowercase)
 */
bool isLetter(char c)
{
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

/*
 * Attempts to analyze text input from stdin.
 * If any words exists, it adds them to the dictionary
 */
void readStdIn(Dictionary *dict)
{
  FileReader *reader = createReader(STDIN_FILENO);
  parseFile(dict, reader);
  closeReader(reader);
}

/*
 * Attempts to analyze text input from the given file path command line arguments
 * If the file paths are valid files and they contain words, it adds them to the dictionary.
 */
void readCmdLine(Dictionary *dict, int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    readFile(dict, argv[i]);
  }
}

/*
 * Attempts to analyze text input from the file at the path defined by the WORD_FREAK env variable
 * If the file path is valid a file and it contain words, it adds them to the dictionary.
 */
void readEnv(Dictionary *dict)
{
  char *value = getenv("WORD_FREAK");
  if (value)
  {
    readFile(dict, value);
  }
}

/*
 * Attempts to open the file at the given path.
 * If succesful, it analyzes the words contained in the file and adds them to the dictionary
 */
void readFile(Dictionary *dict, char *path)
{
  FileReader *reader = openFile(path);

  // If the file returns a nullptr, skip the file.
  if (!reader)
  {
    printStr("Invalid input file. Skipping.\n");
    closeReader(reader);
    return;
  }

  parseFile(dict, reader);

  closeReader(reader);
}

/*
 * Individualy analyzes each character of the given file opened by the file reader.
 * Any words that are parsed in the file are added to the dictionary.
 */
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

        addWord(word, dict);

        free(word);
        word = malloc(100 * sizeof(char));
        pos = 0;
      }
    }
  }

  // add the last word that was being built
  if (pos > 0)
  {
    word[pos] = '\0';

    addWord(word, dict);

    free(word);
  }
}

#include "printer.h"

//Prints the word
void printCharArr(char *arr, int length)
{
  if (write(STDOUT_FILENO, arr, length) == -1)
  {
    exit(0);
  }
}

//Prints the word
void printStr(char *str)
{
  printCharArr(str, strlen(str));
}

//Prints an error message
void printErr(int err)
{
  char out[50];
  int size = sprintf(out, "Error %d encountered.\n", err);
  printCharArr(out, size);
}

//Prints the word along with its count
void printKeyValuePair(char *key, int value, int whitespace)
{
  char str[60];

  for (int i = 0; i < 60; i++)
  {
    str[i] = ' ';
  }

  int size = sprintf(str, "%-*s:%8i\n", whitespace, key, value);

  printCharArr(str, size);
}
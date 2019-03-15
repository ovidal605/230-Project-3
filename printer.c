#include "printer.h"

void printCharArr(char *arr, int length)
{
  write(STDOUT_FILENO, arr, length);
}

void printStr(char *str)
{
  printCharArr(str, strlen(str));
}

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
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
  char *str = (char *)calloc(40, sizeof(char));

  sprintf(str, "%-*s:%8i\n", whitespace, key, value);
  //printf("%s", str);
  printCharArr(str, 40);

  free(str);
}
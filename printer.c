#include "printer.h"

/*
 * Prints the character array to standard output
 */
void printCharArr(char *arr, int length)
{
  if (write(STDOUT_FILENO, arr, length) == -1)
  {
    exit(0);
  }
}

/*
 * Prints the string to standard output
 */
void printStr(char *str)
{
  printCharArr(str, strlen(str));
}

/*
 * Prints an error message with the supplied error code
 */
void printErr(int err)
{
  char out[50];
  int size = sprintf(out, "Error %d encountered.\n", err);
  printCharArr(out, size);
}

/*
 * Prints the word along with its count with a set amount of whitespace for the word alignment
 */
void printKeyValuePair(char *key, int value, int whitespace)
{
  char str[60];

  // Align the input with each word having $whitespace amount of whitespace
  int size = sprintf(str, "%-*s:%8i\n", whitespace, key, value);

  printCharArr(str, size);
}
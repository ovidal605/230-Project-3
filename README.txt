
Video Demonstration: 

REQUIRMENTS
1) Include a Makefile that compiles your submitted code.
    - Makefile -> Contains the source and object files: main.c/.o, fileReader.c/.o, printer.c/.o

2) Include both C source files and header files. You can decide how best to organize your code and determine how many source and header files you require.
    - Our program includes the following source and header files: main.c/.h dictionary.c/.h fileReader.c/.h printer.c/.h

3) have good code organization using source and header files, functions, comments, and proper indentation.
    - All of our code has the proper indentation along with comments

4) include a README.txt file that provides an overview of how your code is structured, which parts of your code demonstrate a rubric item, and any other useful information that will help the reviewer understand your code.
    - The README.txt is included

5) compile a program that will accept 0 to n command line arguments. If your program receives 0 command line arguments it will read from standard input (using the bash pipe operator) for analysis. If your program receives 1 to n command line arguments it will open the provided files for analysis.
    - main.c -> readStdIn(), readCmdLine(), readEnv() -> Correctly handles each of the scenarios specified.

6) compile a program that will use a specified WORD_FREAK environment variable to parse and analyze a text file and produce the proper output.  
    - main.c -> readEnv() -> Looks for the variable "WORD_FREAK" and reads the file that is stored in the variable.

7) use dynamic allocation and freeing (e.g., malloc(), free()).
    - dictionary.c, fileReader.c -> dict_create()/free_dict(), createReader()/closeReader() -> the create functions use malloc to allocate space for the Dictionary strict and the FileReader struct. The other two functions use the free() command to deallocate the memory used.

8) use structs and typedef.
    - dictionary.h, fileReader.h -> Contain the Dictionary and FileReader structs and defines them as such.

9) use pointers.
    - used throughout the program.

10) use only system calls for I/O.
    - Input is handled in the fileReader.c file
    - Output is handled in the printer.c file

11) align output using only system calls for I/O.
    - alignment uses the allowed sprintf() function in printer.c

12) provide error checking for all system and library calls.
    - the above mentioned IO classes exit the program when the receive a -1 return value.

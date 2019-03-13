SRC = main.c dictionary.c file.c
OBJ = main.o dictionary.o file.o
PROG = a.out

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

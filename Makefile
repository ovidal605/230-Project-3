SRC = main.c dictionary.c fileReader.c
OBJ = main.o dictionary.o fileReader.o
PROG = a.out

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

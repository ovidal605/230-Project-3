SRC = main.c dictionary.c fileReader.c printer.c
OBJ = main.o dictionary.o fileReader.o printer.o
PROG = wordfreak

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

CC = g++
CFLAGS = -std=c++0x -I.
DEPS = BinaryTree.h Node.h
OBJ = main.o BinaryTree.o Node.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

bst: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

tidy:
		rm -f *.o core
clean:
		rm -f *.o core game

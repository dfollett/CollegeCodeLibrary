CC = g++
CFLAGS = -std=c++0x -I.
DEPS = Reader.h Writer.h
OBJ1 = Writer.o Reader.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
tidy:
		rm -f *.o core
clean:
		rm -f *.o core game

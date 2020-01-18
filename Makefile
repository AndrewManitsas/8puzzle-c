CC := gcc
CFLAGS := -Wall -g
INCLUDE :=
LIBS :=
SRC := $(wildcard *.c)
EXECNAME := 8puzzle.out

ex1: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECNAME)

clean:
	rm -rf *.out
	rm -rf *.dSYM
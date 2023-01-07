CC=gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) $^ -o &@

txtfind: txtfind.o
	$(CC) $(FLAGS) $^ -o &@

%.0: %.c
	$(CC) $(FLAGS) -c $<

.PHONY: all clean
clean:
	rm -f *.o isort txtfind
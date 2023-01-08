CC=gcc
FLAGS = -Wall -g
INSORT=isort.o
TXT_FIND=txtfind.o
all: isort.o txtfind.o isort.c txtfind.c

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c


.PHONY: all clean
clean:
	rm -f *.o isort txtfind
CC=gcc
FLAGS = -Wall -g
INSORT=isort.o
TXT_FIND=txtfind.o

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) $^ -o $@
	
txtfind: txtfind.o
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $<


.PHONY: all clean
clean:
	rm -f *.o isort txtfind
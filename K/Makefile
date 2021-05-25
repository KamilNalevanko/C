CC=gcc
CFLAGS=-std=c11 -Werror -Wall -g
LDLIBS=-lm
OUTPUT=ps3

all: k.o hof.o ui.o main.c
	echo "Building main"
	$(CC) $(CFLAGS) k.o hof.o ui.o main.c $(LDLIBS) -o $(OUTPUT)

k.o: k.c k.h
	echo "Building k.o ..."
	$(CC) $(CFLAGS) -c k.c

hof.o: hof.c hof.h
	echo "Building hof.o ..."
	$(CC) $(CFLAGS) -c hof.c

ui.o: ui.c ui.h
	echo "Building ui.o ..."
	$(CC) $(CFLAGS) -c ui.c

clean:
	echo "cleaning ..."
	rm -rf $(OUTPUT) k.o hof.o ui.o

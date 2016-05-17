CC=g++
CFLAGS=-c -Wall

all: driver

driver: main.o
	$(CC) main.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o driver

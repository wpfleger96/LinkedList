CC = g++
DEBUG = -g
CFLAGS = -Wall -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main

main: 
	$(CC) $(CFLAGS) -o main Main.cpp LinkedList.cpp ItemType.cpp 

clean:
	rm -rf main
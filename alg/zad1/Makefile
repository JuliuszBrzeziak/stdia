CC = g++
CFLAGS = -o -Wall
DEPS = stack.hpp

stack: clean
	$(CC) stack.cpp -o stack.x -Wall 
	./stack.x


gen: clean
	$(CC) gen.cpp -o gen.x -Wall

all: stack gen

stdin: gen
	$(CC) stdin.cpp -o stdin.x -Wall
	./gen.x | ./stdin.x

clean:
	rm -f *.o *.c


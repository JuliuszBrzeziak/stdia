CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp

stack: clean
	$(CC) stack.cpp -o stack.x -Wall 
	./stack.x


gen: clean
	$(CC) gen.cpp -o gen.x -Wall
	./gen.x

all: stack gen

stdin: gen
	$(CC) stdin.cpp -o stdin.x -Wall
	./gen.x | ./stdin.x

queue: clean
	$(CC) queue.cpp -o queue.x -Wall
	./queue.x
clean:
	rm -f *.o *.c

test-queue: clean
	$(CC) test-queue.cpp -o test-queue.x -Wall
	./test-queue.x


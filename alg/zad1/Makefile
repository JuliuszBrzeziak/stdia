CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp

stack: clean
	$(CC) stack.cpp -o stack.x -Wall 

runstack: stack
	./stack.x


gen: clean
	$(CC) gen.cpp -o gen.x -Wall

rungen: gen
	./gen.x

try: gen stack
	./gen.x | ./stack.x

all: stack gen

stdin: clean
	$(CC) queue.cpp -o queue.x -Wall
	./gen.x | ./queue.x

queue: clean
	$(CC) queue.cpp -o queue.x -Wall

runqueue: queue
	./queue.x

clean:
	rm -f *.o *.c

test-queue: queue gen
	$(CC) test-queue.cpp -o test-queue.x -Wall
	./gen.x | ./queue.x


test-stack: stack gen
	$(CC) test-stack.cpp -o test-stack.x -Wall
	./gen.x | ./stack.x



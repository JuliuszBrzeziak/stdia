CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp

stack: clean
	$(CC) stack.cpp -o stack.x -Wall 

runstack: stack
	./stack.x


gen: clean
	$(CC) gen.cpp -o gen.x -Wall

stdstack: clean
	$(CC) stdstack.cpp -o stdstack.x -Wall

stdqueue: clean
	$(CC) stdqueue.cpp -o stdqueue.x -Wall

rungen: gen
	./gen.x

trys: gen stack stdstack
	echo "stack test"
	echo "my lib"
	time ./gen.x | ./stack.x >> mystack.txt
	echo "std"
	time ./gen.x | ./stdstack.x >> stdstack.txt


tryq: gen queue stdqueue
	echo "queue test"
	echo "my lib"
	time ./gen.x | ./queue.x >> myqueue.txt
	echo "std"
	time ./gen.x | ./stdqueue.x >> stdqueue.txt



all: stack gen

stdin: clean
	$(CC) queue.cpp -o queue.x -Wall
	./gen.x | ./queue.x

queue: clean
	$(CC) queue.cpp -o queue.x -Wall

runqueue: queue
	./queue.x

clean:
	rm -f *.o *.c *.x *.gz *.txt

test-queue: queue gen
	$(CC) test-queue.cpp -o test-queue.x -Wall
	./gen.x | ./queue.x


test-stack: stack gen
	$(CC) test-stack.cpp -o test-stack.x -Wall
	./gen.x | ./stack.x



tar: clean
	tar -czvf Julius_Brzeziak_Zestaw01.tar.gz *
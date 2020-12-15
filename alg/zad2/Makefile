CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp



array: clean
	$(CC) arraylist.cxx -o arraylist.x -pedantic-errors
	./arraylist.x


test: clean gen
	$(CC) queue.cpp -o queue.x -Wall
	./gen.x | ./queue.x >>  mylist.txt



gen: clean
	g++ gen.cpp -o gen.x -Wall




clean:
	rm -f *.o *.c *.x *.gz *.txt 
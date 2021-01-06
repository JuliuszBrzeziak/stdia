CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp



CXX=g++
CFLAGS=-Wall -std=c++14

TEST=cursorlist.cxx
EXECUTABLE=$(TEST:.cpp=)

cursor:
	$(CC) cursorlist2.cxx -o cursorlist.x -pedantic-errors
	./cursorlist.x

clean:
	rm $(EXECUTABLE)



array: clean
	$(CC) ArrayList.cxx -o arraylist.x -pedantic-errors
	./arraylist.x

pointer: clean
	$(CC) PointerList.cxx -o pointerlist.x -Wall
	./pointerlist.x


test: clean gen
	$(CC) queue.cpp -o queue.x -Wall
	./gen.x | ./queue.x >>  mylist.txt



gen: clean
	g++ gen.cpp -o gen.x -Wall




clean:
	rm -f *.o *.c *.x *.gz *.txt 
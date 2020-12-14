CC = g++ 
CFLAGS = -o -Wall
DEPS = stack.hpp



array: clean
	$(CC) arraylist.cxx -o arraylist.x -Wall
	./arraylist.x


test: clean
	$(CC) test.cxx -o test.x -Wall
	./test.x


clean:
	rm -f *.o *.c *.x *.gz *.txt 
CC = g++ 
CFLAGS = -o -Wall





cursor: clean
	$(CC) CursorList.cxx -o cursorlist.x -Wall

stdlist: clean
	$(CC) stdlist.cxx -o stdlist.x -Wall


array: clean
	$(CC) ArrayList.cxx -o arraylist.x -Wall


pointer: clean
	$(CC) PointerList.cxx -o pointerlist.x -Wall


testa: clean gen array stdlist
	echo "arraylist test"
	echo "my lib"
	time ./gen.x | ./arraylist.x >>  myarraylist.txt
	echo "std"
	time ./gen.x | ./stdlist.x >> stdlist.txt
	diff myarraylist.txt stdlist.txt


testp: clean gen pointer stdlist
	echo "pointerlist test"
	echo "my lib"
	time ./gen.x | ./pointerlist.x >>  mypointerlist.txt
	echo "std"
	time ./gen.x | ./stdlist.x >> stdlist.txt
	diff mypointerlist.txt stdlist.txt

testc: clean gen cursor stdlist
	echo "cursorlist test"
	echo "my lib"
	time ./gen.x | ./cursorlist.x >>  mycursorlist.txt
	echo "std"
	time ./gen.x | ./stdlist.x >> stdlist.txt
	diff mycursorlist.txt stdlist.txt






gen: clean
	g++ gen.cpp -o gen.x -Wall




clean:
	rm -f *.o *.c *.x *.gz *.txt 

clean:
	rm -f *.o *.x *.gz *.txt 


test: clean
	gcc gs.c -lgsl -lgslcblas -lm -o gs.x -Wall
	./gs.x

zad2: clean
	gcc zad2.c -lgsl -lgslcblas -lm -o zad2.x -Wall
	./zad2.x
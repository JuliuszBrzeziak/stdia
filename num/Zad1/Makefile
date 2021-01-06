





a: clean
	g++ zad1.cpp -o zad1.x -Wall
	./zad1.x > resa.dat


b: clean
	g++ zadb.cpp -o zadb.x -Wall
	./zadb.x > resb.dat

c: a b
	gnuplot
	plot "resa.dat", "resb.dat"

clean:
	rm -f *.o *.c *.x *.gz *.txt 
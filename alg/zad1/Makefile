CC = g++
CFLAGS = -o -Wall
DEPS = stack.hpp

%.o: clean %.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

makestackc: clean
	$(CC) stack.cpp -o stack.o -Wall

all: clean v$(TARGET) 


$(TARGET): clean $(TARGET).cpp 
	$(CC) $(TARGET) -o $(TARGET).x -Wall
	./$(TARGET).o

	
clean:
	$(RM) $(TARGET) *.x *.o *


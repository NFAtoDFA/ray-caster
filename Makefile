CC=g++
CFLAGS=-lSDL2
SOURCES=rayCast.cpp inc.cpp
DEPS= inc.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

raycast: rayCast.o inc.o
	$(CC) -o Program rayCast.o inc.o $(CFLAGS)

clean: 
	rm -f *.o

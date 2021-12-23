# Makefile
CXX_FLAG = --std=c++11 -g

all: main testcards

main: main.o cards.o
	g++ $(CXX_FLAG) -o main main.o cards.o

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

testrest.o: testrest.cpp
	g++ -c $(CXX_FLAG) testrest.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f main testcards *.o

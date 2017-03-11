CFLAGS = -Wall -ansi -pedantic

all: utils
	g++ main.cpp grafo.o -o main $(CFLAGS)

utils:
	g++ -c grafo.cpp -o grafo.o $(CFLAGS)

clean:
	rm -f main *.o

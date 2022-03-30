all: machine_reader

hexnum.o: hexnum.cpp hexnum.h
	g++ -c hexnum.cpp

machine_reader: main.o operator.o hexnum.o
	g++ -o machine_reader main.o operator.o hexnum.o
main.o: main.cpp operator.h hexnum.h
	g++ -c main.cpp
operator.o: operator.cpp operator.h
	g++ -c operator.cpp 

clean:
	rm machine_reader *.o

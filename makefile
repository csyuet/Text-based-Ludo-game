FLAGS = -pedantic-errors -std=c++11
 
all: main play clean
 
main: main.cpp functions.cpp
	g++ $(FLAGS) -c main.cpp functions.cpp
 
play: main.o functions.o
	g++ main.o functions.o -o main 

clean: 
	rm -f *.o

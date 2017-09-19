tp1: *.cpp
	g++ -o tp1 *.cpp

val: *.cpp
	g++ -g -o tp1 *.cpp
	valgrind ./tp1

run: *.cpp
	g++ -o tp1 *.cpp
	./tp1
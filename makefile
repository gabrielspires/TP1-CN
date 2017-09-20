tp1: *.cpp
	g++ -o tp1 *.cpp

val: *.cpp
	g++ -g -o tp1 *.cpp
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./tp1

run: *.cpp
	g++ -o tp1 *.cpp
	./tp1
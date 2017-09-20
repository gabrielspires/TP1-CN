tp1: *.cpp
	g++ -o tp1 *.cpp

val: *.cpp
	g++ -g -o tp1 *.cpp
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./tp1

run: *.cpp
	reset
	g++ -o tp1 *.cpp
	./tp1

input_run: *.cpp
	reset
	g++ -o tp1 *.cpp
	./tp1 datasets/keijzer-10-test.csv datasets/keijzer-10-train.csv
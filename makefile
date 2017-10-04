tp1: *.cpp
	g++ -std=c++11 -o tp1 *.cpp

val: *.cpp
	g++ -std=c++11 -g -o tp1 *.cpp
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./tp1 datasets/keijzer-10-train.csv datasets/keijzer-10-test.csv

run: *.cpp
	reset
	g++ -std=c++11 -o tp1 *.cpp
	./tp1

k7: *.cpp
	@#clear
	@g++ -std=c++11 -o tp1 *.cpp
	./tp1 datasets/keijzer-7-train.csv datasets/keijzer-7-test.csv

k10: *.cpp
	@g++ -std=c++11 -o tp1 *.cpp
	./tp1 datasets/keijzer-10-train.csv datasets/keijzer-10-test.csv

house: *.cpp
	@g++ -std=c++11 -o tp1 *.cpp
	./tp1 datasets/house-train.csv datasets/house-test.csv
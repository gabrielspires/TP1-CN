#ifndef DEPENDENCIES_H
#define DEPENDENCIES_H

#include <iostream>//Biblioteca padrão do C++
#include <cstdlib> //Biblioteca padrão do C
#include <ctime>   //Time pra geração da seed do rand()
#include <string>  //Lida com strings
#include <sstream> //Lida com string streams
#include <fstream> //Lida com entrada/saida de arquivos
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

const int ind_max_size = 7,
	    init_pop_size = 10,
	    max_pop_size = 20,
	    max_gen = 500,
	    tourn_size = 5;

const double cross_rate = 0.95,
       mut_rate = 0.05;

const bool use_elitism = true;

// enum Operator{ SUM, SUB, DIV, MUL, COS, SIN };
const string operators[] = {"+", "-", "/", "*", "cos", "sin"};
const string variables[] = {"x1" , "x2", "x3", "x4", "x5", "x6", "x7", "x8"};
enum vars{x1,x2,x3,x4,x5,x6,x7,x8};

const int num_of_op = (sizeof(operators)/sizeof(string));
// const int num_of_var = (sizeof(variables)/sizeof(string));

const int MIN_CONST = 0, MAX_CONST = 100;

#endif //DEPENDENCIES_H
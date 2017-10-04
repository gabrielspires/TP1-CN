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
#include <random>
#include <algorithm>

using namespace std;

const int ind_max_size = 4,
               max_gen = 300,
         init_pop_size = 50,
          max_pop_size = 200,
            tourn_size = 2,
              num_runs = 30;

const double cross_rate = 0.6,
               mut_rate = 0.4;

const int elite_count = 2;

extern int node_number;

// enum Operator{ SUM, SUB, DIV, MUL, COS, SIN };
const string operators[] = {"+", "-", "/", "*", "cos", "sin"};
const string variables[] = {"x1" , "x2", "x3", "x4", "x5", "x6", "x7", "x8"};
// enum vars{x1,x2,x3,x4,x5,x6,x7,x8};

const int num_of_op = (sizeof(operators)/sizeof(string));
// const int num_of_var = (sizeof(variables)/sizeof(string));

const int MIN_CONST = 0, MAX_CONST = 7;

#endif //DEPENDENCIES_H
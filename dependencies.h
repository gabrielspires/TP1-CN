#ifndef TP1_DEPENDENCIES_
#define TP1_DEPENDENCIES_

#include <iostream>//Biblioteca padrão do C++
#include <cstdlib> //Biblioteca padrão do C
#include <ctime>   //Time pra geração da seed do rand()
#include <string>  //Lida com strings
#include <sstream> //Lida com string streams
#include <fstream> //Lida com entrada/saida de arquivos
#include <vector>

using namespace std;

// enum Operator{ SUM, SUB, DIV, MUL, COS, SIN };
const string operators[] = {"+", "-", "/", "*", "cos", "sin"};
const string variables[] = {"x1" , "x2", "x3", "x4", "x5", "x6", "x7", "x8"};
enum vars{x1,x2,x3,x4,x5,x6,x7,x8};

const int num_of_op = (sizeof(operators)/sizeof(string));
const int num_of_var = (sizeof(variables)/sizeof(string));

const int MIN_CONST = 0, MAX_CONST = 100;

#endif //TP1_DEPENDENCIES_
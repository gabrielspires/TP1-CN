#ifndef TP1_DEPENDENCIES_
#define TP1_DEPENDENCIES_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

// enum Operator{ SUM, SUB, DIV, MUL, COS, SIN };
const string operators[] = {"+", "-", "/", "*", "cos", "sin"};
const string variables[] = {"x1" , "x2", "x3", "x4", "x5", "x6", "x7", "x8"};

const int num_of_op = (sizeof(operators)/sizeof(string));
const int num_of_var = (sizeof(variables)/sizeof(string));


#endif //TP1_DEPENDENCIES_
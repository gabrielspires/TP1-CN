#ifndef TP1_DEPENDENCIES_
#define TP1_DEPENDENCIES_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

enum Operator{ SUM = '+', SUB = '-', DIV = '/', MUL = '*', COS = 'c', SIN = 's'};
enum Variable{ x1 , x2, x3, x4, x5, x6, x7, x8 };

//const string operators = "+-*/";
const string operators[] = {"+", "-", "*", "/", "c", "s"};

#endif //TP1_DEPENDENCIES_
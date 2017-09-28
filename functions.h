#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Individual.cpp"

using namespace std;

void read_CSV(vector< vector<double> > &, ifstream&);

void generate_population(vector <Individual*> &, int);

void calc_fitness(vector <Individual*> &, vector< vector<double> > , int );

Individual* select(vector <Individual*> &);

void postorder(Tree* p, int indent);

#endif //FUNCTIONS_H
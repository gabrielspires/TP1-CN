#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void read_CSV(vector< vector<double> > &,
			 vector< vector<double> > &,
			 ifstream&, ifstream&);

#endif //FUNCTIONS_H
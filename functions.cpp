#include "functions.h"

void read_CSV(vector< vector<double> > &dataset_train,
			 vector< vector<double> > &dataset_test,
			 ifstream input_train,
			 ifstream input_test){
	string line;

	while(getline(input_train, line, '\n')){
		cout << line;
	}


	input_train.close();
	input_test.close();
}
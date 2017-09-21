#include "functions.h"

void read_CSV(vector< vector<double> > &dataset_train,
			 vector< vector<double> > &dataset_test,
			 ifstream &input_train,
			 ifstream &input_test){
	string line, cell;
	double cell_value;
	int i = 0;

	while(getline(input_train, line, '\n')){
		vector<double> lineVector;
		dataset_train.push_back(lineVector);

		// cout << line << endl;
		stringstream line_stream(line);

		while(getline(line_stream, cell, ',')){
			stringstream cell_stream(cell);
			cell_stream >> cell_value;
			// cout << "C: " << cell_value << " ";
			dataset_train[i].push_back(cell_value);
		}
		// cout << endl;
		i++;
	}


	input_train.close();
	input_test.close();
}
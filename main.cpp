#include "Individual.cpp"

// #include "dependencies.h"
#include "functions.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    int num_of_var;
    vector <Individual*> population;

    vector< vector<double> > dataset_train;
    vector< vector<double> > dataset_test;

    ifstream input_train(argv[1]),
    		 input_test(argv[2]);

    double sum = 0;
    double fit_med = 0;

    // cout << "Individual max size: "; cin >> ind_max_size;
    // cout << "Initial pop. size: "; cin >> init_pop_size;
    // cout << "Maximum pop. size: "; cin >> max_pop_size;
    // cout << "Maximum number of gen: "; cin >> max_gen;
    // cout << "Tournament size: "; cin >> tourn_size;
    // cout << "Crossover rate: "; cin >> cross_rate;
    // cout << "Mutation rate: "; cin >> mut_rate;


    read_CSV(dataset_train, input_train);
    read_CSV(dataset_test, input_test);

    num_of_var = dataset_train[0].size() - 1;

    for(int j=0; j < dataset_train[0].size()-1; j++) cout << "x" << j+1 << ":" << dataset_train[40][j] << " "; cout << endl;

	cout << "Y = " << dataset_train[0][dataset_train[0].size()-1] << endl;
    
    for (int i = 0; i < init_pop_size; i++){
    	//Cria um novo individuo
    	sum = 0;
        population.push_back(new Individual(num_of_var));

        for (int j = 0; j < dataset_train.size(); j++){
        	sum += pow(population[i]->genotype->evaluate(population[i]->genotype, dataset_train[j]) - dataset_train[j][dataset_train[j].size()-1], 2);
        }

        population[i]->fitness = sqrt(sum/dataset_train.size());
    	cout << "Fitness " << i << ": " << population[i]->fitness << endl;
    	fit_med += sqrt(sum/dataset_train.size());

        // cout << "Resultado: " << population[i]->genotype->evaluate(population[i]->genotype, dataset_train[40]) << " Expressão: ";
        // population[i]->printExpression(population[i]->genotype);
        // cout << endl << endl;

    }
    cout << "Fitness media: " << fit_med/20 << endl;


    
    



    
    for (int i = 0; i < init_pop_size; ++i){
    	delete population[i];
    }

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;

    return 0;
}

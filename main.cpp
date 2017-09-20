#include "dependencies.h"
#include "Tree.cpp"
#include "Individual.cpp"

#include "functions.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));
    
    int ind_max_size = 7,
        init_pop_size = 10,
        max_pop_size = 20,
        max_gen = 500,
        tourn_size = 5;

    double cross_rate = 0.95,
           mut_rate = 0.05;

    bool use_elitism = true;

    vector <Individual*> population;

    vector< vector<double> > dataset_train;
    vector< vector<double> > dataset_test;

    ifstream input_train(argv[1]), input_test(argv[2]);

    // cout << "Individual max size: "; cin >> ind_max_size;
    // cout << "Initial pop. size: "; cin >> init_pop_size;
    // cout << "Maximum pop. size: "; cin >> max_pop_size;
    // cout << "Maximum number of gen: "; cin >> max_gen;
    // cout << "Tournament size: "; cin >> tourn_size;
    // cout << "Crossover rate: "; cin >> cross_rate;
    // cout << "Mutation rate: "; cin >> mut_rate;


    read_CSV(dataset_train, dataset_test, input_train, input_test);

    for (int i = 0; i < max_pop_size; ++i){
        population.push_back(new Individual);

        // population[i]->printExpression(population[i]->genotype);

        // cout << "\nRoot value: \t" << population[i]->genotype->node_value << endl;
        // cout << "isOperator: \t" << population[i]->genotype->isOperator() << endl;
        // cout << "isVariable: \t" << population[i]->genotype->isVariable() << endl;
        // cout << "isTerminal: \t" << population[i]->genotype->isTerminal() << endl;
        cout << endl;

        delete population[i];
    }

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;z

    return 0;
}

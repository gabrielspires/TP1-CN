#include "Individual.cpp"

// #include "dependencies.h"
#include "functions.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    int num_of_var;
    vector <Individual*> population, new_population;

    vector< vector<double> > dataset_train;
    vector< vector<double> > dataset_test;

    ifstream input_train(argv[1]),
             input_test(argv[2]);

    read_CSV(dataset_train, input_train);
    read_CSV(dataset_test, input_test);

    num_of_var = dataset_train[0].size() - 1;


    // Individual *teste = new Individual(num_of_var);

    // postorder(teste->genotype, 4);
    // teste->printExpression(teste->genotype);
    generate_population(population, num_of_var);
    calc_fitness(population, dataset_train, num_of_var);

    select(population);
    select(population);
    select(population);
    
    // evolve(population, new_population);


    // for(int j=0; j < dataset_train[0].size()-1; j++) cout << "x" << j+1 << ":" << dataset_train[40][j] << " "; cout << endl;

    // cout << "Y = " << dataset_train[0][dataset_train[0].size()-1] << endl;
    
    //Calculo do Fitness de cada indivíduo

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;

    //Free population from memory
    for (int i = 0; i < population.size(); i++){
        delete population[i];
    }
    for (int i = 0; i < new_population.size(); i++){
        delete new_population[i];
    }

    return 0;
}

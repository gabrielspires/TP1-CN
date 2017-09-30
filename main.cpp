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

    generate_population(population, num_of_var);
    calc_fitness(population, dataset_train, num_of_var);

    //----------------------------------------------
    

    // Tree* temp_tree;
    // Individual *teste = new Individual(num_of_var);

        // population[i] = teste;

        // teste->genotype = new Tree(true, num_of_var);
        // teste->genotype->node_value = "+";

        // teste->genotype->left = new Tree(num_of_var);
        // teste->genotype->left->node_value = "*";

        // teste->genotype->left->left = new Tree(num_of_var);
        // teste->genotype->left->left->node_value = "x4";
        // teste->genotype->left->right = new Tree(num_of_var);
        // teste->genotype->left->right->node_value = "x7";

        // teste->genotype->right = new Tree(num_of_var);
        // teste->genotype->right->node_value = "cos";
        // teste->genotype->right->right = new Tree(num_of_var);
        // teste->genotype->right->right->node_value = "x7";

        // postorder(teste->genotype, 0);
        // cout << "MAXDEPTH: " << teste->maxDepth(teste->genotype) << endl;
        // cout << "===================" << endl;
        // mutate(teste);
        // postorder(teste->genotype, 0);

    // Individual *teste2 = new Individual(num_of_var);

    //     // population[i] = teste;

    //     teste2->genotype = new Tree(true, num_of_var);
    //     teste2->genotype->node_value = "+";

    //     teste2->genotype->left = new Tree(num_of_var);
    //     teste2->genotype->left->node_value = "*";

    //     teste2->genotype->left->left = new Tree(num_of_var);
    //     teste2->genotype->left->left->node_value = "30";
    //     teste2->genotype->left->right = new Tree(num_of_var);
    //     teste2->genotype->left->right->node_value = "12";

    //     teste2->genotype->right = new Tree(num_of_var);
    //     teste2->genotype->right->node_value = "sin";
    //     teste2->genotype->right->right = new Tree(num_of_var);
    //     teste2->genotype->right->right->node_value = "x3";

    //     postorder(teste2->genotype, 0);
    //     cout << "MAXDEPTH: " << teste2->maxDepth(teste2->genotype) << endl;
    //     cout << "===================" << endl;


    //     temp_tree = teste2->genotype->right;
    //     teste2->genotype->right = teste->genotype->right;
    //     teste->genotype->right = temp_tree;


    //     postorder(teste->genotype, 0);
    //     cout << "===================" << endl;
    //     postorder(teste2->genotype, 0);
    //     cout << "===================" << endl;
    cout << "PopSize: " << population.size() << endl;
    cout << "NewPopSize: " << new_population.size() << endl;
    // evolve(population, new_population);
    new_population.push_back(population[0]);
    new_population.push_back(population[1]);
    cout << "PopSize: " << population.size() << endl;
    cout << "NewPopSize: " << new_population.size() << endl;

    postorder(population[1]->genotype, 0);

    // calc_fitness(new_population, dataset_train, num_of_var);


    // for(int j=0; j < dataset_train[0].size()-1; j++) cout << "x" << j+1 << ":" << dataset_train[40][j] << " "; cout << endl;

    // cout << "Y = " << dataset_train[0][dataset_train[0].size()-1] << endl;
    
    //Calculo do Fitness de cada indivíduo

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;

    //Free population from memory
    for (int i = 0; i < population.size(); i++){
        delete population[i];
    }
    // for (int i = 0; i < new_population.size(); i++){
    //     delete new_population[i];
    // }

        return 0;
}

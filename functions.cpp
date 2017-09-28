#include "functions.h"
#include "dependencies.h"
#include "Individual.cpp"

void read_CSV(vector< vector<double> > &dataset, ifstream &input){
    string line, cell;
    double cell_value;
    int i = 0;

    while(getline(input, line, '\n')){
        vector<double> lineVector;
        dataset.push_back(lineVector);

        stringstream line_stream(line);

        while(getline(line_stream, cell, ',')){
            stringstream cell_stream(cell);
            cell_stream >> cell_value;
            dataset[i].push_back(cell_value);
        }
        i++;
    }
    input.close();
}

void generate_population(vector <Individual*> &population, int num_of_var){
    for (int i = 0; i < init_pop_size; i++){
        population.push_back(new Individual(num_of_var));
    }
}

void calc_fitness(vector <Individual*> &population, vector< vector<double> > dataset_train, int num_of_var){
    double mean_squared_error;
    double fit_med = 0;

    for (int i = 0; i < init_pop_size; i++){
        mean_squared_error = 0;
        for (int j = 0; j < dataset_train.size(); j++){
            mean_squared_error += pow(population[i]->genotype->evaluate(population[i]->genotype, dataset_train[j]) - dataset_train[j][dataset_train[j].size()-1], 2);
        }

        population[i]->fitness = sqrt(mean_squared_error/dataset_train.size());
cout << "Fitness " << i << ": " << population[i]->fitness << endl;
fit_med += sqrt(mean_squared_error/dataset_train.size());

        // cout << "Resultado: " << population[i]->genotype->evaluate(population[i]->genotype, dataset_train[40]) << " Expressão: ";
        // population[i]->printExpression(population[i]->genotype);
        // cout << endl << endl;
    }

cout << "Fitness media: " << fit_med/20 << endl;
}

//##############################################//
//Select the best of X individuals by tournament
Individual *select(vector <Individual*> &population){
    int best_individual_index = 0, rand_index = 0, i= 0;
    double best_individual_fitness = (1.0/0.0); //INF
    vector<int> v;
    Individual *selected_individual;

    if (population.empty()) return selected_individual;

    if (population.size() < tourn_size)
        i = tourn_size - population.size();

    for (i; i < tourn_size; i++){
        //Escolhe um índice aleatório e continua
        //escolhendo caso o indivíduo não possa ser escolhido
        do{
            rand_index = rand()%population.size();
        }while(population[rand_index]->can_participate == false || find(v.begin(), v.end(), rand_index) != v.end());
        v.push_back(rand_index);

        cout << "Selected Individual #" << rand_index << " with fitness of: " << population[rand_index]->fitness << endl;
        // cout << population[rand_index]->fitness << " " << best_individual_fitness;

        if (population[rand_index]->fitness < best_individual_fitness){
            best_individual_index = rand_index;
            best_individual_fitness = population[rand_index]->fitness;
        }
    }
    cout << "Winner Individual is: #" << best_individual_index << endl;
    
    //Marca o indivíduo para não ser mais usado em torneios
    population[best_individual_index]->can_participate = false;
    selected_individual = population[best_individual_index];
    population.erase(population.begin() + best_individual_index);

    return selected_individual;
}

//###################################################
//Picks a random node from the genotype of the parent
Tree *select_random_node(Tree *parent_genotype){
    double selection_chance = (rand()%10)/10;

    if(parent_genotype){
        if(selection_chance <= 0.3) return parent_genotype;
        select_random_node(parent_genotype->left);
        select_random_node(parent_genotype->right);
    }
    return parent_genotype;
}

//Combine DNA from both parents to create a new individual
void crossover(Individual parent1, Individual parent2, vector <Individual*> *new_population){
    Individual *child1 = NULL, *child2 = NULL;
    Tree *temp_node1, *temp_node2, *aux_node;
    //Selecionar um nó aleatorio da arvore
    //Trocar nó ou então sub-arvore
    //Retornar novo individuo

    // child1 = parent1;

    temp_node1 = select_random_node(parent1.genotype);
    temp_node2 = select_random_node(parent2.genotype);

    aux_node = temp_node1;
    temp_node1 = temp_node2;
    temp_node2 = aux_node;

    /*
        NÃO SEI COMO FAZ PRA TROCAR OS NÓS
        PRECISO CRIAR UM FILHO PRA NAO MODIFICAR OS PAIS
        MUTAR SÓ O FILHO

        VERIFICAR SE TA TROCANDO OPERADOR COM OPERADOR, ETC
        TA TUDO ERRADO ESSA BOSTA, ARRUMA AI CARA!!!
        ADICIONAR O GLOBAL ELITE
    */

    new_population->push_back(child1);
    new_population->push_back(child2);
}

//Mutate the DNA from the child to generate diversity
Individual *mutate(Individual *child){

}

void evolve(vector <Individual*> &population, vector <Individual*> &new_population){
    Individual *parent1, *parent2, *child;

    for (int i = 0; i < max_gen; i++){
        parent1 = select(population);
        parent2 = select(population);

        if((double(rand()%10)/10) <= 0.9){
            // crossover(parent1, parent2, new_population);
            // mutate(child);
        }
        else{
            // mutate(parent1);
            // mutate(parent2);
        }

        //Add the child to the new population
        new_population.push_back(child);
    }
}
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

    for (int i = 0; i < population.size(); i++){
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

cout << "Fitness media: " << fit_med/init_pop_size << endl;
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

    for (; i < tourn_size; i++){
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
    // delete population[best_individual_index];
    population.erase(population.begin() + best_individual_index);

    return selected_individual;
}

//###################################################
//Picks a random node from the genotype of the parent
Tree *select_random_node(Tree *parent_genotype, int rand_node_number){
    Tree *return_node = NULL;
    // cout << rand_node_number << endl;
    // cout << "node atual:" << parent_genotype->node_value << " : " << parent_genotype->number << " rand_node_number: " << rand_node_number << endl;
    if (parent_genotype->number == rand_node_number){
        return parent_genotype;
    }

    if (parent_genotype->left && return_node == NULL) return_node = select_random_node(parent_genotype->left, rand_node_number);
    if (parent_genotype->right && return_node == NULL) return_node = select_random_node(parent_genotype->right, rand_node_number);
    return return_node;
}

void swap_node(Tree &node1, Tree &node2){
    Tree aux_node = node1; 
    node1 = node2;
    node2 = aux_node;
}

//Combine DNA from both parents to create a new individual
void crossover(Individual *parent1, Individual *parent2, vector <Individual*> &new_population){
    Tree *temp_node1 = NULL, *temp_node2 = NULL;

    temp_node1 = select_random_node(parent1->genotype, rand()%parent1->size(parent1->genotype));
    temp_node2 = select_random_node(parent2->genotype, rand()%parent2->size(parent2->genotype));
    
    swap_node(*temp_node1, *temp_node2);
    parent1->numerate_nodes(parent1->genotype, "reset");
    parent2->numerate_nodes(parent2->genotype, "reset");

    /*
        ADICIONAR O GLOBAL ELITE
    */

    new_population.push_back(parent1);
    new_population.push_back(parent2);
}

//Mutate the DNA from the child to generate diversity
void mutate(Individual *indiv, vector <Individual*> &new_population){
    Tree *node_to_mutate = NULL;
    do{
        node_to_mutate = select_random_node(indiv->genotype, rand()%indiv->size(indiv->genotype));
    }while(!node_to_mutate);

    if (node_to_mutate->isOperator()) node_to_mutate->generateOperator();
    if (node_to_mutate->isVariable()) node_to_mutate->generateVariable();
    if (node_to_mutate->isTerminal()) node_to_mutate->generateTerminal();

    new_population.push_back(indiv);
}

void keep_the_elite(vector <Individual*> &population, vector <Individual*> &new_population){
    double best_fitness = (1.0/0.0); //INF
    int elite_index;

    for (int i = 0; i < population.size(); ++i){
        if (population[i]->fitness < best_fitness){
            best_fitness = population[i]->fitness;
            elite_index = i;
        }
    }
                                                        //excluir o elite!?!??!?!?!?!?
    new_population.push_back(population[elite_index]);
}

void evolve(vector <Individual*> &population, vector <Individual*> &new_population){
    Individual *parent1, *parent2, *child;

    // keep_the_elite(population, new_population);

    cout << init_pop_size << " - " << population.size() << " - " << new_population.size() << endl;

                                                                        //problema no init_pop_size/2
    for (int i = 0; i < init_pop_size/2 /*&& !population.empty()*/; i++){

        if((double(rand()%100)/100) <= cross_rate){
            cout << "\tCROSSOVER" << endl;
            parent1 = select(population); //Tournament
            parent2 = select(population); //Tournament
            crossover(parent1, parent2, new_population);
            // mutate(child);
        }
        else{
            cout << "\tMUTATION" << endl;
            parent1 = select(population); //Tournament
            mutate(parent1, new_population);
            // mutate(parent2);
        }

        //Add the child to the new population
    }
}

void postorder(Tree* p, int indent){
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << setw(indent) << ' ';
        cout << "(" << p->number << ")" << p->node_value << "\n ";
        if(p->left) {
            cout << setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}
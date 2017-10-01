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
    
    for (int i = 0; i < population.size(); i++){
        mean_squared_error = 0;
        for (int j = 0; j < dataset_train.size(); j++){
            mean_squared_error += pow(population[i]->genotype->evaluate(population[i]->genotype, dataset_train[j]) - dataset_train[j][dataset_train[j].size()-1], 2);
        }

        population[i]->can_participate = true; //Reset individual to participate in tournament
        population[i]->fitness = sqrt(mean_squared_error/dataset_train.size());
        // cout << "Fitness " << i << ": " << population[i]->fitness << endl;

        // cout << "Resultado: " << population[i]->genotype->evaluate(population[i]->genotype, dataset_train[40]) << " Expressão: ";
        // population[i]->printExpression(population[i]->genotype);
        // cout << endl << endl;
    }
}

//##############################################//
//Select the best of X individuals by tournament
Individual *select(vector <Individual*> &population){
    std::vector<int> selected_indexes;
    int index, i = 0, best_index;
    double best_fitness = (1.0/0.0);
    Individual *tourn_winner;

    //Select random indexes from the population
    if (population.size() < tourn_size) i = tourn_size -population.size();
    while(i < tourn_size){
        index = rand()%population.size();
        if(find(begin(selected_indexes), end(selected_indexes), index) == selected_indexes.end()){
        // cout << index << endl;
            i++;
            selected_indexes.push_back(index);
        }
    }

    for (int j = 0; j < selected_indexes.size(); j++){
        if (population[selected_indexes[j]]->fitness < best_fitness){
            best_fitness = population[selected_indexes[j]]->fitness;
            best_index = selected_indexes[j];
        }
    }
    tourn_winner = population[best_index];

    population.erase(population.begin() + best_index);
    return tourn_winner;
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
    double prob;

    temp_node1 = select_random_node(parent1->genotype, rand()%parent1->size(parent1->genotype));
    temp_node2 = select_random_node(parent2->genotype, rand()%parent2->size(parent2->genotype));
    
    swap_node(*temp_node1, *temp_node2);
    parent1->numerate_nodes(parent1->genotype, "reset");
    parent2->numerate_nodes(parent2->genotype, "reset");

    prob = (rand()%100)/100.0;

    if(prob <= mut_rate){
        // cout << "\tMUTATION" << endl;
        mutate(parent1, new_population);
        mutate(parent2, new_population);
    }


    new_population.push_back(parent1);
    new_population.push_back(parent2);
}

//Mutate the DNA from the child to generate diversity
void mutate(Individual *indiv, vector <Individual*> &new_population){
    Tree *node_to_mutate = NULL;
    // do{
        node_to_mutate = select_random_node(indiv->genotype, rand()%indiv->size(indiv->genotype));
    // }while(!node_to_mutate);

    // if (node_to_mutate->isOperator()) node_to_mutate->generateOperator();
    // if (node_to_mutate->isVariable()) node_to_mutate->generateVariable();
    // if (node_to_mutate->isTerminal()) node_to_mutate->generateTerminal();
    node_to_mutate->left = NULL;
    node_to_mutate->right = NULL;
    indiv->generateGenotype(node_to_mutate);
    indiv->numerate_nodes(indiv->genotype, "reset");
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

    // Individual *elite = new Individual(*population[elite_index]);
                                                        //excluir o elite!?!??!?!?!?!?
    new_population.push_back(population[elite_index]);
    // new_population.push_back(elite);
    population.erase(population.begin() + elite_index);
}

void evolve(vector <Individual*> &population, vector <Individual*> &new_population){
    Individual *parent1, *parent2, *child;
    double prob;

    keep_the_elite(population, new_population);

    // cout << init_pop_size << " - " << population.size() << " - " << new_population.size() << endl;

                                                                        //problema no init_pop_size/2
    // for (int i = 0; i < init_pop_size /*&& !population.empty()*/; i++){
    while(population.size() > 0){
        prob = (rand()%100)/100.0;
        if(prob <= cross_rate && population.size() > 1){
            // cout << "\tCROSSOVER" << endl;
            parent1 = select(population); //Tournament
            parent2 = select(population); //Tournament
            crossover(parent1, parent2, new_population);
        }else{ //Reproduction
            parent1 = select(population); //Tournament
            new_population.push_back(parent1);
        }
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
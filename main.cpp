#include "dependencies.h"
#include "Tree.cpp"
#include "Individual.cpp"

int main(int argc, char const *argv[]){
    srand(time(NULL));
    
    int ind_max_size = 7,
        init_pop_size = 50,
        max_pop_size = 500,
        max_gen = 500,
        tourn_size = 5;

    double cross_rate = 0.95,
           mut_rate = 0.05;

    bool use_elitism = true;

    ifstream entrada;

    // readInput(&entrada, argv[1]);

    // for (int i = 0; i < 15; ++i){
        Individual *j = new Individual();

        j->inOrder(j->genotype);

	    cout << "\nRoot value: \t" << j->genotype->node_value << endl;
	    cout << "isOperator: \t" << j->genotype->isOperator() << endl;
	    cout << "isVariable: \t" << j->genotype->isVariable() << endl;
	    cout << "isTerminal: \t" << j->genotype->isTerminal() << endl;
	    cout << endl;

        delete j;
	// }

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;z

    return 0;
}

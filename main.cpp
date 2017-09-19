#include "dependencies.h"
#include "Tree.cpp"
#include "Individual.cpp"

int main(){
    srand(time(NULL));
    
    int ind_max_size = 7,
        init_pop_size = 50,
        max_pop_size = 500,
        max_gen = 500,
        tourn_size = 5;

    double cross_rate = 0.95,
           mut_rate = 0.05;

    bool use_elitism = true;


    // for (int i = 0; i < 15; ++i){
    	Tree *jooj = new Tree();
        jooj->left = new Tree();
        jooj->right = new Tree();

	    cout << "Node value: \t" << jooj->node_value << endl;
	    cout << "isOperand: \t" << jooj->isOperand() << endl;
	    cout << "isOVariable: \t" << jooj->isVariable() << endl;
	    cout << "isTerminal: \t" << jooj->isTerminal() << endl;
	    cout << endl;
	// }

    // cout << "# of OP: " << num_of_op << endl;
    // cout << "# of VAR: " << num_of_var << endl;

    Individual ind;
    ind.genotype = jooj;
    // ind.generateGenotype(jooj);
    ind.inOrder(ind.genotype);

    return 0;
}

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

    Tree jooj;
    cout << jooj.node_value << endl;
    cout << jooj.isOperand() << endl;

    return 0;
}
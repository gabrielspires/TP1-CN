#ifndef INDIVIDUAL_CPP
#define INDIVIDUAL_CPP

#include "Tree.cpp"

class Individual{
public:
    Individual(int num_of_var){
    	this->num_of_var = num_of_var;
        this->ind_size = 1;
        bool isRoot = true;
        this->genotype = new Tree(isRoot, num_of_var);
        this->generateGenotype(this->genotype);
    };
    ~Individual(){
        deleteTree(this->genotype);
        // delete this->genotype;
    };

    Tree *genotype;
    int ind_size;
    int num_of_var;

    void generateGenotype(Tree *node){
        // cout << "IND SIZE: " << this->ind_size << endl;
        if(this->ind_size >= 7 && !node->isOperator()) return;
        
        this->ind_size++;

        if (node->isOperator()){
            if(node->node_value != "cos" && node->node_value != "sin"){
                node->left = new Tree(num_of_var);
                node->right = new Tree(num_of_var);
                generateGenotype(node->left);
                generateGenotype(node->right);
            }
            else {
                int trig_param = rand()%10;

                node->right = new Tree(num_of_var);
                if(trig_param < 5)
                    node->right->generateVariable();
                else{
                    node->right->generateTerminal();
                }
            }
        }
        this->ind_size--;
    }

    // void generatePopulation(vector <Individual*> population, int max_pop_size){
    //     for (int i = 0; i < max_pop_size; i++){
    //         population.push_back(new Individual);
    //         population[i]->printExpression(population[i]->genotype);
    //     }
    // }

 //    double eval(Tree node, vector< vector<double> > data_set){
 //    	double result = 0;
 //    	stringstream node_terminal;

 //    	if (node.isOperator()){
 //    		if (node.node_value == "+"){
 //    			return node.left + node.right;
 //    		}
 //    	}
 //    	else if (node.isVariable()){
    		
 //    	}
 //    	else/* if (node.isTerminal())*/{
 //    		return result;
 //    	}
	// }
    
    void printExpression(Tree *node){
        if(node){
            if((node->left || node->right)) cout << "(";
            printExpression(node->left);
            cout << node->node_value << " ";
            printExpression(node->right);
            if((node->left || node->right)) cout << ")";
        }
    }

    // Tree node;
private:
    void deleteTree(Tree *node) {    
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
};

#endif //INDIVIDUAL_CPP
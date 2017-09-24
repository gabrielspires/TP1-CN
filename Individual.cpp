#ifndef INDIVIDUAL_CPP
#define INDIVIDUAL_CPP

#include "Tree.cpp"

class Individual{
public:
    Tree *genotype;
    int ind_size;
    int num_of_var;
    double fitness;
    bool can_participate; //If the individual got selected by a tournament

    Individual(int num_of_var){
    	this->can_participate = true;
    	this->fitness = 0.0;
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

    void generateGenotype(Tree *node){
        // cout << "IND SIZE: " << this->ind_size << endl;
        if(this->ind_size >= 7 && !node->isOperator()) return;
        
        this->ind_size++;

        if (node->isOperator()){
            if(node->node_value != "cos" && node->node_value != "sin"){
                node->left = new Tree(num_of_var);
                if (ind_size >=5) node->left->generateTerminal();
                
                node->right = new Tree(num_of_var);
                if (ind_size >=5) node->right->generateTerminal();
                
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
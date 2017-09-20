#ifndef TP1_INDIVIDUAL_
#define TP1_INDIVIDUAL_

#include "dependencies.h"
#include "Tree.cpp"

class Individual{
public:
    Individual(){
    	this->ind_size = 1;
    	bool isRoot = true;
    	this->genotype = new Tree(isRoot);
    	this->generateGenotype(this->genotype);
    };
    ~Individual(){
    };

    Tree *genotype;
	int ind_size;

    void generateGenotype(Tree *node){
    	cout << "IND SIZE: " << this->ind_size << endl;
    	if(this->ind_size >= 7 && !node->isOperator()) return;
    	
    	this->ind_size++;

    	if (node->isOperator()){
    		if(node->node_value != "cos" && node->node_value != "sin"){
    			node->left = new Tree();
    			node->right = new Tree();
    			generateGenotype(node->left);
    			generateGenotype(node->right);
    		}
    		else {
    			int trig_param = rand()%10;

				node->right = new Tree();
				if(trig_param < 5)
					node->right->generateVariable();
				else{
					node->right->generateTerminal();
				}
    		}
    	}
    	this->ind_size--;
    }

    //Terminar de gerar o individuo!!!!!!!!!!!!!!!!!!!!!
    void inOrder(Tree *node){
    	if(node){
    		if((node->left || node->right)) cout << "(";
			inOrder(node->left);
			cout << node->node_value << " ";
			inOrder(node->right);
			if((node->left || node->right)) cout << ")";
    	}
    }

    // Tree node;
private:
    
};

#endif //TP1_INDIVIDUAL_
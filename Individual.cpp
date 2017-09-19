#ifndef TP1_INDIVIDUAL_
#define TP1_INDIVIDUAL_

#include "dependencies.h"
#include "Tree.cpp"

class Individual{
public:
    Individual(){
    	ind_size = 0;
    };
    ~Individual(){
    };

    Tree *genotype;

    void generateGenotype(Tree *node){
    	cout << ind_size << endl;
    	cout << node->node_value << endl;
    	if(ind_size >= 7 || !node->isOperand()) return;
    	ind_size++;
    	if (node->isOperand()){
    		if(node->node_value != "cos" && node->node_value != "sin"){
    			node->left = new Tree();
    			generateGenotype(node->left);

    			node->right = new Tree();
    			generateGenotype(node->right);
    		}
    		else {
				node->left = new Tree();
    			generateGenotype(node->left);
    		}
    	}
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
	int ind_size;
    
};

#endif //TP1_INDIVIDUAL_
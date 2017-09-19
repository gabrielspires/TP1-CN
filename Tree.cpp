#ifndef TP1_TREE_
#define TP1_TREE_

#include "dependencies.h"


class Tree{
public:
    Tree(){ //Construtor, gera o nó da arvore
    	int node_type = rand()%3;

    	ostringstream terminal;
    	terminal << rand()%100;

    	if (node_type == 0)
    		this->node_value = operators[rand() % num_of_op];
    	else if (node_type == 1)
    		this->node_value = variables[rand() % num_of_var];
    	else
    		this->node_value = terminal.str();
    }

    bool isOperand(){
        for (int i = 0; i < num_of_op; ++i){
        	if (this->node_value == operators[i])
        		return true;
        }
        return false;
    }

    bool isVariable(){
        for (int i = 0; i < num_of_var; ++i){
        	if (this->node_value == variables[i])
        		return true;
        }
        return false;
    }

    bool isTerminal(){
        return (!this->isOperand() && !this->isVariable());
    }

    // ~Tree(){
    // }
    
    Tree *left, *right;
    string node_value;
    
    
private:
    
};

#endif //TP1_TREE_
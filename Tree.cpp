#ifndef TP1_TREE_
#define TP1_TREE_

#include "dependencies.h"


class Tree{
public:
    Tree(bool isRoot){
        double node_type = (rand()%100)/100.0;
        if(node_type <= 0.90) this->generateOperator();
        else if(node_type <= 0.93) this->generateVariable();
        else if(node_type <= 1.00) this->generateTerminal();

        this->left = this->right = NULL;
    }
    Tree(){
        double node_type = (rand()%100)/100.0;
        if(node_type <= 0.60) this->generateOperator();
        else if(node_type <= 0.80) this->generateVariable();
        else if(node_type <= 1.00) this->generateTerminal();
        
        this->left = this->right = NULL;
    }

    void generateOperator(){
        this->node_value = operators[rand() % num_of_op];
    }
    void generateVariable(){
        this->node_value = variables[rand() % num_of_var];
    }
    void generateTerminal(){
        ostringstream terminal;
        terminal << (rand()%(MAX_CONST+1))-(rand()%(MIN_CONST+1));
        this->node_value = terminal.str();
    }

    bool isOperator(){
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
        return (!this->isOperator() && !this->isVariable());
    }

    // ~Tree(){
    // }
    
    string node_value;
    Tree *left, *right;
    
    
private:
    
};

#endif //TP1_TREE_
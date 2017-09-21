#ifndef TREE_H
#define TREE_H

#include "dependencies.h"

class Tree{
public:
    string node_value;
    Tree *left, *right;
    int num_of_var;
    Tree(bool isRoot, int num_of_var){
    	this->num_of_var = num_of_var;
        double node_type = (rand()%100)/100.0;
        if(node_type <= 0.90) this->generateOperator();
        else if(node_type <= 0.93) this->generateVariable();
        else if(node_type <= 1.00) this->generateTerminal();

        this->left = this->right = NULL;
    }
    Tree(int num_of_var){
    	this->num_of_var = num_of_var;
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

    double evaluate(Tree *node, vector< vector<double> > data_set) const
	{
	    if (node->left != NULL && node->right != NULL)
	    {
	        if(node->node_value == "+"){
	            return node->left->evaluate(node->left, data_set) + right->evaluate(node->right, data_set);
	        // ############################################################################################################################
	            // remaining operators left as an exercise for the reader
	        // ....
	        }
	    }
	    // return data;
	}

    // ~Tree(){
    // }
    
    
    
private:
    
};

#endif //TP1_TREE_
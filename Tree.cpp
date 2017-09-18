#ifndef TP1_TREE_
#define TP1_TREE_

#include "dependencies.h"


class Tree{
public:
    Tree(){
    	this->node_value = operators[rand() % operators.size()];
    }

    bool isOperand(){
        if (this->node_value == "+" ||
        this->node_value == "-" ||
        this->node_value == "/" ||
        this->node_value == "*"){
            return true;
        }
        else{
            return false;
        }
    }
    
    // ~Tree(){
    // }
    
    Tree *left, *right;
    string node_value;
    
    
private:
    
};

#endif //TP1_TREE_
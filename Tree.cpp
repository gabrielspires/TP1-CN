#ifndef TP1_TREE_
#define TP1_TREE_

#include "dependencies.h"


class Tree{
public:
    Tree(){
    	this->node_value = operators[rand() % (sizeof(operators)/sizeof(string))];
    }

    bool isOperand(){
        switch(int(this->node_value[0])){
            case SUM:
            case SUB:
            case MUL:
            case DIV:
            case COS:
            case SIN:
                return true;
        };
        return false;
    }
    
    // ~Tree(){
    // }
    
    Tree *left, *right;
    string node_value;
    
    
private:
    
};

#endif //TP1_TREE_
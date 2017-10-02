#ifndef INDIVIDUAL_CPP
#define INDIVIDUAL_CPP

#include "Tree.cpp"

class Individual{
public:
    Tree *genotype;
    int ind_size, num_of_var, depth, node_number;
    double fitness;
    bool can_participate; //If the individual got selected by a tournament

    Individual(int num_of_var){
    	this->node_number = 0;
    	this->can_participate = true;
    	this->fitness = 0.0;
    	this->num_of_var = num_of_var;
        this->ind_size = 1;
        bool isRoot = true;
        this->genotype = new Tree(isRoot, num_of_var);
        this->generateGenotype(this->genotype);
        this->depth = this->maxDepth(this->genotype);
        this->numerate_nodes(this->genotype);
    };
    ~Individual(){
        deleteTree(this->genotype);
        // delete this->genotype;
    };

    Individual(const Individual &obj){ //Deep copy constructor
    	this->node_number = obj.node_number;
    	this->can_participate = obj.can_participate;
    	this->fitness = obj.fitness;
    	this->num_of_var = obj.num_of_var;
        this->ind_size = obj.ind_size;
        this->depth = obj.depth;
        this->genotype = new Tree(*obj.genotype);
    }

    void generateGenotype(Tree *node){
        // cout << "IND SIZE: " << this->ind_size << endl;
        if(this->ind_size >= ind_max_size && !node->isOperator()) return;
        
        this->ind_size++;

        if (node->isOperator()){
            if(node->node_value != "cos" && node->node_value != "sin"){
                node->left = new Tree(num_of_var);
                node->right = new Tree(num_of_var);
                
                if (ind_size >=ind_max_size){
                	node->left->generateTerminal();
                	node->right->generateTerminal();
                }
                
                generateGenotype(node->left);
                generateGenotype(node->right);
            }
            else {
                int trig_param = rand()%10;

                node->right = new Tree(num_of_var);
                if(trig_param < 5){
                    node->right->generateVariable();
                }
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

    int maxDepth(Tree *genotype){
		if(genotype){ return 1 + max( maxDepth(genotype->left), maxDepth(genotype->right)); }
		return 0;
	}

	int size(Tree *node) const{
	    if(node == NULL) { //This node doesn't exist. Therefore there are no nodes in this 'subtree'
	        return 0;
	    } else { //Add the size of the left and right trees, then add 1 (which is the current node)
	        return size(node->left) + size(node->right) + 1;
	    }
	}

	void numerate_nodes(Tree *node){
	    if(node){
	    	node->number = this->node_number;
	    	this->node_number++;
            numerate_nodes(node->left);
            numerate_nodes(node->right);
        }
	}

	void numerate_nodes(Tree *node, string reset){
	    if (reset == "reset"){
	    	this->node_number = 0;
	    	numerate_nodes(node);
	    }
	}

    // Tree node;
    void deleteTree(Tree *node) {    
        if (!node) return;
        if(node->left) deleteTree(node->left);
        if(node->right) deleteTree(node->right);

        delete node;
    }
private:
};

#endif //INDIVIDUAL_CPP
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
        deleteTree(this->genotype);
        // delete this->genotype;
    };

    Tree *genotype;
    int ind_size;

    void generateGenotype(Tree *node){
        // cout << "IND SIZE: " << this->ind_size << endl;
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

    // void generatePopulation(vector <Individual*> population, int max_pop_size){
    //     for (int i = 0; i < max_pop_size; i++){
    //         population.push_back(new Individual);
    //         population[i]->printExpression(population[i]->genotype);
    //     }
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

#endif //TP1_INDIVIDUAL_
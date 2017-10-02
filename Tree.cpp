#ifndef TREE_H
#define TREE_H

#include "dependencies.h"

class Tree{
public:
    string node_value;
    Tree *left, *right;
    int num_of_var, number;

    Tree(bool isRoot, int num_of_var){
    	// this->node_number = 0;
    	this->num_of_var = num_of_var;
        // double node_type = (rand()%100)/100.0;
        /*if(node_type <= 0.90) */ this->generateOperator(isRoot);
        // else if(node_type <= 0.93) this->generateVariable();
        // else if(node_type <= 1.00) this->generateTerminal();

        this->left = this->right = NULL;
    }
    Tree(int num_of_var){
    	// this->node_number = 0;
    	this->num_of_var = num_of_var;
        double node_type = (rand()%100)/100.0;
        if(node_type <= 0.60) this->generateOperator();
        else if(node_type <= 0.80) this->generateVariable();
        else if(node_type <= 1.00) this->generateTerminal();
        
        this->left = this->right = NULL;
    }
    Tree(const Tree &obj){
    	this->node_value = obj.node_value;
    	this->num_of_var = obj.num_of_var;
    	this->number = obj.number;
    	this->left = this->right = NULL;
    
    	if(obj.left)
    		left = new Tree(*obj.left);
        if(obj.right)
            right = new Tree(*obj.right);
    }

    void generateOperator(bool isRoot){
    	this->node_value = operators[rand() % (num_of_op-2)];
    }
    void generateOperator(){
    	this->node_value = operators[rand() % num_of_op];
    }
    void generateVariable(){
        this->node_value = variables[rand() % num_of_var];
    }
    void generateTerminal(){
    	uniform_real_distribution<double> unif(MIN_CONST, MAX_CONST);
	    std::random_device rand_dev;          // Use random_device to get a random seed.
	    std::mt19937 rand_engine(rand_dev()); // mt19937 is a good pseudo-random number 
	                                          // generator.

        ostringstream terminal;
        terminal << /*double(rand()%(MAX_CONST+1))-(rand()%(MIN_CONST+1))**/unif(rand_engine);
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

    double evaluate(Tree *node, vector<double> data_set){
	    if (node->left != NULL && node->right != NULL){ //Binary operators
	        if(node->node_value == "+")
	            return node->left->evaluate(node->left, data_set) + node->right->evaluate(node->right, data_set);
            else if(node->node_value == "-")
                return node->left->evaluate(node->left, data_set) - node->right->evaluate(node->right, data_set);
            else if(node->node_value == "*")
                return node->left->evaluate(node->left, data_set) * node->right->evaluate(node->right, data_set);
            else if(node->node_value == "/"){
                double eval_left, eval_right;
                eval_left = node->left->evaluate(node->left, data_set);
                eval_right = node->right->evaluate(node->right, data_set);

                if(eval_right == 0) //Divisao por zero (retorna sempre 1)
                    return 0;
                else
                    return eval_left / eval_right;
            }
	    }
        else if (node->left == NULL && node->right != NULL){ //Trigonometric operators
            if (node->node_value == "cos"){
                return cos(node->right->evaluate(node->right, data_set));
            }
            else if (node->node_value == "sin"){
                return sin(node->right->evaluate(node->right, data_set));   
            }
        }
        else if(node->isVariable()){ //SUBSTITUI AS VARIÁVEIS PELA ENTRADA DO DATA_SET
            int i;

            //Procura qual variavel é (x1, x2, ...) e retorna seu índice
            for (i = 0; i < this->num_of_var; ++i){
                if (node->node_value == variables[i])
                    break;
                else if (i == this->num_of_var - 1){ //Se a variável n tiver no "dicionário" da um erro
                    cout << "ERRO!! VARIAVEL NAO ENCONTRADA" << endl;
                }
            }
            // stringstream variable; //converte o double do dataset em string pra arvore
            // variable << 
            return data_set[i];
            // variable >> node->node_value;
        }
        //Se n entrar nos if's acima é pq o nó é uma constante (terminal)
        //daí retorna o valor double do terminal pra fazer os devidos cálculos
        stringstream terminal;
        double terminal_value;
        terminal << node->node_value;
        terminal >> terminal_value;

        return terminal_value;
	}

    ~Tree(){
    }
    
    
    
private:
    
};

#endif //TP1_TREE_
#include "tree_old.h"
#include "TreeClass.cpp"

int main(int argc, char const *argv[]){
    int init_pop,
        max_pop,
        ind_max_size,
        gen_max,
        tourn_size;
    double cross_rate, mut_rate;
    bool elitism;

	string postfix = "ab*cd*-ef*/";
	string postfix2 = "512+x*+3-";
	string postfix3 = "359+2*+";

	Tree *arvore = constructTree(postfix3);
	cout << "A expressao gerada foi ";
    inorder(arvore);
    cout << endl;
    return 0;
}

/*

Gerar os individuos criando árvores

Os indivíduos são expressões (3x² + 2x + 1):
	São gerados com árvores onde as folhas 
	são operandos e os demais nós são os
	operadores.
	A expressão deve ter idealmente 7 simbolos.

Gerar a população inicial mais simples:
	Tentar achar a solução com funções
	mais simples no começo, e depois
	ir complicando as funções.

Começar com operadores simples (sem seno, coseno, etc):
	Caso operadores muito complicados ou
	muitos operadores diferentes sejam
	usados no inicio, é capaz que a
	solução seja prejudicada.

Utilizar scanf/cin para mudança dos parametros:
	Parametros "hardcoded" são mais
	dificeis de mudar pra testes, entao
	é melhor ler eles na execução.
	
*/
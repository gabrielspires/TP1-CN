#include <iostream>
#include "tree.h"

int main(int argc, char const *argv[]){
	char postfix[] = "ab+ef*g*-";
    et* arvore = constructTree(postfix);
    cout << "infix expression is \n";
    inorder(arvore);
    cout << 1.55E+06 * 10 << endl;
    return 0;
}

/*

Os indivíduos são funções (3x² + 2x + 1):
	São gerados com árvores onde as folhas 
	são operandos e os demais nós são os
	operadores.

Gerar a população inicial mais simples:
	Tentar achar a solução com funções
	mais simples no começo, e depois
	ir complicando as funções.

Começar com operadores simples (sem seno, coseno, etc):
	Caso operadores muito complicados ou
	muitos operadores diferentes sejam
	usados no inicio, é capaz que a
	solução seja prejudicada.

Utilizar cin >> para mudança dos parametros:
	Parametros "hardcoded" são mais
	dificeis de mudar pra testes.
	
*/
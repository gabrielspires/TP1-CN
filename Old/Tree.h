#include "dependencies.h"

class Tree{
public:
	Tree *left, *right;
	string nodeValue;

	Tree();
	~Tree();
	Tree newnode();
	string readTree(); //inOrder
	Tree createTree();


};
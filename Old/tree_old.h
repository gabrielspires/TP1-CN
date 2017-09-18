// C++ program for expression tree
#include <iostream>
#include <cstdio>

#include <stack>

using namespace std;
 
// An expression tree node
struct Tree{
    char value;
    Tree *left, *right;
};
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c);
 
// Utility function to do inorder traversal
void inorder(Tree *t);

// A utility function to create a new node
Tree* newNode(int v);
 
// Returns root of constructed tree for given
// postfix expression
Tree* constructTree(string postfix);
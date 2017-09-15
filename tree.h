// C++ program for expression tree
#include<bits/stdc++.h>
using namespace std;
 
// An expression tree node
struct et{
    char value;
    et* left, *right;
};
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c);
 
// Utility function to do inorder traversal
void inorder(et *t);
// A utility function to create a new node
et* newNode(int v);
 
// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[]);
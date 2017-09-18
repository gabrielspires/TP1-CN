#include "tree_old.h"

// A utility function to check if 'c'
// is an operator
bool isOperator(char c){
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;
    return false;
}

// Utility function to do inorder traversal
void inorder(Tree *t){
    if(t){
        if((t->left || t->right)) cout << "(";
        inorder(t->left);
        printf("%c", t->value);
        inorder(t->right);
        if((t->left || t->right)) cout << ")";
    }
}

// A utility function to create a new node
Tree* newNode(int v){
    Tree *temp = new Tree;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

// RTreeurns root of constructed tree for given
// postfix expression
Tree* constructTree(string postfix){
    stack<Tree *> st;
    Tree *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<postfix.size(); i++){
        // If operand, simply push into stack
        if (!isOperator(postfix[i])){
            t = newNode(postfix[i]);
            st.push(t);
        }
        else{ // operator
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            // make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    // only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
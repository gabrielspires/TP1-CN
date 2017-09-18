#ifndef TP1_TREE_
#define TP1_TREE_

class Tree{
public:
    Tree();
    Tree(Tree &&) = default;
    Tree(const Tree &) = default;
    Tree &operator=(Tree &&) = default;
    Tree &operator=(const Tree &) = default;
    ~Tree();

    Tree *left, *right;
    

    
private:
    
};

Tree::Tree(){
}

Tree::~Tree(){
}

#endif //TP1_TREE_
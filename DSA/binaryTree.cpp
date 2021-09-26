#include<iostream>

class tree {
    int data;
    tree *left, *right;
    
    public:
    tree(int data)
        :this.data(data) : left->NULL : right->NULL
    {

    }

    ~tree(){ delete tree; }
};
//incomplete..
tree *insertNode(tree* root) {
    int data;
    std::cout << "\nEnter data to be entered in the Tree(-1 for no data): ";
    std::cin >> data;

    if(data==-1){ return NULL; }

    tree *node = new tree(data);

    std::cout << "\nEnter left child of: " << data;
    node->left=insertNode(root);

    std::cout << "\nEnter right child of: " << data;
    root->right=insertNode(root);

    return root;
}

int main() {

    tree *root=NULL;

    root=insertNode(root);
      

    return 0;
}
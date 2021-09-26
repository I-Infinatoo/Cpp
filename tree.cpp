#include<iostream>
using namespace std;

class tree{
public:
    int nodeData;

    //for children
    int numberOfChilds;
    struct tree **child_ptr;

} *newNode=NULL;

tree* initialize() {
    struct tree *node;
    
    node->nodeData=0;

    cout << "Enter number of children: ";
    cin >> node->numberOfChilds;
    
    //creating N number of nodes
    node->child_ptr = new tree*[node->numberOfChilds];
    //initializing each child with null
    for(int i=0; i<node->numberOfChilds; i++) {
        node->child_ptr[i]=NULL;

    }

    return node;
}

void insert() {
    
}

int main() {



    return 0;
}
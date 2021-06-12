#include<iostream>
#include<vector>
#include<map>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};


//create a new node
struct tree* create(int data){
    
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

struct tree* insertTree(struct tree *root, int data) {


    //if tree is empty then create new one and return the node
    if(!root) {
        root = create(data);
        return root;
    }

    if(data <= root->data) {
        root->left = insertTree(root->left, data);
    } else {
        root->right = insertTree(root->right, data);
    }

    return root;
}

//inorder display
void dispInorder(struct tree *root){

    if(!root) {
        return;
    }
    
    dispInorder(root->left);
    std::cout << root->data << " " ;
    dispInorder(root->right);
}

/**
 *          1
 *      2       3
 *        4       6
 *              5   7
 *                    8 
 *  
 * left view---> 1 2 4 5 8
 * 
 *      root left right
**/


/**
 * This is not an optimised approch as it is traversing each and every node of the tree. O(n) ---> n is the number of nodes in the tree.
 * 
 * Instead of this approch we can use level order traversal
**/

//using preorder traversal  
static std::map<int, bool>visited;
static std::vector<int> result;
static int lvl=0;

void dispLeftView(struct tree *root, int lvl) {
    
    //if node is empty then return simply 
    if(!root) {
        return;
    }
    
    if(!visited[lvl]) {
        result.push_back(root->data);
        visited[lvl] = true;
    }
    
    
    dispLeftView(root->left, lvl+1);
    
    dispLeftView(root->right,  lvl+1);
    
}

void dispRightView(struct tree *root, int lvl){
    if(!root) {
        return;
    }

    if(!visited[lvl]) {
        result.push_back(root->data);
        visited[lvl] = true;
    }
    
    dispLeftView(root->right,  lvl+1);

    dispLeftView(root->left, lvl+1);
}


int main() {
    
    struct tree *root = NULL;

    //creating the BST
    root = insertTree(root, 5);
    root = insertTree(root, 3);
    root = insertTree(root, 8);
    root = insertTree(root, 4);
    root = insertTree(root, 6);
    root = insertTree(root, 9);
    root = insertTree(root, 10);

    /**
     *              5
     *           3     8
     *             4  6  9
     *                     10
    **/

    std::cout << "\nInOrder Display:\t";
    dispInorder(root);


    std::cout << "\nLeft View:\t" ;
    
    dispLeftView(root, lvl);

    //resulut should be 5 3 4 10
    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << " " ;
    }

    return 0;
} 
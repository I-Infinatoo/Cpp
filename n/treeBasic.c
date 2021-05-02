#include <stdio.h>
#include <malloc.h>

struct tree {
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *ins(struct tree *root, int val) {
    
    struct tree *p;                     // creating a local pointer to keep root safe

    if ( root == NULL ) {              // If tree is empty then it will create a root node
        printf("\nBranch is empty.");
        p = (struct tree *) malloc( sizeof(struct tree ));
        
        p->value = val;
        p->left = p->right = NULL;

        return p;
    } else {                            // if tree is not empty

        
        if ( root->value > val) {       //if new val is smaller then parent then move to left sub tree
            printf("\nMoving to left sub tree.");
            root->left = ins(root->left, val);
        
        } else {                        //if new val is greater then or equal to parent then move to right sub tree
            printf("\nMoving to right sub tree.");
            root->right = ins(root->right, val);
        }

    }

    return root;
}

void inorderShow (struct tree *root) {

    if (root == NULL) {
        return;

    } else {
        inorderShow(root->left);
        printf(" %d", root->value);
        inorderShow(root->right);
    }
}

void preorderShow (struct tree *root) {

    if (root == NULL) {
        return;

    } else {
        
        printf(" %d", root->value);
        preorderShow(root->left);
        preorderShow(root->right);
    }
}
void postorderShow (struct tree *root) {

    if (root == NULL) {
        return;

    } else {
        postorderShow(root->left);
        postorderShow(root->right);
        printf(" %d", root->value);
    }
}


// search function
int search ( struct tree* root, int data) {
    
    if ( root == NULL) {
        printf("\nEmpty tree");
        return 0;    
    } else if ( root->value == data ) { 
        return 1; 
    
    } else if ( root->value > data ) {
        return search (root->left, data);
    
    } else {
        return search (root->right, data);
    }
    
}


struct tree* minValue(struct tree* node) {  
  struct tree* current = node;                  
  
  while ( current->left != NULL) { 
    current = current->left; 
  } 
  return current; 
} 


struct tree* del ( struct tree* root, int data) {
    
    if( root == NULL) {                          //if empty tree
        return root;
    
    } else if( data < root->value ) {           //if value is in left sub-tree
        root->left = del(root->left, data);
   
    } else if ( data > root->value ) {          //if value is in right sub-tree
        root->right = del(root->right, data);
    
    } else {                                    //if found the data

        if (root->left == NULL && root->right == NULL) {        // if no child
            free(root);
            root = NULL;                        // to overcome with dangling pointer
            //return root;
        
        } else if (root->left == NULL) {        //if right child only
            struct tree* temp = root;           //making a copy of root
            root = root->right;                 //shifting the root to its next child
            free(temp);                         //free the temp node
           /* return root;                        /*returning the next right node to make link with 
            ----                                  previous nodes*/ 
        
        } else if (root->right == NULL) {       //if left child only
            struct tree* temp = root;           //making a copy of root
            root = root->left;                  //shifting the root to its next child
            free(temp);                         //free the temp node
            /*return root;                        /*returning the next left node to make link with 
            ----                                  previous nodes*/ 
        
        } else {                                //both child are present
            struct tree* temp = minValue(root->right);  // inorder successor
            root->value = temp->value;
            root->right = del(root->right, temp->value);
        } 
        
        
    }

    return root;
}


int main () {
    
    int ch = 3, val;
    struct tree *root = NULL;

    do{
        printf("\n1:Add\t2:Show\t3:Delete\t4:Search\t5:Exit :-\t");
        scanf ("%d", &ch);

        switch ( ch ) {
            
            case 1: printf("\nData to enter:\t");
                    scanf("%d", &val);
                    root = ins(root, val);
                    break;
            
            case 2: inorderShow(root);
                    printf("\n\n");
                    break;

            case 3: printf("\nData to delete:\t");
                    scanf("%d", &val);
                    root = del(root, val);

                    inorderShow(root);              //display after delete
                    printf("\n\n");

                    break;
            
            case 4: printf("\nData to search:\t");
                    scanf("%d", &val);
                    ( search(root, val)) ? printf("\nFound") : printf("\nNot Found");
                    break;  

            default : printf("\nWrong choice!");       
        }
    } while ( ch < 5) ;

    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}
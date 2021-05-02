#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node* left, *right;
}node;

#define size sizeof(node)

node* insert( ) {
    node *p;
    int x;
    printf("\nEnter data(-1 for no data):\t");
    scanf("%d", &x);

    if(x == -1) { return NULL; }

    p = (node*)malloc(size);
    p->data = x;

    printf("\nEnter Left Child of %d:\n", x);
    p->left=insert();

    printf("\nEnter Right Child of %d:\n", x);
    p->right=insert();

    return p;
} 

void preOrder( node *t) {
    if(t!=NULL) {
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

int main () {
    
    printf("\n---Binary Tree---\n");
    node *root = insert();

    printf("\nPreorder traversal of tree is:\t");
    preOrder(root);

    return 0;
}
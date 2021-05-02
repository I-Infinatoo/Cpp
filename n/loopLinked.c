#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node* next;
};
#define size sizeof(struct node)

struct node* ins( struct node* head, int val) {
    
    struct node* newNode = (struct node* )malloc(size);
    
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) { return newNode; }

    struct node* temp = head;
    while( temp->next != NULL ) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLinkedList(struct node *head) {

    while (head != NULL) {
        printf("%d", head->data);
        if(head != NULL && head->next!=NULL) { printf("-->"); }
        head = head->next;
    }
}

void printFromLast(struct node* head, int pos) {
    
    int length = 0; 
    struct node* temp = head;
 
    while( temp != NULL) {
        length++;
        temp = temp->next;
    }

    temp = head;
    
    for (int i = 1; i < length - pos + 1; i++) { temp = temp->next; }

    printf("\nData at %d-pos from last node is: %d", pos, temp->data);
}

int main () {
    
    struct node* head = NULL;

    head = ins(head, 20);
    head = ins(head, 30);
    head = ins(head, 40);
    head = ins(head, 50);
    head = ins(head, 60);
    head = ins(head, 70);

    printLinkedList(head);

    printFromLast(head, 2);
}

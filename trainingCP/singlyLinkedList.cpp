#include<iostream>

class node{

    public:
    int data;
    node *next;

    node(int inputData)
    : data(inputData) , next(NULL) 
    {

    }

    node()
    : data(0), next(NULL)
    {

    }
};

void insertBeg(node* &start, int data) {

    node *newNode = new node(data);

    if(start==NULL){
        start = newNode;
        return; 
    }

    newNode->next=start;
    start=newNode;

    return;

}

void insertEnd(node* &start, int data) {

    node* newNode = new node(data);

    if(start==NULL){
        start=newNode;
        return;
    }

    node *tempNode=start;
    while(tempNode->next!=NULL){
        tempNode=tempNode->next;
    }

    tempNode->next=newNode;
    return;

}

void display(node *start) {
    
    if(start==NULL) {
        std::cout << "\nEmpty!\n";
    }

    // node *temp = start;
    while(start!=NULL){     //here we are using start to iterate because we have received it by value not by ref.
        std::cout << start->data << " ";
        start=start->next;
    } 

    std::cout << "\n";
}

void reverseIteration(node* &start){
    
    node* currentNode = start;
    node *prevNode = NULL, *nextNode = NULL;
 
    while (currentNode != NULL) {
            // Store next
        nextNode = currentNode->next;
 
            // Reverse current node's pointer
        currentNode->next = prevNode;
 
            // Move pointers one position ahead.
        prevNode = currentNode;
        currentNode = nextNode;
    }
    start = prevNode;
}

void printUsingRecurssion(node *start){

    if(start==NULL){
        return;
    }

    std::cout << start->data << " ";

    printUsingRecurssion(start->next);
}

void printRevUsingRecurssion(node *start) {

    if(!start){
        return;
    }

    printRevUsingRecurssion(start->next);
    std::cout << start->data << " " ;
}

void reverseRecurssion(node *&start) {
    
}

int main () {

    node *head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    // display(head);
    
    // printUsingRecurssion(head);
    printRevUsingRecurssion(head);
    // display(head);

    // reverseIteration(head);
    // display(head);

    return 0;
}
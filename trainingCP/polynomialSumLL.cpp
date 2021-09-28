#include<iostream>

class node {
    public:
    int power;
    int data;
    node *next;

    node() 
    : power(0), data(0), next(NULL)
    {

    }
    node(int data, int power) 
    : power(power), data(data), next(NULL)
    {

    }
    
};

void insertEnd(node* &start, int data, int power) {
    
    node* newNode = new node(data, power);

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
        std::cout << start->data << "^" << start->power << " ";
        start=start->next;
    } 

    std::cout << "\n";
}

node* addPolynomial(node *head, node *head1){
    node *tempResult = new node(0,0);
    node *tempResultPointer = tempResult;

    while(head!=NULL and head1!=NULL){
        if(head->power==head1->power){
            node *tempNode= new node(head->data+head1->data, head->power);
            tempResultPointer->next=tempNode;
            head=head->next;
            head1=head1->next;
        }
        else if(head->power>head1->power){
            tempResultPointer->next=head;
            head=head->next;
        }
        else {
            tempResultPointer->next=head1;
            head1=head1->next;
        }
        tempResultPointer=tempResultPointer->next;
    }

    if(head1!=NULL){
        tempResultPointer->next=head1;
    }

    if(head!=NULL){
        tempResultPointer->next=head;
    }

    return tempResult->next;
}


int main() {
    node *head = NULL;

    insertEnd(head, 2, 2);
    insertEnd(head, 3, 1);
    
    node *head1 = NULL;

    insertEnd(head1, 5, 1);
    insertEnd(head1, 6, 0);

    display(head);
    display(head1);

    node *result=addPolynomial(head, head1);
    display(result);

    return 0;
}
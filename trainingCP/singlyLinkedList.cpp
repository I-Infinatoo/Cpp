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

node* reverseRecurssion(node *&start) {
    
    if(start->next==NULL or start==NULL){
        // startRef=start;
        return start;
    }

    node* newHead = reverseRecurssion(start->next);
    start->next->next=start;
    start->next=NULL;

    return newHead;
    
}

node* midNodeUsingDoublePointerIteration(node *start){
    if(start==NULL) {
        return start;
    }

    node *fast=start, *slow=start;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next; 
    }

    return slow;
}

void nthNodeFromEnd(node *start, int &n) {
    if(start==NULL) {
        return;
    }

    nthNodeFromEnd(start->next, n);

    if(--n == 0) {
        std::cout << start->data << " ";
    }
}

// node* midNodeUsingSinglePointerIteration(node* start) {
//     if(start==NULL){
//         return start;
//     }

// }


node *mergeSortedListRecurrsion(node *head1, node *head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node *result=NULL;
    if(head1->data<=head2->data) {
        result=head1;
        result->next=mergeSortedListRecurrsion(head1->next, head2);
    }
    else {
        result=head2;
        result->next=mergeSortedListRecurrsion(head1, head2->next);
    }

    return result;

}

node *mergeSortedList(node *head1, node *head2) {

    node *tempHead = new node(-1);
    node *tempHeadPointer = tempHead;

    while(head1!=NULL and head2!=NULL){
        if(head1->data <= head2->data) {
            tempHeadPointer->next=head1;
            head1=head1->next;
        }
        else{
            tempHeadPointer->next=head2;
            head2=head2->next;
        }
        tempHeadPointer=tempHeadPointer->next;
    }

    if(head2!=NULL){
        tempHeadPointer->next=head2;
    }

    if(head1!=NULL){
        tempHeadPointer->next=head1;
    }

    return tempHead->next;
}

void midNodeUsingDoublePointerIterationAndSeperate(node *start, node *&l1, node *&l2){
    if(start==NULL) {
        return ;
    }

    l1=start;
    
    node *fast=start, *slow=start, *temp=NULL;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        temp=slow;
        slow=slow->next; 
    }
    temp->next=NULL;

    l2=slow;
}

node *mergeList(node *head1, node *head2){

    node *tempHead = new node(-1);
    node *tempHeadPointer = tempHead;

    while(head1!=NULL and head2!=NULL){

        tempHeadPointer->next=head1;
        head1=head1->next;
        tempHeadPointer=tempHeadPointer->next;
            
        tempHeadPointer->next=head2;
        head2=head2->next;
        tempHeadPointer=tempHeadPointer->next;
    }

    if(head2!=NULL){
        tempHeadPointer->next=head2;
    }

    if(head1!=NULL){
        tempHeadPointer->next=head1;
    }

    return tempHead->next;
} 

node *foldeList(node *start) {
    node *l1=NULL, *l2=NULL;
    midNodeUsingDoublePointerIterationAndSeperate(start, l1, l2);

    l2=reverseRecurssion(l2);

    return mergeList(l1, l2);
}

node *createIntersectionPoint(node *head, node *head2, int position){
    if(!head or !head2){
        return head2;
    }
    node *head2Pointer=head2;
    while(head2Pointer->next!=NULL){
        head2Pointer=head2Pointer->next;
    }

    while(head!=NULL and position--){
        head=head->next;
    }
    head2Pointer->next=head;

    return head2;
}

#include<unordered_set>
node *findIntersectionPoint(node *head, node *head2){

   //will use unsorted_map (hash map) to find the intersection point
   //using unordered set
    std::unordered_set<node*>setNode;
    
    while(head!=NULL){
        setNode.insert(head);
        head=head->next;
    }

    while(head2!=NULL){
        if(setNode.find(head2)!=setNode.end()){
            return head2;
        }
        head2=head2->next;
    }
    return NULL;
}

int main () {

    node *head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);
    insertEnd(head, 60);

    display(head);

    // node *foldedList=foldeList(head);
    // display(foldedList);

    node *head2 = NULL;
    insertEnd(head2, 70);
    insertEnd(head2, 80);
    
    head2=createIntersectionPoint(head, head2, 3);
    display(head2);

    std::cout << findIntersectionPoint(head, head2)->data << "\n";

    return 0;
}
#include<iostream>
#include<malloc.h>
#include<string>

struct node {
    char data;
    node* next;
    // node* prev;
};
struct node *head=NULL, *tail=NULL;

void insert(char i){
    if(!head){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = i;
        temp->next=NULL;
        
        head=tail=temp;
        return;
    }

    struct node* p=head;
    while(p->next!=NULL){ p=p->next; }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = i;
    temp->next=NULL;

    p->next=temp;
    
    tail=temp;
        
}

void addEnd(char t, bool i) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = t;
    temp->next=NULL;
        
    if(i){
        tail->next=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void print(){
    struct node*temp=head;
    while(temp!=NULL){
        std::cout << temp->data;
        temp=temp->next;
    }
}

void reverse(){
    struct node* current = head, *prev = NULL, *next = NULL;
 
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {

    std::string str = "abc";
    // std::cin >> str;

    for(auto i:str){
        insert(i);
    } 

    int q=1;
    // std::cin >> q;

    while(q--){
        int query=1;
        // std::cin >> query;
        switch(query){
            
            case 1: {
                        reverse();
            }
            break;

            case 2: {
                        char temp;
                        std::cin >> temp;

                        addEnd(temp, true); //1 to add at the end
            } 
            break;

            case 3: {
                        char temp;
                        std::cin >> temp;

                        addEnd(temp, false); //0 for starting
            } break;
        }
    }

    print();
    
    return 0;
}
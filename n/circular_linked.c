#include<stdio.h>
#include<malloc.h>

struct node {
    int info;
    struct node *next;
};

#define size sizeof(struct node)

struct node* ins(struct node* rear, struct node* front){
    
    struct node *temp = (struct node*)malloc(size);
    
    printf("\nEnter data:\t");
    scanf("%d", &temp->info);
    
    temp->next = NULL;
    
    if ( rear == NULL ) {
        
        return temp;
       
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
    
    return rear;
    
}

struct node* del (struct node* rear,struct node* front) {
    
    if (front == NULL) {
        printf("Empty");
        return front;
    }

    struct node *temp = front;
    
    printf("\nDeleted element:\t%d", temp->info);

    if (front == rear ) {
        front = rear = NULL;
        return front;
    }

    front = front->next;
    rear->next = front;
    
    temp = NULL;
    return front;
}

void show(struct node* rear, struct node *front) {
    
    struct node *temp = front;
    
    if (front == NULL) {
        printf("\nEmpty");
        return ;
    }
    
    printf("\nQueue:\t");
        
    while (temp->next != front) {
        printf("\t%d", temp->info);
        temp = temp->next;
    }
    printf("\t%d", temp->info);

    temp = NULL;
    return ;
}

int main () {
    
    int ch;
    struct node *front = NULL, *rear = NULL;
    while(1) {
        printf("\n1.Insert\t2.Delete\t3.Show\t4.Exit\t");
        scanf("%d", &ch);
        
        switch(ch) {

            case 1: if( rear == NULL && front == NULL )  { front = rear = ins(rear, front); } // for the very first time
                    else { rear = ins(rear, front); }
                    break;
            
            case 2: if ( front == rear ) { rear = front = del(rear, front); }       //for the single node
                    else { front = del(rear, front); }
                    break;

            case 3: show(rear, front);
                    break;

            case 4: return 0;        
        }
    }
    return 0;    
}
#include <stdio.h>
#include <malloc.h>

struct node {
    int info;
    struct node *next;
}; 

#define size sizeof(struct node)

struct node* ins(struct node *rear) {
    struct node *temp = (struct node*)malloc(size);
    
    printf("\nEnter data:\t");
    scanf("%d", &temp->info);
    
    temp->next = NULL;
    
    if ( rear == NULL ) {
        rear = temp;
       
    } else {
        rear->next = temp;
        rear = temp;
    }
    
    return rear;
}

struct node* del (struct node* front) {
    
    if (front == NULL) {
        printf(" Empty");
        return front;
    }
    
    struct node *temp = front;
    
    printf("\nDeleted element:\t%d", temp->info);

    front = front->next;
    temp = NULL;
    return front;
}

void show(struct node *front) {
    
    struct node *temp = front;
    
    if (front == NULL) {
        printf("\nEmpty");
        return ;
    }
    
    printf("\nQueue:\t");
        
    while (temp != NULL) {
        printf("\t%d", temp->info);
        temp = temp->next;
    }
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

            case 1: if( rear == NULL && front == NULL )  { front = rear = ins(rear); } // for the very first time
                    else { rear = ins(rear); }
                    break;
            case 2: front = del(front);
                    break;
            case 3: show(front);
                    break;
            case 4: return 0;        
        }
    }
    return 0;
}
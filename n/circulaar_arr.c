#include<stdio.h>

#define size 3
int front = -1, rear = -1;

void insert(int q[]) {  
    
    if ( (front == 0 && rear == size-1) || (front-rear)==1 ) {
        printf("\nQueue is Full");
        return;
    }
    
    int data;
    printf("\nEnter data:\t");
    scanf("%d", &data);
    
    if (front == -1 && rear==-1) { // Insert 1st
        
        front = rear = 0;
        q[rear] = data;
    }
    else if (rear == size-1 && front != 0) {
        rear = 0;
        q[rear] = data;
    }
    else {
        rear=rear+1;
        q[rear] = data; 
    }
} 

void del( int q[] ) {
    if (front == -1) {
        printf("\nQueue is Empty");
        return; 
    }
    int data = q[front];
    q[front] = -1;
    printf("\nDeleted data:\t%d", data);
    
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front=front+1;
    return ;
} 

void show( int q[]) {
    int front_pos = front, rear_pos = rear;
    if(front == -1) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue elements :\t");
    
    if ( front_pos <= rear_pos ) {
        while(front_pos <= rear_pos) {
            printf("%d ",q[front_pos]);
            front_pos++;
        }
    }
    else {
        while(front_pos <= size-1) {
            printf("%d ",q[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos) {
            printf("%d ",q[front_pos]);
            front_pos++;
        }
    }
}

int main() {   
    
    int q[size], ch, data;
    while(1) {
        printf("\n1.Insert\t2.Delete\t3.Show\t4.Exit\t");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: insert(q);
                    break;

            case 2: del(q);
                    break;

            case 3: show(q);
                    break;

            case 4: return 0;        
        }
    }

    return 0;
}
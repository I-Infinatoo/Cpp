#include <stdio.h>

#define size 3
int front = -1, rear = -1;

int ins(int q[]) {
    
    if( rear == size-1) {
        printf("\nFull");
        return 0;
    }
    
    printf("\nEnter element:\t");
    
    if( rear == -1 && front == -1) {
        front = 0;
    
    } 
    scanf("%d", &q[++rear]);
    
    printf("\nf:%d  r:%d", front, rear);
    return 0;
}

int del (int q[]) {
    
    if( front == -1 || front == rear+1) {
        printf("\nEmpty");
        return 0;
        
    } else {
        printf("\nDeleted element:\t%d", q[front++] );
    }
    printf("\nf:%d  r:%d", front, rear);
    return 0;
}

void show (int q[]) {
    
    if( front == -1 || front == rear+1) {
        printf("\nEmpty");
        return ;
        
    }
    printf("\nQueue:\n");
    for(int i = front; i <= rear; i++ ) {
        printf("\t%d", q[i]);
    }
    printf("\nf:%d  r:%d", front, rear);
}

int main()
{   
    int q[size], ch;
    while(1) {
        printf("\n1.Insert\t2.Delete\t3.Show\t4.Exit\t");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: ins(q);
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

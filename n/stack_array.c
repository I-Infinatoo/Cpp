#include <stdio.h>

#define size 3

int top = -1;

void push(int s[]) {
    
    if( top == size-1) {
        printf("\nFull");
    
    } else {
        printf("\nEnter element:\t");
        scanf("%d", &s[++top]);
    }
}

void pop (int s[]) {
    
    if( top == -1) {
        printf("\nEmpty");
    
    } else {
        printf("\nDeleted element:\t%d", s[top--] );
    }    
}

void show (int s[]) {
    
    printf("\nStack:\n");

    if( top == -1) {
        printf("\nEmpty");
    
    } else {

        for(int i = top; i >=0; i-- ) {
            printf("\t%d", s[i]);
        }
    }
}

int main()
{   
    int ch;
    int s[size];
    
    while(1) {
        printf("\n1.Push\t2.Pop\t3.Show\t4Exit\t");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: push(s);
                    break;

            case 2: pop(s);
                    break;

            case 3: show(s);
                    break;

            case 4: return 0;        
        }
    }

    return 0;
}

// stack using linked list
#include <stdio.h>
#include<malloc.h>

struct node {
  int info;
  struct node *next;
};

#define size sizeof(struct node)

struct node* push (struct node* top) {
    struct node *p = (struct node *)malloc(size);
    
    if(p == NULL) {
        printf("\nOut of Space!");
        return 0;
    }   
    
    printf("\nEnter data:\t");
    scanf("%d", &p->info);
    p->next = top;
    top = p;
    
    return top;
}

struct node* pop(struct node* top) {
    if (top == NULL) {
        printf("\nEmpty");
        return top;
    }
    struct node *p = top;
    printf("\nDeleted Data:\t%d", p->info);
    
    top = top->next;
    free(p);
    
    return top;
}

void show (struct node* top) {
    if (top == NULL) {
        printf("\nEmpty");
        return ;
    }
    struct node *p = top;
    
    printf("\nElements of Stack:\n");
    while (p!=NULL) {
        printf("\t%d", p->info);
        p=p->next;
    }

    return ;	
}

int main () {
    int ch;
    struct node *top = NULL;
    while(1) {
        printf("\n1.Push\t2.Pop\t3.Show\t4.Exit\t");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: top = push(top);
                    break;
            case 2: top = pop(top);
                    break;
            case 3: show(top);
                    break;
            case 4: return 0;        
        }
    }

    return 0;
}

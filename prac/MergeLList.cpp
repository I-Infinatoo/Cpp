//incomplete and incorrect merge function
#include<iostream>

struct node
{
    int data;
    struct node *next;

    node (int val) 
    : data(val), next(NULL) {}
};

struct node* insertEnd(struct node* head, int val)
{
    if(!head)
    {
        struct node * temp = new node(val);
        
        return temp;
    }

    struct node* p = head;
    while(p->next!=NULL){ p = p->next; }

    struct node * temp = new node(val);
    p->next = temp;

    return head;
}

void disp(struct node *head)
{
    if(!head)
    {
        return;
    }

    while(head!=NULL)
    {
        
        if(head->next == NULL) 
        {
            std::cout << head->data << "\n";
        }
        else
        {
            std::cout << head->data << "->";
        }
        
        head = head->next; 
    }
}
//incomplete and incorrect
struct node* merge(struct node* head1, struct node* head2)
{
    struct node* p1 = head1, *p2 = head2; 
    head1 = NULL;
    while(p1->next!=NULL and p2->next!=NULL) {

        if(p1->data <= p2->data)
        {
            head1->next = p1;
            p1 = p1->next;
        } else 
        {
            head1->next = p2;
            p2 = p2->next;
        }

        head1 = head1->next;
    }
    return head1;
}

int main () 
{
    struct node *head1 = NULL, *head2 = NULL;

    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 5);
    head1 = insertEnd(head1, 7);
    head1 = insertEnd(head1, 9);

    disp(head1);

    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 6);
    head2 = insertEnd(head2, 8);

    disp(head2);

    // head1 = merge(head1, head2);
    // disp(head1);
    return 0;
}
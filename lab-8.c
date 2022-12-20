#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

//Enqueue function
struct node* enQueue(struct node *head, int x) {
    struct node *p = malloc(sizeof(struct node));
    p->val = x;
    p->next = NULL;

    struct node *temp = head;
    while(temp->next!=NULL) temp = temp->next;
    
    temp->next = p;

    return head;

}

//Dequeue function
struct node* deQueue(struct node *head) {
    struct node *temp = head;
    head = head->next;
    
    free(temp);
    return head;
}

//Print Queue fucntion
void printQueue(struct node *head) {
    
    printf("\nQueue: ");
    while(head!=NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    //Creating queue of 3 nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));

    //assigning values and forming a queue
    head->val = 5;
    head->next = n1;
    n1->val = 8;
    n1->next = n2;
    n2->val = 2;
    n2->next = NULL;

    //printing queue
    printQueue(head);
 
    //enqueuing 9 and 16
    head = enQueue(head, 9);
    head = enQueue(head, 16);
    printQueue(head);
 
    //dequeuing 5 and 8
    head = deQueue(head);
    head = deQueue(head);
    printQueue(head);

}
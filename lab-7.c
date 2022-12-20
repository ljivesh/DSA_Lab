#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

//Insertion at first node
struct node* insertAtFront(struct node *head, int x)
{
    
    struct node *p = malloc(sizeof(struct node));
    p->val = x;
    p->next = head;

    struct node *temp = head;
    while(temp->next!=head) temp = temp->next;
    
    temp->next = p;
    head = p;

    return head;
}

//Deletion at last node
void deleteLast(struct node *head)
{
    struct node *temp = head;
    while (temp->next->next!=head) temp = temp->next;
    
    free(temp->next);
    temp->next = head;
      
}

//Function to print list
void printList(struct node *head)
{
    printf("\nList: ");
    struct node *temp = head;
    
    
    
    while(temp->next != head) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
        printf("%d ", temp->val);

    
}

int main()
{
    //creating first 3 nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));

    //assigning values and joining the nodes in circular loop
    head->val = 8;
    head->next = n1;

    n1->val = 10;
    n1->next = n2;
    
    n2->val = 5;
    n2->next = head;

    //printing the list
    printList(head);
    
    //Inserting new node at front and updating head
    head = insertAtFront(head, 7);
    printList(head);

    //deleting last node
    deleteLast(head);
    printList(head);

}
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *head){
    struct Node * ptr = head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=head);
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    } 
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 27;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 77;
    fourth->next = head;
   
    printf("Circular linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 21);
    // head = insertAtFirst(head, 7);
    head = insertAtIndex(head, 12, 4); 
    printf("Circular linked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}
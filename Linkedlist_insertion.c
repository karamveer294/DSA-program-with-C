#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
   
};
void linkedListTraversal(struct Node  *ptr){
    while(ptr!=NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct  Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;

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
    struct Node * head; 
    struct Node * second; 
    struct Node * third; 
    struct Node * fourth;

    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    fourth = (struct Node*)malloc(sizeof(struct Node)); 
    //   for the first element in the given linked list
    head->data = 11;
    head->next = second;
    //   for the second element in the given linked list
    second->data = 24;
    second->next = third;
     
    //  for the third element in the given linked list
    third->data = 77;
    third->next = fourth;

    fourth->data = 07;
    fourth->next = NULL;

    printf("Linked List before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 3, 11);
    //head = insertAtEnd(head, 5);
    printf("LInked List after insertion\n");
    linkedListTraversal(head);
    

    return 0;
}
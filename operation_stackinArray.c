#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full:%d\n", isFull(sp));
    printf("Before pushing, Empty:%d\n", isEmpty(sp));
    push(sp, 12);
    push(sp, 21);
    push(sp, 33);
    push(sp, 81);
    push(sp, 7);
    push(sp, 333);
    push(sp, 18);
    push(sp, 72);
    push(sp, 99);
    push(sp, 23);
    push(sp, 101);
    printf("After pushing, Full:%d\n", isFull(sp));
    printf("After pushing, Empty:%d\n", isEmpty(sp));
    printf("Popped %d from the stack\n: ", pop(sp));

    return 0;
}

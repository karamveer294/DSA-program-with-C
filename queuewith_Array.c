#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue * q)
{
    if(q->r == q->f){
        return 1;

    }
    return 0;
}

int isFull(struct queue * q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int val){
    if(isFull(q)){
        printf("This queue is Full\n");

    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueue element: %d\n", val);
    }
}

int dequeue(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is Empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 45);
    enqueue(&q, 22);
    enqueue(&q, 77);
    enqueue(&q, 4);
    printf("Dequeuing element: %d\n",  dequeue(&q));
    printf("Dequeuing element: %d\n",  dequeue(&q));
    printf("Dequeuing element: %d\n",  dequeue(&q));
    // enqueue(&q, 59);
    // enqueue(&q, 11);

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }

    return 0;

}
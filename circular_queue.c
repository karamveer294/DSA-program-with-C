#include<stdio.h>
#include<stdlib.h>

struct cicularQueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct cicularQueue * q){
    if(q->r==q->f){
        return -1;
    }
    return 0;
}

int isFull(struct cicularQueue *q){
    if((q->r+1)%q->size == q->f){
    return 1;
    }

    return 0;
}

void enqueue
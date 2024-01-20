#include<stdio.h>

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        printf("%d\t\t", A[i]);
    }
    printf("\n");
}

void selectionSort(int* A, int n){
    int indexofMin, temp;
    printf("Pressing selection count ...\n");
    for(int i = 1; i < n-1; i++){
        indexofMin = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[indexofMin]){
                indexofMin = j;

            }
        }
        temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}

int main()
{
    int A[] ={11, 55, 3, 45, 7, 4};
    int n = 6;

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;

}
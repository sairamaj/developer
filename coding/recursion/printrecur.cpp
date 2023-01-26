#include <stdio.h>

void printReverse(int* array, int size)
{
    if(size == 0){
        return;
    }

    if(size == 1){
        printf("%d-", array[0]);
        return;
    }

    printReverse(&array[1], size-1);
    printf("%d-", array[0]);
}

void printNormal(int* array, int size)
{
    if(size == 0){
        return;
    }

    printf("%d-", array[0]);
    printNormal(&array[1], size-1);
}

void printNumberInReverse(int n){
    if(n==0){
        return;
    }
    printf("%d-", n);
    printNumberInReverse(n-1);
}

void main()
{
    int array[] = {1,3,6,7,8};
    int size = sizeof(array)/sizeof(int);
    printReverse(array, size);
    printf("\n------------\n");
    printNormal(array,size);

    printf("\n------------\n");
    printNumberInReverse(5);
}


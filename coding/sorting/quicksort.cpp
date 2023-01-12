/*
    Quick sort works on pivot.
    Select a pivot element and move to its poistion where all left elements are less than this pivot
    and all right elements are more than this pivot
      50,70,60,90,40,80,10,20,30
    aim is to take pivot say 50 and move and it should become
        (40,30,20,10) 50 (80,90,60,70)
    this is also called partitioning here we have (40,30,20,10) are less than 50 and (80,90,60,70) are more than 50 and elemeent 50
    is sitting in right position.
    This process is repeated on left (40,30,20,10) and (80,90,60,70)

    Pseudo code:
      50,70,60,90,40,80,10,20,30
    pivot: 50
        p:0(50)
        i:0(50)
        j:8(30)
       move i such that right element is less than pivot:50
            i=1(70) i stopped as it is more than 50
            j=8(30) j is stopped as it is less than 50
            swap
                50,30,60,90,40,80,10,20,70
            move i:2(60) j:7(20)
            swap again
                 50,30,20,90,40,80,10,60,70
            keep doing this till i>j
                50,30,20,10,40,80,90,60,70
            do till i > j
                here i:5(80) and j:4(40)
                swap pivot now 0(50) with j
                (40,30,20,10),(50),(80,90,60,70)
            now we have 50 is in right place where all elements to left or less.

            Now work separately on (40,30,20,10) and also on (80,60,60,70)
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int l, int h)
{
    int i = l;
    int j = h;
    int pivot = array[l];

    do
    {
        // move i such that it is more than pivot
        do
        {
            i++;
        } while (array[i] <= pivot);

        // move j such that it is less than pivot
        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            // we found element at left less than pivot and right more than pivot. swap
            swap(&array[i], &array[j]);
        }
    } while (i < j);

    // swap pivot with j
    swap(&array[l], &array[j]);
    return j;
}

void printArray(char *title, int *array, int start, int end)
{
    printf("%s\n", title);
    for (int i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
        {
            printf(",");
        }
    }
    printf("\n");
}

void printArray(char *title, int *array, int size)
{
    printf("-------%s---------\n", title);
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            printf(",");
        }
    }
    printf("\n");
}

void quickSort(int *array, int l, int h, int size)
{
    printArray("quicksort", array, l, h);
    int x = 0;
    printf("l:%d h:%d\n", l, h);
    if (l < h)
    {
        int j = partition(array, l, h);
        quickSort(array, l, j, size);
        quickSort(array, j + 1, h, size);
    }
}
void main()
{
    int array[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, INT_MAX};
    int size = sizeof(array) / sizeof(int);

    printArray("original", array, size);
    quickSort(array, 0, size - 1, size);
    printArray("modified", array, size);
}
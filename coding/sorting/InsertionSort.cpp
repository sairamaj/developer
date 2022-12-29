#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *array, int size)
{
    // 0,1,2
    // 
    for (int i = 0; i < size-1; i++)
    {
        for (int j = (i+1); j > 0; j--)
        {
            if (array[j-1] > array[j])
            {
                swap(&array[j-1], &array[j]);
            }
        }
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }

    printf("\n");
}

void main()
{
    int array[] = {3, 5, 1, 6, 1};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    sort(array, size);
    printArray(array, size);
}

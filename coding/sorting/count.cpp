/*
    here we create a new array which has size of larget element in the original array
    i.e
        6, 3, 9, 10, 15, 6, 8, 12, 3, 6
    we create array of size 15
    for each element in original array we mark the position in this auxilary array.

    [0,0,0,2,0,0,3,....]

    we use this auxiliary array to write sorted array.

    pseudo code
        - get max
        - declare new array
        - go through each element and increment the value at that position
        - write the sorted array from the auxiliary array info.

*/
#include <stdio.h>
#include <memory.h>

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

int getMax(int *array, int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}
void countSort(int *array, int size)
{
    int max = getMax(array, size);
    int *auxArray = new int[max + 1];
    memset(auxArray, 0, sizeof(int) * (max + 1));

    for (int i = 0; i < size; i++)
    {
        auxArray[array[i]] = auxArray[array[i]] + 1;
    }

    int k = 0;
    for (int i = 0; i < (max + 1); i++)
    {
        if (auxArray[i] > 0)
        {
            for (int j = 0; j < auxArray[i]; j++)
            {
                array[k++] = i;
            }
        }
    }
}
void main()
{
    int array[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int size = sizeof(array) / sizeof(int);

    printArray("before", array, size);
    countSort(array,size);
    printArray("after", array, size);
}
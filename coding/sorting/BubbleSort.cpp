#include <stdio.h>

void sort(int *array, int size)
{
    bool continueProcess = true;
    while (continueProcess)
    {
        continueProcess = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                continueProcess = true;
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
    int array[] = {3, 5, 1, 6, 1, 0};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    sort(array, size);
    printArray(array, size);
}

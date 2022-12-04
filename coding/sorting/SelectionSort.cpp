/*
    Selection sort is most intutitive
    Strategy:
        Go through each element
        Compare with other element
        swap if other elements is less than this
    Complexity
        Time:  O(n*2)
        Space: O(1)
*/

#include <stdio.h>
void sort1(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (array[j] < array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// leetcode version
//  start j=i+1
//  don't swap immeidate. find out min and then swap finally
void sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = array[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[i])
            {
                if (array[j] < min)
                {
                    minIndex = j;
                }
            }

            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
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

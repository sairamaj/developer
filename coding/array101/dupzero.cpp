#include <stdio.h>

// 4,5,1,2
// 0,4,5,2

// 4,4,1,2

void printArray(int *array, int size)
{
    printf("__________________________\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
    printf("__________________________\n");
}

void main()
{
    int array[8] = {1, 0, 2, 3, 0, 4, 5, 0};

    auto size = sizeof(array) / sizeof(int);
    printArray(array,size);
    for (int i = size - 2; i > 0; i--)
    {
        if (array[i - 1] == 0) // check for previous 0
        {
            auto cur = array[i];                // take the current (4)
            for (auto j = i; j < size - 1; j++) // Loop through the rest of the elements
            {
                auto existing = array[j + 1]; // backup (5) the next one.
                array[j + 1] = cur;           // update the next one with cur(4)
                cur = existing;               // update the cur with 5.
            }
            array[i] = 0; // set current to 0;
        }
    }

    printArray(array,size);
}
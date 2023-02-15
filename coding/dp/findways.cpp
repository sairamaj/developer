/*
    3

        0 --                    1 --
    0 0 -     0 1 -           1 0 -
0 0 1  000   010


*/
#include <stdio.h>

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%4d", array[i]);
    }

    printf("\n");
}
int findWays(int array[], int start, int prev, int size)
{
    // we have reached to end means we have a combination
    if (size == start)
    {
        return 1;
    }

    int count = 0;
    array[start] = 0;
    count += findWays(array, start + 1, 0, size);

    if (prev != 1)
    {
        array[start] = 1;
        count += findWays(array, start + 1, 1, size);
    }

    return count;
}
void main()
{
    int array[3];
    int size = sizeof(array) / sizeof(int);
    auto count = findWays(array, 0, -1, size);
    printf("%d\n", count);
}
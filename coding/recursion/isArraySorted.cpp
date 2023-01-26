/*
    find out whether array is sorted or not through recursion
    [1,2,3,4,5,6]

    start with [1,2] + [3,4,5,6]
                            [3,4] + [4,5,6]
                                    [4,5] + [5,6]
                                        [6] => true (base condition)
*/
#include <stdio.h>

bool isSorted1(int *array, int size)
{
    if(size == 0 || size == 1){
        return true;
    }

    if(array[0] < array[1]){
        return isSorted1(&array[1], size-1);
    }

    return false;       // not sorted
}
bool isSorted(int *array, int size)
{
    return isSorted1(array, size);
}
void main()
{
    int array[] = {1, 2, 3, 4, 5, 6,12};
    int size = sizeof(array)/sizeof(int);

    printf("%d", isSorted(array, size));
}
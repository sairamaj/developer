#include <stdio.h>
void printArray(int *array, int size)
{
    printf("\n__________________________\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
    printf("\n__________________________\n");
}

bool validMountainArray(int *arr, int arrSize)
{
    // go through beginging
    //      compare with next
    //      if same
    //          not a mountain
    //      if less
    //          stop reached peak
    //      if more
    //          move to next
    // go through end
    //      compare with previous
    //      if same
    //          not a mountain
    //      if less
    //          stop- reached mountain
    //      if more
    //          move to previous

    // check at the end whether both left and right are same position
    //      then it is mountain.

    if (arrSize == 1)
    {
        return false;
    }

    int left = 0, right = arrSize - 1;
    while (left < arrSize - 2)
    {
        if (arr[left] < arr[left + 1])
        {
            left++;
        }
        else
        {
            break;
        }
    }

    while (right > 1)
    {
        if (arr[right] < arr[right - 1])
        {
            right--;
        }
        else
        {
            break;
        }
    }
    // printf("left:%d-%d  right:%d-%d", left, arr[left], right, arr[right]);
    return left == right;
}

void main()
{
    // int array[] = {0, 3, 2, 1};
    int array[] = {2, 1};
    printArray(array, sizeof(array) / sizeof(int));
    bool ret = validMountainArray(array, sizeof(array) / sizeof(int));
    printf("ret:%d\n", ret);
}
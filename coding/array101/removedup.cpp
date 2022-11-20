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

// 1,2,3,3,4,5,3
// keep check for value
//    if not equal to value move both i and j
// if they are same
//    keep move j till value not equal num
//    at this time we need to keep copying the elements
//    till we reach to nums or end.

int removeElement(int *nums, int numsSize, int val)
{
    int count = 0;
    int r = 0, w = 0;
    for (; r < numsSize; r++)
    {
        if (nums[r] != val)
        {
            nums[w] = nums[r];
            w++;
        }
    }
    return w;
}

// 3,2,2,3
// i=0; j=0;
// j++ = 1
// 2,2,2,3
// i++; j++;
// i=1 j=2 ;
// 2,2,2,3

void main()
{

    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int size = sizeof(nums) / sizeof(int);
    printArray(nums, size);
    int final = removeElement(nums, size, 2);
    printArray(nums, final);
}

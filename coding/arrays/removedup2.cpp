// input: 0,0,1,1,1,2,2,3,3,4
// output: 0,1,2,3,4

// w:0 r:0
// look ahead and see next value
// i.e r[1] = 0
// same as cur
// skip
// move r-> 2
// compare and they are not same. means we have done for this dup.
// move w by 1 and
// copy r[2] -> w[1] . now the array: 0,1,1,1
// keep moving r again

// i: 1,1,2
// r:0 w:0
// r[1] == w[0]
// r:2
// r[2] != w[0]
// move w: w:1
// copy r[2] w[1]
// 1,2
// r[3] does not exists and hence comeout

// 1,2,3
// r:0 w:0
// r[1] (1 !=2)
// move w
//
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
int removeDuplicates(int *nums, int numsSize)
{
    int final = 1;
    for (int r = 0, w = 0; r < numsSize - 1;)
    {
        if (nums[r + 1] == nums[w])
        {
            r++;
        }
        else
        {
            w++;
            nums[w] = nums[r + 1];
            final++;
        }
    }
    return final;
}

void main()
{
    // int nums[] = {1, 1, 2};
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(int);
    printArray(nums, size);

    int final = removeDuplicates(nums, size);
    printArray(nums, final);
}

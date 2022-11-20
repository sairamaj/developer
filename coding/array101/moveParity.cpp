/*
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/
/*
Strategy:
    left and right pointers
    keep moving left till it is odd
    keep moving right till it is even
    exchange
    do until left <= right
ex:
  left:0(3)
  right:3(4)
  exchange:
  [4,1,2,3]
  left:1(1)
  right:2(2)
  exchange
  [4,2,1,3]

ex2 (all or even)
  [6,2,4,4,6]
  left and right will move and no exchange
ex3: (center is odd)
  [2,4,6,1,8,10,12]
  left will move:1
  right will stay at: 12
  exchange
  [2,4,5,12,8.10,1]
*/

/*
Lessons learned:
    Parenthesis important
    special cases like only 2
    Look for constraints (missed case for 0 which is even)
*/
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

/*
    Found from leet code
*/
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    int left = 0;
    int right = numsSize - 1;
    while (left < right)
    {
        if (( (nums[left] & 1) ) > (nums[right] & 1) )
        {
            // that means we found odd in the left and even in the right. swap
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }

        if ((nums[left] & 1) == 0)
            left++;
        if ((nums[right] & 1) == 1)
            right--;
    }

    *returnSize = numsSize;
    return nums;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParityMySol(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    if (numsSize < 2)
    {
        return nums;
    }

    int left = 0, right = numsSize - 1;
    while (left < right)
    {
        while ((left < numsSize) && (((nums[left] & 1) == 0) || nums[left] == 0))
        {
            left++; // keep moving left till we find odd
        }
        while ((right > 0) && ((nums[right] & 1) == 1))
        {
            right--; // keep moving left till we find even
        }
        printf("left:%d right:%d\n", left, right);
        if (left < right)
        {
            // swap
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }

    return nums;
}

void main()
{
    int array[] = {3, 1, 2, 4};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    int returnSize;
    int *retArray = sortArrayByParity(array, size, &returnSize);
    printArray(retArray, returnSize);
}
/*
Problem:
    Given an integer array nums sorted in non-decreasing order,
    return an array of the squares of each number sorted in non-decreasing order.
    Example
        Input: nums = [-4,-1,0,3,10]
        Output: [0,1,9,16,100]
        Explanation: After squaring, the array becomes [16,1,0,9,100].
        After sorting, it becomes [0,1,9,16,100].

        Input: nums = [-7,-3,2,3,11]
        Output: [4,9,9,49,121]
*/

/*
    Strategy:
        find out: first positive :right
                  the previous number: left
        all the numbers on left are increasing order
        all the numbers on right are increasing order

        square and compare
        fill lower one
        move the pointer (if left -- , if right ++)

        [-4,-1,0,3,10]
        l = 1(-1)
        r = 2(0)
        [0]
        l=1(-1)
        r=3(3)

        [0,1]
        l=0(-4)
        r=3(3)
        [0,1,9]
        l=0(-4)
        r=4(10)
        [0,1,9,16]
        l=-1
        r=5(10)
        [0,1,9,16,100]


 */
#include <stdio.h>
#include <malloc.h>
#include <math.h>

void printArray(int *array, int size)
{
    printf("\n__________________________\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
    printf("\n__________________________\n");
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
    Time: O(n)
    Space: O(n)
*/
int *sortedSquaresFromLeetCode(int *nums, int numsSize, int *returnSize)
{
    // Use pattern of largest absolute value
    int left = 0;
    int right = numsSize - 1;
    int cur = 0;
    int *newArray = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    cur = numsSize - 1;
    while (left <= right)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            newArray[cur--] = nums[left] * nums[left];
            left++;
        }
        else
        {
            newArray[cur--] = nums[right] * nums[right];
            right--;
        }
    }

    return newArray;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int left = -1, right = numsSize + 1;

    int *newArray = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= 0)
        {
            right = i;
            break;
        }
        else
        {
            left = i;
        }
    }

    printf("left:%d right:%d\n", left, right);
    int cur = 0;
    while (left >= 0 || right < numsSize)
    {
        if (left < 0)
        {
            // ranout of lefts
            newArray[cur++] = nums[right] * nums[right];
            right++;
        }
        else if (right >= numsSize)
        {
            // ran out of rights
            newArray[cur++] = nums[left] * nums[left];
            left--;
        }
        else
        {
            int leftVal = nums[left] * nums[left];
            int rightVal = nums[right] * nums[right];
            if (leftVal < rightVal)
            {
                newArray[cur++] = leftVal;
                left--;
            }
            else
            {
                newArray[cur++] = rightVal;
                right++;
            }
        }
    }

    return newArray;
}

void main()
{
    int array[] = {-4, -1, 0, 3, 10};
    int ret = 0;
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    // int *squredArray = sortedSquares(array, size, &ret);
    int *squredArray = sortedSquaresFromLeetCode(array, size, &ret);
    printf("__________________________________");
    printArray(squredArray, ret);
}

/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
*/

/*
Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/

/*
    Strategy:
        [1,7,3,6,5,6]
            start from left and right;
            left = 1
            right = 6
            left < right;
            move left
            1+7
            right < left
            move right
            1+7  = 8
            5+6 = 11
            left < right
            move left
            1+7+3 = 11
            5+6 = 11
            left = right
            move left and right
            l = 6[3]
            r = 6[3]
            index is same
            pivot =3
    [1,2,3]
        l = 1
        r = 3
        l < 4
        1+2 = 3
        r = 3
        l = 3
        r = 2
        li < ri
            no pivot
    [2,1,-1]
        li = 0 [2]
        ri = 2 [-1]
    ri = 1 (val:1)
    ri = 0 (val:1-1 = 0)
    ri = 0

    [1,-1,2]
*/

/*
 Status: Not done
 Notes: Made complex of using 2 pointers. Need to implement leet code 
*/
#include <stdio.h>

int pivotIndex(int *nums, int numsSize)
{
    int lIndex = 0;
    int rIndex = numsSize - 1;
    int lSum = nums[lIndex];
    int rSum = nums[rIndex];
    while (lIndex < rIndex)
    {
        if (lSum < rSum)
        {
            lIndex++;
            lSum += nums[lIndex];
        }
        else if (rSum < lSum)
        {
            rIndex--;
            rSum += nums[rIndex];
        }
        else
        {
            lSum += nums[lIndex];
            rSum += nums[rIndex];
            lIndex++;
            rIndex--;
        }
    }

    if (lIndex == rIndex)
    {
        return lIndex;
    }

    return -1;
}

void test(int *num, int size, int expected)
{
    int lIndex = pivotIndex(num, size);
    printf("%d\n", lIndex);
    if (lIndex != expected)
    {
        printf("failed: expected:%d actual:%d\n", expected, lIndex);
    }
}
void main()
{
    int array[] = {-1, -1, -1, -1, -1, 0};
    int size = sizeof(array) / sizeof(int);
    test(array,size,2);
}
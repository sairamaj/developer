/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
c*/

/*
    Use binary searh to find target.
    once found,
        walk through either way to get start and end.
*/
/*
    NOTE: This works but this may end up linear search if there are lot of targets (like entire array
    is filled up with target) then we end up O(n)
    Todo: Implement what leet code said to find out whether what we found is first( check previous and
    if it is same then we need search in left array) or last(same approach as what we found as first)
*/
#include <stdio.h>
#include <malloc.h>

void assert(char *msg, int expected, int actual)
{
    if (expected != actual)
    {
        printf("[err] %s expected:%d actual:%d\n", msg, expected, actual);
    }
    else
    {
        printf("[success] %s expected:%d actual:%d\n", msg, expected, actual);
    }
}

int binarySearch(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
    {
        return -1;
    }
    int l = 0, h = numsSize;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        printf("mid:%d\n", mid);
        int val = nums[mid];
        if (val == target)
        {
            return mid;
        }
        if (target < val)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * 2);
    int index = binarySearch(nums, numsSize, target);
    if (index == -1)
    {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    int i = index + 1;
    int j = index - 1;
    while (nums[i] == target && i < numsSize)
        i++;
    while (nums[j] == target && j >= 0)
        j--;

    ret[0] = j + 1;
    ret[1] = i - 1;
    return ret;
}
void test1()
{
    int array[] = {5, 7, 7, 8, 8, 10};
    int size = sizeof(array) / sizeof(int);
    int retSize = 0;

    int *range = searchRange(array, size, 8, &retSize);
    assert("test1 return Size", retSize, 2);
    assert("test1 range:1", 3, range[0]);
    assert("test1 range:2", 4, range[1]);
}

void test2()
{
    int array[] = {5, 7, 7, 8, 8, 10};
    int size = sizeof(array) / sizeof(int);
    int retSize = 0;

    int *range = searchRange(array, size, 6, &retSize);
    assert("test2 return Size", retSize, 2);
    assert("test2 range:1", -1, range[0]);
    assert("test2 range:2", -1, range[1]);
}
void test3()
{
    int array[] = {1};
    int size = sizeof(array) / sizeof(int);
    int retSize = 0;

    int *range = searchRange(array, size, 1, &retSize);
    assert("test2 return Size", retSize, 2);
    assert("test2 range:1", 0, range[0]);
    assert("test2 range:2", 0, range[1]);
}
void main()
{
    //test1();
    //test2();
    test3();
}
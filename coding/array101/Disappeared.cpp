/*
Problem:
    Given an array nums of n integers where nums[i] is in the range [1, n],
    return an array of all the integers in the range [1, n] that do not appear in nums.

    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

    Input: nums = [1,1]
    Output: [2]
*/

/*
Strategy
    Brute force:
        - Create map
        - Walk through the array and load in to map
        - Walk through the map and add missing
    Optimized
        - arralocate new array
        - initialize with 0
        - walk through original list
        - set 1 in the position
        - at the end collect all 0 and find out missing.
    ex:
        [4,3,2,7,8,2,3,1]
        [0,0,0,0,0,0,0,0]

        [0,0,0,1,0,0,0,0]
        [0,0,1,1,0,0,0,0]
        [0,1,1,1,0,0,0,0]
        [0,1,1,1,0,0,1,0]
        [0,1,1,1,0,0,1,1]
        [0,1,1,1,0,0,1,1]
        [0,1,1,1,0,0,1,1]
        [1,1,1,1,0,0,1,1]

        [5,1,1,1,0,0,1,1]
        [5,6,1,1,0,0,1,1]
*/

#include <stdio.h>
#include <malloc.h>
#include <map>

using namespace std;
void printArray(int *array, int size)
{
    printf("\n__________________________\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
    printf("\n__________________________\n");
}

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *newArray = (int *)malloc(sizeof(int) * numsSize);
    memset(newArray, 0, sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        newArray[nums[i] - 1] = 1;
    }

    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (newArray[i] == 0)
        {
            newArray[k++] = (i+1);
        }
    }

    *returnSize = k;
    return newArray;
}

int *findDisappearedNumbersBruteForce(int *nums, int numsSize, int *returnSize)
{
    // create map
    map<int, int> numMap;

    // Loop throug the nums
    for (int i = 0; i < numsSize; i++)
    {
        numMap[nums[i]] = 1;
    }

    map<int, int>::iterator iter;
    int *newArray = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (numMap.find(i) == numMap.end())
        {
            newArray[*returnSize] = i;
            (*returnSize)++;
        }
    }

    return newArray;
}

void main()
{
    int array[] = {4, 3, 2, 7, 8, 2, 3, 1};
    //int array[] = {1, 1};
    int size = sizeof(array) / sizeof(int);
    int ret;

    printArray(array, size);
    int *retArray = findDisappearedNumbers(array, size, &ret);
    printf("_____________________________________");
    printArray(retArray, ret);
    free(retArray);
}

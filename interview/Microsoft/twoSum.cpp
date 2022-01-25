#include <stdio.h>
#include <malloc.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int returnSize = 0;
        unordered_map<int, int> map;
        vector<int> numbers;
        for (auto i = 0; i < nums.size(); i++)
        {
            auto diff = target - nums[i];
            // check whether this diff exists already in map
            if (map.find(diff) != map.end())
            {
                // we find diff
                numbers.push_back(map[diff]);
                numbers.push_back(i);
                return numbers;
            }
            map[nums[i]] = i; // [3] = 0 , [2]=1 [4]
        }

        return numbers;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// use map

// 3,2,4
// map: [3] = 0
// when 2 comes
//  we need to check for 4
// [4] = 1
// when 4 comes :
//
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;
    unordered_map<int, int> map;
    for (auto i = 0; i < numsSize; i++)
    {
        auto diff = target - nums[i];
        // check whether this diff exists already in map
        if (map.find(diff) != map.end())
        {
            // we find diff
            int *result = (int *)malloc(sizeof(int) * 2);
            result[0] = map[diff];
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        map[nums[i]] = i; // [3] = 0 , [2]=1 [4]
    }

    return NULL;
}

// bruite force
int *twoSumBruteForce(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;

    for (auto i = 0; i < numsSize; i++)
    {
        auto remain = target - nums[i];
        for (auto k = i + 1; k < numsSize; k++)
        {
            if (remain == nums[k])
            {
                int *result = (int *)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = k;
                *returnSize = 2;
                return result;
            }
        }
    }

    return NULL;
}

void assert(int *actual, int *expected, int size)
{
    if (actual == NULL)
    {
        printf("failed as actual is NULL\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (actual[i] != expected[i])
        {
            printf("failed: actual:%d expected:%d\n", actual[i], expected[i]);
        }
    }
}

void printArray(char *title, int *array, int size)
{
    printf("----- %s -----\n", title);
    if (array == NULL)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("  %d\n", array[i]);
    }
}

void main()
{
    // int array[] = {3, 2, 4};
    // int returnSize;

    // int *actual = twoSum(array, sizeof(array) / sizeof(int), 6, &returnSize);
    // printArray("{3,2,4}:6", actual, returnSize);
    // int expected[] = {1, 2};
    // assert(actual, expected, 2);
    // if (actual != NULL)
    // {
    //     free(actual);
    // }
    // printf("exiting...!");

    Solution sl;
    vector<int> nums{0, 4, 3, 0};

    printf("\n-------------------\n");
    vector<int> output = sl.twoSum(nums, 0);
    for (int i = 0; i < output.size(); i++)
    {
        printf("%d\n", output[i]);
    }
    printf("\n-------------------\n");
}
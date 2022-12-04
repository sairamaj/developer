/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

    Example 1:
        Input: nums = [2,0,2,1,1,0]
        Ougotput: [0,0,1,1,2,2]
    Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]
*/
/*
    Strategy:
        Brute force:
            Go through 3 passes
            Each pass take different color
            Bring all of them
        Logic:
            [2,0,2,1,1,0]
            first pass
            : 0
            [0,2,2,1,1,0]
            [0,0,2,1,1,2]
            index: 2
            [0,0,1,2,1,2]
            [0,0,1,1,2,2]
        - 2 passes is good enough

    - One pass with extra space
        - [2,0,2,1,1,0]
          [-1,-1,-1,-1,-1,-1]

          2 go to the end
          [1,1,1,1,1,2]
          0 go to the begining
          [0,1,1,1,-1,2]
          2 go the end
          [0,1,1,1,2,2]
          1 ignore
          1 ignore
          0 go to the beging
          [0,0,1,1,2,2]
    Leet code
        count the
    One pass:
        Dutch National Flag Problem
        p0 will move only if the zero
        p2 will move back only if it is 2
        cur keep moving.
        ex:
            [2,0,2,1,1,0]
            p0:0 cur:0 p2:5
            curv:2
            [0,0,2,1,1,2]
            p0:0 cur:1 p2:4
            cur[0]
              swapwith p0: and move: p0
            [0,0,2,1,1,2]
            p0:1 cur:2 p2:4

*/

#include <stdio.h>

void sortColorsMultiPass(int *nums, int numsSize)
{
    int curIndex = 0;
    int curColor = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = curIndex; j < numsSize; j++)
        {
            if (nums[j] == curColor)
            {
                int temp = nums[curIndex];
                nums[curIndex] = nums[j];
                nums[j] = temp;
                curIndex++;
            }
        }

        curColor++;
    }
}

void sortColorsWithCount(int *nums, int numsSize)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            zeroCount++;
        }
        else if (nums[i] == 1)
        {
            oneCount++;
        }
        else if (nums[i] == 2)
        {
            twoCount++;
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < zeroCount; j++)
        {
            nums[0] = 0;
        }
        for (int j = 0; j < oneCount; j++)
        {
            nums[zeroCount + j] = 1;
        }
        for (int j = 0; j < twoCount; j++)
        {
            nums[zeroCount + oneCount + j] = 2;
        }
    }
}

void swap(int* f, int *s){
    int t = *f;
    *f = *s;
    *s = t;
}
// One Pass.
void sortColors(int *nums, int numsSize)
{
    int p0 = 0, cur = 0, p2 = numsSize - 1;
    while (cur <= p2)
    {
        if(nums[cur] == 2){
            swap(&nums[cur],&nums[p2]);
            p2--;
        }else if(nums[cur] == 0){
            swap(&nums[cur],&nums[p0]);
            p0++;
        }

        cur++;
    }
}
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }

    printf("\n");
}

void main()
{
    //int array[] = {2, 0, 2, 1, 1, 0};
    int array[] = {2, 0, 1};
    int size = sizeof(array) / sizeof(int);
    printArray(array, size);
    sortColors(array, size);
    printArray(array, size);
}
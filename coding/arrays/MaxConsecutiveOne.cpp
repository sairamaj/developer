/*
    Input: nums = [1,0,1,1,0]
Output: 4
Explanation:
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.

Input: nums = [1,0,1,1,0,1]
Output: 4
Explanation:
- If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.

*/
/*
    Strategy:
1,0,1,1,0
start
  if we get one zero count as it is one
     keep moving till you get next 0

1  -> 1
0  -> 2  (found already 0
1  -> 3
1  -> 4
0  -> record:max:4

1,0,1,1,0,1,1,1,1

max: 0
prevconsecutiveOne:0
0: false

1 -> 1  (max:1) , pC = 1
0 -> 0-true, max:2 pC = 0
1 -> 0-true , max:3, Pc = 1
1 -> 0-true, max:4 , pC = 2
0 -> max:4,
          curMax = pC+1
        0 - true

as soon as we get 0 we need to do 2 things
    - if there was previous 0
        evaluate and record
    - if there is no previous 0
          mark
        count this as 0
        increment curMax and proceed

// 1,0,1,1,0,1
1 -> pc=1 max=1
0 -> flag 0, pc=0, max=2
1 -> pc=1 max=3
1 -> pc=2 max=4
0 ->  already saw 0
    max=4
    curMax= pc+1 = 3
1 -> curmax+1

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

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int curMax = 0, max = 0;
    int curConsecutiveOnes = 0;
    bool isZeroFound = false;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            curConsecutiveOnes++;
            curMax++;
        }
        if (nums[i] == 0)
        {
            if (isZeroFound == false)
            {
                // Treat this as if it is 0
                isZeroFound = true;
                curMax++;
            }
            else
            {
                // we already saw 0. record the details.
                if (curMax > max)
                {
                    max = curMax;
                }

                curMax = curConsecutiveOnes + 1;
            }

            curConsecutiveOnes = 0;
        }
    }

    if (curMax > max)
    {
        max = curMax;
    }

    return max;
}

void main()
{
    int array[] = {1, 0, 1, 1, 0, 1};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);
    printf("_________________________________\n");
    int result = findMaxConsecutiveOnes(array, size);
    printf("result:%d\n", result);
}
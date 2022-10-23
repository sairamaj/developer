/*
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/

/*
Strategy
    2 pointers
        curZeroIndex - moves zero
        curNonZeroIndex - moves to non zero
        swap 2 elements
        move curZeroIndex to next zero
        move curNonIndex to non zero
Walk through
  curZero = 0(0)
  curNonZero  = 1(1)
  swatp
  1,0,0,3,12
  curZero = curNonZero = 1(1)
  movecurNonZero = 3(3)
  swap
  1,3,0,0,12
  curZero = 2(move till next 0)
  curNonZer = 4(12)
  swap
  1,3,12,0,0
  curNonZero end
  stop
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
void moveZeroes(int *nums, int numsSize)
{
    int curZero = 0, curNonZero = 0, i = 0;
    while (i < numsSize)
    {
        if (nums[i] != 0)
        {
            int temp = nums[curZero];
            nums[curZero] = nums[i];
            nums[i] = temp;
            curZero++;
        }
        i++;
    }
}

void moveZeroesx(int *nums, int numsSize)
{
    int curZero = -1, curNonZero = 0;

    int i = 0;
    while (i < numsSize)
    {
        if (nums[i] == 0)
        {
            // found zero. already visited zero, stay on it, if not then position here
            if (curZero == -1)
            {
                curZero = i;
            }
        }
        else
        {
            // found non zero.
            // did we saw zero previously
            // if yes
            // swap
            // increment curZero
            // if not
            // ignore
            if (curZero >= 0)
            {
                nums[curZero] = nums[i];
                nums[i] = 0;
                curZero++;
            }
        }
        i++;
    }
}

void main()
{
    //int array[] = {0};
    int array[] = {0, 2};

    int size = sizeof(array) / sizeof(int);
    printArray(array, size);
    moveZeroes(array, size);
    printArray(array, size);
}
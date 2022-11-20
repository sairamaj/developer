/*
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
    Strategy
        2 pointers
        p1, p2 keep moving till we get the value
        p1 stays
        p2 moves till not found the value
        move p2 element to p1
        increment p1 and p2

ex:
    0,1,2,2,3,0,4,2
    p1,p2 => 2(2)
    p1: 2(2)
    p2 3(4)

    swap p2 to p1
    0,1,3,2,2,0,4,2
    p1:2(3)
    p2:0(5)
    move p2:p1
    0,1,3,0,2,2,4,2
_______

Stragy:2
p1:begin
p2:end

keep moving p1 till =val
keep moving back till != val
swap
keep going
____
walk through:
    0,1,2,2,3,0,4,2
    p1:0
    p2:2

    p1:1
    p2:4

    p1:2
    p2:4

    move
    0,1,4,2,3,
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
// using strategy:1
int removeElement(int *nums, int numsSize, int val)
{
    int reader = 0;
    int writer = 0;
    while(reader < numsSize){
        if(nums[reader] == val){
            reader++;
        }else{
            nums[writer] = nums[reader];
            reader++;
            writer++;
        }
    }

    return writer;
}

// using strategy:2
int removeElement2(int *nums, int numsSize, int val)
{
    if (numsSize == 0)
    {
        return 0;
    }
    if (numsSize == 1)
    {
        if (nums[0] == val)
        {
            return 0;
        }

        return numsSize;
    }

    int p1 = 0;
    int p2 = numsSize - 1;
    while (p1 < p2)
    {
        while (p1 < p2 && nums[p1] != val)
        {
            p1++;
        }

        while (p1 < p2 && nums[p2] == val)
        {
            p2--;
        }
        if (p1 < p2)
        {
            nums[p1] = nums[p2];
            p1++;
            p2--;
        }
    }

    return p1 + 1;
}

void main()
{
    int array[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int size = sizeof(array) / sizeof(int);

    printArray(array, size);

    int ret = removeElement(array, size, 2);

    printf("______________________________________________");
    printArray(array, ret);
}

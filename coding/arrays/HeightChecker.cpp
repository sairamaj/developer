/*
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.

Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.

1,2,3,4,5
2,1,3,4,5
 ans:2
cur:2
move to next
less: increment
cur:2
move to next:
*/

/*
ex: 1,1,4,2,1,3
  start with cur:
    cur:1
    4:
       +
    cur:4
    move:2
        ++
    cur:4
    move:1
        ++
    cur:4
    move:3
        ++
*/

// This solution is not guranteed, and does not work for all test cases.
#include <stdio.h>
int heightChecker(int *heights, int heightsSize)
{
    if (heightsSize == 0)
    {
        return 0;
    }

    int previousHeight = heights[0];
    int result = 0;
    for (int cur = 0; cur < heightsSize; cur++)
    {
        if (heights[cur] < previousHeight)
        {
            result++; // found in wrong position.
        }

        if (heights[cur] > previousHeight)
        {
            previousHeight = heights[cur];
        }
    }

    return result;
}

void printArray(int *array, int size)
{
    printf("\n__________________________\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
    printf("\n__________________________\n");
}

void main()
{
    // int array[] = {1, 1, 4, 2, 1, 3};
    int array[] = {5, 1, 2, 3, 4};
    // int array[] = {1, 2, 3, 4, 5};

    int size = sizeof(array) / sizeof(int);

    printArray(array, size);

    int output = heightChecker(array, size);
    printf("output:%d\n", output);
}
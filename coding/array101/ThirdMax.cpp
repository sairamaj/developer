/*
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.*/

/*
    Strategy:
        have array with 3
        [intmin,intmin,intmin]
    go through list
    check and replace in max array
    at the end take 3rd one
ex:
    [3,2,1]
3    -> [3,-1,-1]
2    -> [3,2,-1]
1    -> [3,2,1]

// go through list and get min :1

ex:
[3,5,7,1,2,3,9,23,1]
3  -> [3,-1,-1]
5  -> [3,5,-1]
7  -> [3,5,7]
1,2,3 -> no replace
9  -> [9,5,7]
23 -> [9,23,7]
1  -> no replace

[9,23,7]  -> 7 is the 3rd.

pseudo
    maxarray = [intmin,intmin,intmin]
    lastminIndex = 0;
    lsatminVal = intmin;
    for(i=0; i<len; i++){
        // getmin of max array
        // chek current agains min
        // if current > min
        // replace
    }

**/

B
int findMinOfArray(int *array, int size, int *index)
{
    if (size == 0)
    {
        return -1;
    }

    int curMin = array[0];
    *index = 0;
    // get min of maxArray
    for (int k = 0; k < size; k++)
    {
        if (array[k] < curMin)
        {
            curMin = array[k];
            *index = k;
        }
    }

    return curMin;
}

bool exists(int *num, int size, int findVal)
{
    for (int i = 0; i < size; i++)
    {
        if (num[i] == findVal)
        {
            return true;
        }
    }

    return false;
}

int thirdMax(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }

    int maxArray[] = {INT_MIN, INT_MIN, INT_MIN};

    for (int i = 0; i < numsSize; i++)
    {
        int curMinIndex = -1;
        int curMin = findMinOfArray(maxArray, sizeof(maxArray) / sizeof(int), &curMinIndex);
        if (nums[i] > curMin && !exists(maxArray, sizeof(maxArray) / sizeof(int), nums[i]))
        {
            maxArray[curMinIndex] = nums[i];
        }

        // printf("______________________\n");
        // printArray(maxArray, sizeof(maxArray) / sizeof(int));
        // printf("______________________\n");
    }

    // finally find the min of maxArray
    int curMinIndex = 0;
    auto actualSize = sizeof(maxArray) / sizeof(int);
    if (numsSize < actualSize)
    {
        actualSize = numsSize;
    }

    return findMinOfArray(maxArray, actualSize, &curMinIndex);
}

void main()
{
    int array[] = {2,2,1,3};

    printArray(array, sizeof(array) / sizeof(int));
    int result = thirdMax(array, sizeof(array) / sizeof(int));
    printf("result:%d\n", result);
}
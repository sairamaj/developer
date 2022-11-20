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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
 */
// out loop
// inner loop starts from +1
//  find max
//  replace current
int *replaceElementsMultiLoop(int *arr, int arrSize, int *returnSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        int max = -1;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (max < arr[j])
            {
                max = arr[j];
            }
        }

        arr[i] = max;
    }

    *returnSize = arrSize;
    return arr;
}

// [17,18,5,4,6,1]
// walk backwards
// [18,6,6,6,1,-1]
// last = -1
// last-1 = last
// rightmax = i[5]
// i[5] = i[6]
// i[6] = -1
// i-- >4
// temp = arr[i]
// arr[i] = max
// temp > max
//   max = temp
// i--

int *replaceElements(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    if (arrSize == 1)
    {
        arr[0] = -1;
        return arr;
    }
    else if (arrSize == 2)
    {
        arr[0] = arr[1];
        arr[1] = -1;
        return arr;
    }

    int curRightMax = arr[arrSize - 1];
    for (int i = arrSize - 2; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = curRightMax;
        if (temp > curRightMax)
        {
            curRightMax = temp;
        }
    }
    arr[arrSize-1] = -1;
    return arr;
}

void main()
{
    int arr[] = {17, 18, 5, 4, 6, 1};
    int retSize = 0;
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    int *newArray = replaceElements(arr, size, &retSize);
    printArray(arr, size);
}
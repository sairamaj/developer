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

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int cur = nums1Size - 1;
    int pos1 = m - 1;
    int pos2 = n - 1;

    while (pos1 >= 0 && pos2 >= 0)
    {
        if (nums1[pos1] > nums2[pos2])
        {
            // move
            nums1[cur] = nums1[pos1];
            cur--;
            pos1--;
        }
        else
        {
            nums1[cur] = nums2[pos2];
            cur--;
            pos2--;
        }
    }

    while (pos2 >= 0)
    {
        nums1[cur] = nums2[pos2];
        cur--;
        pos2--;
    }
}

void main()
{
    // int num1[6] = {1, 2, 3, 0, 0, 0};
    // int num2[3] = {2, 5, 6};

    // int num1[7] = {1, 2, 10,  15, 0, 0, 0};
    // int num2[3] = {3, 4, 5};

    int num1[1] = {0};
    int num2[1] = {1};
    printArray(num1, 1);
    printArray(num2, 1);

    printf("+++++++++++++++++++++++++");
    merge(num1, 1, 0, num2, 1, 1);
    printArray(num1, 1);
}
/*
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
*/

/*
    Strategy:
    1
        [0,1]
    2
        [00,10,11,01]
    3(7)
        [000,001,010,011,100,101,110]
        [000,100,110,111,011,001,010]
    4(15)
        [0000,1000,1100,1110,1111,0111,0011,0001]
*/

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void displayBin(int num)
{
    unsigned int mask = 0x80000000;
    for (int i = 1; i <= 32; i++)
    {
        if (num & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

        if ( i > 0 && (i % 4) == 0)
        {
            printf("-");
        }
        mask = mask >> 1;
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int size = 2*n;
    int* array = (int *)malloc(sizeof(int) * size);
    memset(array, 0, sizeof(int)* size);

    int mask = (01 << (n-1));
    //printf("mask:%d\n");
    //displayBin(mask);
    int current = 0;
    for(int i=1; i<=n; i++){
        array[i] = current ^ mask;
        mask >>= 1; 
        current = array[i];
    }

    mask = (01 << (n-1));
    for(int i=(n+1); i<(2*n); i++){
        array[i] = current ^ mask;
        mask >>= 1; 
        current = array[i];
    }

    *returnSize = size;
    return array;
}

void main()
{
    int ret;
    int* array = grayCode(1,&ret);
    for(int i=0; i<ret;i++){
       printf("%d\n", array[i]);
       displayBin(array[i]);
    }
}
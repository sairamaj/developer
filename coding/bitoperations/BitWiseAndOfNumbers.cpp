/*
    Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 Example 1:

    Input: left = 5, right = 7
    Output: 4
    Example 2:

    Input: left = 0, right = 0
    Output: 0
    Example 3:

    Input: left = 1, right = 2147483647
    Output: 0
*/

/*
    Strategy:
    Brute force: 
        loop all numbers and do AND operation on each number.
    Optimized
        5:  0101
        6:  0110
        7:  0111
    we need to set those bits where all bits are on all numbers
    as any 0 make the position to 0

*/
#include <stdio.h>

int rangeBitwiseAndBruteForce(int left, int right)
{
    int num = left;
    for (int i = left+1; i <= right; i++)
    {
        num &= i;
        if(num == 0){
            break;
        }
    }   

    return num;
}

int rangeBitwiseAnd(int left, int right)
{
    int num1 = left;
    int num2 = right;

    int count=  0;
    while(num1 != num2){
        num1 = num1 >> 1;
        num2 = num2 >> 1;
        count++;
    }
    //printf("num1:%d count:%d\n", num1, count);
    num1 = (num1 << count);
    return num1;
}

void main()
{
    printf("%d\n", rangeBitwiseAnd(5,7));
}


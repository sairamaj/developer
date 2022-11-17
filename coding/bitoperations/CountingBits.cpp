/*
    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
    ans[i] is the number of 1's in the binary representation of i.

    Example 1:

        Input: n = 2
        Output: [0,1,1]
        Explanation:
        0 --> 0
        1 --> 1
        2 --> 10

    Example 2:

        Input: n = 5
        Output: [0,1,1,2,1,2]
        Explanation:
        0 --> 0
        1 --> 1
        2 --> 10
        3 --> 11
        4 --> 100
        5 --> 101
*/

/*
    Strategy:
        Bruite Force:
            go through each int and count bits
        Optimized            
            0000 -> 0 (0)
            0001 -> 1 (1)

            0010 -> 2 (1)
            0011 -> 3 (2)
            
            0100 -> 4 (1)
            0101 -> 5 (2)
            0110 -> 6 (2)
            0111 -> 7 (3)

            1000 -> 8 (1)
            1001 -> 9 (2)
            1010 -> 10(2)
            1011 -> 11(3)
            1100 -> 12(2)
            1101 -> 13(3)
            1110 -> 14(3)
            1111 -> 15(4)
*/

#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    return 0;
}
void main()
{
}
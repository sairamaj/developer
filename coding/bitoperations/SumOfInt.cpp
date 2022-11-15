/*
    Given two integers a and b, return the sum of the two integers without using the operators + and -.
*/

/*
    Strategy
        use bitwise
        If both bits are 1 then set destination to 1 and carryover to 1
    Note: This does not work for all cases (ex: negative numbers)

    Leetcode solution:
        https://leetcode.com/problems/sum-of-two-integers/solutions/678639/official-solution/
    Sum of 2 positive integers: (x^y) + (carry over)

    1111 = 15
    0010 =  2

  xor:  1101 = 13
  carry over:   1 1 1 1
                0 0 1 0

                0 1 0 0   => 4
   sum = 13 + 4 = 17
*/
#include <stdio.h>

int getSum(int a, int b)
{
    int xor = a ^ b;
    int carryOverValue = 0;
    int carry = 0;
    int mask = 1;

    for (int i = 1; i <= sizeof(int) * 8; i++)
    {
        int aBit = a & mask;
        int bBit = b & mask;

        if ((aBit & bBit))
        {
            printf("both bits are on:%d\n",i);
            carry = 1 << (i);
            carryOverValue = carryOverValue | carry;
        }

        mask = mask << 1;        
    }

    return xor+carryOverValue;
}
int getSumx(int a, int b)
{
    int dest = 0;
    int carryOver = 0;
    int curMask = 1;

    return a ^ b;

    /*
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        int first = a & curMask;
        int second = b & curMask;

        carryOver = first && second & carryOver;
        if (first || second)
        {
            dest = dest | curMask;
        }
        curMask = curMask << 1;
    }
    if (carryOver > 0)
    {
        dest = dest | curMask;
    }

    return dest;
    */
}
void main()
{
    // 101
    // 010

    // 111
    // 011

    // 111 (7)
    // 010 (2)
    // 1001
    // 101 (5)

    printf("%d", getSum(25, 10));
}

// 0100 (4)
//      (-4)
// 1100
// 0011
// 0100
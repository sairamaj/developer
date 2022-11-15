/*
    Reverse bits of a given 32 bits unsigned integer.
Example 1:
    Input: n = 0000 0101 0010 1000 0011 1101 001 1100
    Output:    964176192 (00111001011110000010100101000000)
    Explanation: The input binary string 00000010100101000001111010011100 represents
                the unsigned integer 43261596, so return 964176192

    Input: n = 11111111111111111111111111111101
    Output:   3221225471 (10111111111111111111111111111111)
    Explanation: The input binary string 11111111111111111111111111111101 represents
     unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
*/

/*
    Strategy:
        -Extract from last bit from original
            - And with 0x01
            - shift right
        -Set in the destination
            - Or it
            - shift left
    ex:
        s:1011
        m:0001
        v:0001
        f:1000

        d:0000
        o:1000
        f:1000
*/
#include <stdio.h>
#include <conio.h>

void displayBin(int num)
{
    unsigned int mask = 1;
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
        mask = mask << 1;
    }
    printf("\n");
}
unsigned int reverseBits(unsigned int n)
{
    unsigned int mask = 0x80000000;
    unsigned int dest = 0x00;
    unsigned int destMask = 1;

    for (int i = 0; i < 32; i++)
    {
        unsigned int bitValue = n & mask;
        //displayBin(mask);
        if (bitValue > 0)
        {
            dest = dest | destMask;
        }

        mask = mask >> 1;
        // printf("_____________________\n");
        // displayBin(dest);
        // printf("_____________________\n");
        destMask = destMask << 1;
    }

    return dest;
}

void main()
{
    //  0000 0010 1001 0100 0001 1110 1001 1100
    //  8     0    0    0    0    0    0    0
    // 00111001011110000010100101000000
    //

    // 1011
    // 1111
    // 0000 1011
    // 1101 0000

    unsigned int val = 566554;
    unsigned int output = 0xd0;
    // printf("0x%x\n", val);
    displayBin(val);
    // printf("0x%x\n", output);
    // displayBin(output);
    output = reverseBits(val);
    // printf("0x%x\n", output);
    displayBin(output);
    printf("val:%u output:%u\n", val, output);
}
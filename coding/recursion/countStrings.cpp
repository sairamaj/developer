/*
    Count the number of binary strings with no consecutive ones that can be formed using a binary string of Length no

    Input: N

    2 => 3 strings (00,01,10, NOT 11)
    3 => 5 strings (000,001,010,100,101, NOT 110, 011,111)

    if we fix the position with 0 then total posible values are f(n-1)
    if we fix the position with 1 then it is 1,0,..  which is f(n-2)  see the 0... as same as above

    the total possible values are f(n-1) + f(n-2)
*/
#include <stdio.h>
// O(2^n)
int countStrings(int n)
{
    printf("n:%d\n", n);
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2;
    }

    return countStrings(n - 1) + countStrings(n - 2);
}

void main()
{
    for (int i = 1; i < 5; i++)
    {
        printf("countStrigns: %d:%d\n", i, countStrings(i));
    }
}
/*
    Given a "4xn" board and tiles of size "4x1" count the number of ways to tile the given board using the "4x1" tiles"
    A file can either be placed horizontally as 1x4 or vertically 4x1

    Try to get recurisve function
    If tiles are placed vertically then it is 1+f(n-1)
        One verical column there is only one way
    If tiles are placed horizontally then it is 1+f(n-4)
        To put horizontally we need at least 4 rows.

    recusive function is
        f(n) = f(n-1)  + f(n-4)
    base is
        if n < 3
            1
*/
#include <stdio.h>
int f(int n)
{
    if(n<= 3){
        return 1;
    }
    return f(n-1) + f(n-4);
}

void main()
{
    printf("%d\n", f(5));
}
/*
    fib(0) = 0
    fib(1) = 1
    fib(2) = 1
    fib(3) = 2
    fib(4) = 3

    base condition
        0 -> 0
        1 -> 1
*/
#include <stdio.h>

/*
                        5
                    4
                3     2  
            2     1
        1
    0

T: 1+2+4+... (Geomertic Progress) : O(2^n)
S: O(n)  -> uses the stack

*/
int fib(int n)
{
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}


void main()
{
    printf("%d\n", fib(0));
    printf("%d\n", fib(1));
    printf("%d\n", fib(3));
    printf("%d\n", fib(5));
}


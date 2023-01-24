/*
    factorial of n: (n)*(n-1)*(n-2)... 1
        n! = n  * (n-1)!
        f(n!) = n * f(n-1)
    ex: 5!  5*4*3*2*1  = 120
*/
/*
                5(24)  (Top down approach -> moving down towards base)
            4(6)
        3(2)
    2 (1)
1(base case)
*/
#include <stdio.h>

int fact(int n)
{
    if (n == 1)
    {
        return 1; // base case;
    }

    return n * fact(n - 1);
}

// Iterative which is bottom to top
int factIterative(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}
void main()
{
    printf("%d\n", fact(30));
    printf("%d\n", factIterative(30));
}

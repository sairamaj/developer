#include <stdio.h>
#include <math.h>

// O(n) O(1)
void listFactors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d,", i);
        }
    }

    printf("\n");
}

// O(n) O(1)
void listFactors2(int n)

{
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            printf("%d,", i);
        }
    }

    printf("\n");
}

// O(sqrt(n)) O(1)
void listFactors3(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%d,", i);
            printf("%d,", n / i);
        }
    }

    printf("\n");
}
void main()
{
    listFactors(100);
    listFactors2(100);
    listFactors3(100);
    listFactors3(24);
}

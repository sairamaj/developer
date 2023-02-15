#include <stdio.h>

int steps(int n)
{
    if(n <= 1){
        return 0;
    }

    auto count = 10000;
    if (n % 2 == 0)
    {
        int step1 = steps(n / 2) + 1;
        if (step1 < count)
        {
            count = step1;
        }
    }
    if (n % 3 == 0)
    {
        int step2 = steps(n / 3) + 1;
        if (step2 < count)
        {
            count = step2;
        }
    }

    int step3 = steps(n - 1) + 1;
    if (step3 < count)
    {
        count = step3;
    }

    return count;
}

void main()
{
    printf("%d\n", steps(11));
}
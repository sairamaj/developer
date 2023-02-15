/*
    dp(i) = dp(i) + dp
*/
#include <stdio.h>

int findMax(int *prices, int size, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        int amt = prices[i - 1];
        amt += findMax(prices, size, n-i);
        if(amt > max){
            max = amt;
        }
    }

    return max;
}

void main()
{
    int prices[]{2,2};
    int size = sizeof(prices)/sizeof(int);
    int max = findMax(prices, size, 2);
    printf("%d\n",max);
}
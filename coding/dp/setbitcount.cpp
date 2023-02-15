/*
    printing the set bits in 1..n numbers.
*/

#include <stdio.h>
#include <memory.h>
    /*
            0    0  (00)
            1    1  (01)
            2    1  (10)
            3    2  (11)
            4    1  (100)
            5    2  (101)
            6    2  (110)
            7    3  (111)
            8    2  (1000)
            9    2  (1001)
            10   2  (1010)
            11   3  (1011)

            f(i) = f(i/2) + f(odd)
            10   = 5(2)+ 0 => 2
            11   = 5(2)+ 1 => 3
            f(0) = 0;
            f(1) = f(0) + 1 = 1

    */


int getSetBit(int n, int* cache)
{
    if (n == 0)
    {
        return 0;
    }

    if(cache[n] != 0){
        return cache[n];
    }

    int val = getSetBit(n / 2,cache) + (n % 2 == 0 ? 0 : 1);
    cache[n] = val;
    return val;
}

void printByDp(int n)
{
    int *cache = new int[n+1];
    memset(cache, 0, sizeof(int)*((n+1)));
    for (int i = 0; i <= n; i++)
    {
        printf("%d %d\n",i, getSetBit(i, cache));
    }
    delete []cache;
}

void printByDpByTabulation(int n)
{
    int *results = new int[n+1];
    
    results[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        results[i] = results[i/2] + (i%2 == 0 ? 0 : 1);
        printf("%d %d\n", i, results[i]);
    }

    delete []results;
}
void printByBruteForce(int n)
{
   for (int i = 0; i <= n; i++)
    {
        int count = 0;
        int x = i;
        for (int j = 0; j < sizeof(int); j++)
        {
            if (x & 1)
            {
                count++;
            }
            x = x >> 1;
        }
        printf("%i:%d\n", i, count);
    }
}
void main()
{
    int n = 10;
    printf("\n---------Brute force-----------\n");
    printByBruteForce(n);
    
    printf("\n-------Recursion Memoziation-------------\n");
    printByDp(n);
    
    printf("\n-------- Tabulation ------------\n");
    printByDpByTabulation(n);
}
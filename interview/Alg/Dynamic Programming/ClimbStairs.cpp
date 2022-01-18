/*
    https://www.youtube.com/watch?v=QlT4HG93Gaw&list=PLVrpF4r7WIhTT1hJqZmjP10nxsmrbRvlf&index=4
*/
#include <stdio.h>
#include <memory>

/*
    1. objective
        f(i) is the distinict way of reaching top
            1 step at a time.
            2 steps at a time.
    2. Bases cases
        f(0) 1
        f(1) 1
    3. recurrence relation
        f(n) = f(n-1) + f(n-2)
    4. order of execution
        bottom-up
    5. answer
        f(n)
*/
int getPossiblePaths(int n)
{
    int *dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (auto i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int getPossiblePathsSpaceOptimized(int n)
{
    int x, y;
    x = 1; // [0]
    y = 1; // [1]

    // [1,1,2,3,5]
    // x=1 y=1 val=1
    // val = 2 x=1 y=2
    // val = 3 x=2 y=3

    int val = 1;
    for (auto i = 2; i <= n; i++)
    {
        val = x + y;
        x = y;
        y = val;
    }

    return val;
}

int getPossiblePathsWithOneTwoOrThree(int n)
{
    // todo: checks for n
    int *dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (auto i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    int val = dp[n];
    delete[] dp;
    return val;
}

// 2: 2
// 3: 3
// 4:
/*
    Time complexity : O(n*k)
    Space complexity: O(n)  - can be optimized to O(k)
*/
int getPossiblePathsWithKSteps(int n, int k)
{
    int *dp = new int[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));

    dp[0] = 1;
    dp[1] = 1;

    for (auto i = 2; i <= n; i++)
    {
        for (auto j = 1; j <= k; j++)
        {
            if ((i - j) >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];
}

void main()
{
    for(int i=2; i<=5; i++)
    {
        printf("%d: %d\n",i,getPossiblePaths(i));
        printf("%d: %d\n",i,getPossiblePathsSpaceOptimized(i));
        printf("________________________\n");
    }

    printf("+++++++++++++++++++++\n");

    for (int i = 3; i <= 5; i++)
    {
        printf("--- %d ---\n", i);
        printf("%d: %d\n", i, getPossiblePathsWithOneTwoOrThree(i));
        printf("________________________\n");
    }

    printf("+++++++++++++++++++++\n");
    for (int i = 3; i <= 5; i++)
    {
        printf("%d: %d\n", i, getPossiblePathsWithKSteps(i, 2));
        printf("________________________\n");
    }
}
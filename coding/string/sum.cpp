#include <stdio.h>

// 2^3 = 2*2*2
//       (2^2)*2

int exp(int n, int m)
{
    if (m == 1)
    {
        return n;
    }

    return n * exp(n, m - 1);
}
int expoptimization(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    int val = exp(n, (m) / 2);
    int final = val * val;
    if(m%2 == 1){
        return final*n;
    }
    return final;
}

/*
  e^x = 1+x+x^2/2 + x^3/3! + x^4/4! + ... n

  5th term: pow(x^4)/fac(4!)


*/

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}

int sumIterative(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n;
        n--;
    }

    return sum;
}

int fact(int n){
    int result = 1;
    for(int i=1 ; i<=n; i++){
        result *= i;
    }

    return result;
}

double f(int x,int n)
{
    if(n == 0){
        return 1;
    }

    int nFact = fact(n);
    int expValue = exp(x,n);

    double val = expValue/nFact;
    return val + f(x,n-1);
}

int sumFormula(int n)
{
    return ((n) * (n + 1)) / 2;
}

void main()
{
    int n = 2;
    int x = 2;
    printf("%d-%lf", x , f(x,n));
    return;
    printf("%d\n", 22&1);
    printf("%d\n", 13&1);
    return;
    // printf("%d\n", exp(2, 1));
    // printf("%d\n", exp(2, 2));
    // printf("%d\n", exp(2, 3));
    printf("%d\n", exp(2, 7));
    printf("%d\n", exp(2, 8));

    printf("___________________\n");
    printf("%d\n", expoptimization(2, 7));
    printf("%d\n", expoptimization(2, 8));
    return;
    printf("%d\n", expoptimization(2, 3));
    printf("%d\n", expoptimization(2, 4));
    printf("%d\n", expoptimization(2, 5));

    return;
    printf("_______________________\n");
    printf("%d\n", sum(1));
    printf("%d\n", sum(2));
    printf("%d\n", sum(3));
    printf("%d\n", sum(4));
    printf("%d\n", sum(5));

    printf("_______________________\n");
    printf("%d\n", sumFormula(1));
    printf("%d\n", sumFormula(2));
    printf("%d\n", sumFormula(3));
    printf("%d\n", sumFormula(4));
    printf("%d\n", sumFormula(5));
}
/*
    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

/*
    Strategy:
        we can do this recursivily
        base conditions is
        double calc(double x, int n)
            if(n==1){
                return x;
            }

            return calc(x,n/2)*calc(x,n/2)
*/

#include <stdio.h>
#include <math.h>

/*
    todo: need to do iteratively.
*/
double myPow2(double x, int n)
{
   if (n == 1)
    {
        return x;
    }

    double result = myPow2(x, n / 2) ;
    result = result * result;
    if (n % 2 == 1)
    {
        result *= x;
    }

    return result;
}

double myPow(double x, int n)
{
    if(n < 0){
        x = 1/x;
    }

    return myPow2(x,abs(n));
}

void main()
{
    printf("%lf", myPow(2, -2));
}
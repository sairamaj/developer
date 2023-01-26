/*
            2^8 = 
                (2^4&2^4) = 
                    (2^2*2^2)*(2^2*2^2)
                        (2*1)(2*1)
        
*/
#include <stdio.h>

int pow(int x, int n){
    if(n==0){
        return 1;
    }

    int val = pow(x,n/2);
    if(n & 1){
        return val*val*x;
    }

    return val*val;
}

void main()
{
    printf("%d\n", pow(2,3));
    printf("%d\n", pow(3,2));
    printf("%d\n", pow(2,10));
}
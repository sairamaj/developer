/*
*/
#include <stdio.h>

int hammingWeight(unsigned int n) {
    int count = 0;
    unsigned int num = 1;
    for(int i=0; i<sizeof(n)*8; i++){
        //printf("num:%d\n", num);
        if( (n & num) == 1)
        {
            count++;
        }

        n = n  >> 1;
    }

    return count;    
}

void main()
{
    printf("%d\n", hammingWeight(11));
}
#include <stdio.h>
#include <limits.h>

int guess(int n){
    if(n == 6){
        return 0;
    }
    if(n>6){
        return -1;
    }
    if(n<6){
        return 1;
    }

    return 0;
}
void main()
{
    int x = INT_MAX;
    //int x = 10;

    printf("%d\n", x);

    int start =0, end =x;
    do{
        int mid = start + (end-start)/2;
        //int mid = start + (end-start)/2;
        printf("number to guess:%d\n", mid);
        int ret = guess(mid);
        if(ret == 0){
            printf("found:%d\n",mid);
            break;
        }
        if(ret == -1){
            end = mid-1;
        }
        else if(ret == 1){
            start = mid +1;
        }
    }while(true);
}
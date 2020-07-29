#include <stdio.h>

void main(){
    int x = 40;
    int y = 60;

    printf("Before x:%d y:%d\n", x, y);
    y = x+y;
    x = y-x;
    y = y-x;

    printf("After x:%d y:%d\n", x, y);
}
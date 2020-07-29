#include <stdio.h>

int isPal(char *ptr){
    char* last = ptr + strlen(ptr)-1;
    while(*ptr == *last){
        ptr++;
        last--;
        if(ptr >= last){
            return 0;
        }
    }

    return -1;
}

void main()
{
    char data[100];

    scanf("%s", data);
    printf("%s\n", data);

    int ret = isPal(data);
    printf("%s is :%d", data, ret);

} 
#include <stdio.h>
#include <string.h>

void main()
{
    char str[100];
    strcpy(str, "welcome");

    char *ptrleft = str;
    char *ptrright = str + strlen(str)-1;

    while (ptrleft < ptrright)
    {
        char temp = *ptrleft;
        *ptrleft = *ptrright;
        *ptrright = temp;
        ptrleft++; ptrright--;
    }

    printf("str:%s\n",str);
}
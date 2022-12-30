#include <stdio.h>
#include <string.h>

void printBits(int val)
{
    int x = 1;
    for (int i = 1; i < sizeof(int)*8 + 1; i++)
    {
        printf("%d", ( (val & x) > 0 ? 1: 0));
        x = x << 1;
        if ((i % 4) == 0)
        {
            printf("-");
        }
    }

    printf("\n");
}

void main()
{
    char str[100];
    strcpy(str, "hello");

    int charBit = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        int x = 1;

        int val = (int)str[i] - 97;
        printf("val:%d\n", val);
        charBit = (charBit | (x << val));
    }

    printf("charBit:%d\n", charBit);
    printBits(charBit);

    // display duplicates
    int x = 1;
    for (int i = 0; i < sizeof(int)*8; i++)
    {
        if( x & charBit){
            printf("%c ", (char)((i+97)));
        }
        x = x << 1;
    }
}

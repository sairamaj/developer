#include <stdio.h>
#include <string.h>

bool isPalindrome(char *str)
{
    char *ptr1 = str;
    char *ptr2 = str + strlen(str) - 1;

    while (ptr1 < ptr2)
    {
        if (*ptr1 != *ptr2)
        {
            return false;
        }
        ptr1++;
        ptr2--;
    }

    return true;
}

bool areEqual(char *str1, char *str2)
{
    char *ptr1 = str1;
    char *ptr2 = str2;

    while (*ptr1 && *ptr2)
    {
        if(*ptr1 != *ptr2){
            return false;       // bail out.
        }

        ptr1++;ptr2++;
    }

    // when they come out both should be at null characters.
    return *ptr1 == *ptr2;
}

void main()
{
    char str[100];
    
    printf("are equal:%d", areEqual("abc","ab"));
}
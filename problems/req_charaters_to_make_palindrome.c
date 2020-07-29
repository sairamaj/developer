#include <stdio.h>

int getRequiredPalindromeCharacters(char *ptr)
{
    char *last = ptr + strlen(ptr) - 1;
    int count = 0;
    while (*ptr != '\0' && ptr <= last)
    {
        if (*ptr != *last)
        {
             count++;
        }
        else{
            last--;
        }

        ptr++;
    }

    return count;
}

void main()
{
    char data[100];

    printf("enter text to find out number of characters rquired to make it palindrome:");
    scanf("%s", data);
    printf("%s\n", data);

    int ret = getRequiredPalindromeCharacters(data);
    printf("required :%d for data:%s\n",ret, data);
}
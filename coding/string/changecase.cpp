#include <stdio.h>
#include <string.h>

char *toLower(char *info)
{
    char *ptr = info;
    while (*ptr != '\0')
    {
        printf("%c-%d\n", *ptr, *ptr);

        if (*ptr >= 65 && *ptr <= 90)
        {
            *ptr = (int)*ptr - 65 + 97;
        }
        printf("%c-%d\n", *ptr, *ptr);
        ptr++;
    }
    return info;
}
char *toUpper(char *info)
{
    char *ptr = info;
    while (*ptr != '\0')
    {
        printf("%c-%d\n", *ptr, *ptr);

        if (*ptr >= 97 && *ptr <= 122)
        {
            *ptr = (int)*ptr - 97 + 65;
        }
        printf("%c-%d\n", *ptr, *ptr);
        ptr++;
    }
    return info;
}
void main()
{
    char str[100];
    strcpy(str, "WELCOME");
    printf("%s\n", toLower(str));
}
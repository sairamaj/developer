#include <stdio.h>
#include <string.h>

// strategy
// two pointers
// swap
void reverseString(char *s, int sSize)
{
    auto i = 0, j = sSize-1;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;j--;
    }
}

void assert(char *expected, char *actual, char *title)
{
    if (strcmp(expected, actual) == 0)
    {
        printf("success: expected:|%s| actual:|%s| title:|%s|\n", expected, actual, title);
    }
    else
    {
        printf("failed: expected:|%s| actual:|%s| title:|%s|\n", expected, actual, title);
    }
}

void main()
{
    char str[30];
    strcpy(str,"hello");
    reverseString(str, strlen(str));
    assert("olleh", str, "hello");

    strcpy(str,"Hannah");
    reverseString(str, strlen(str));
    assert("hannaH", str, "Hannah");

}
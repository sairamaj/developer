#include <stdio.h>
#include <string.h>

// todos
// use C++ functions for isAlpha

// test cases
// case insentive
// empty string is palindrome.
// strategy
// ptr from front
// ptr from back
// keep comparing till they meet.


const int number0 = 48;
const int number9 = number0 + 9;
const int alphaA = 65;
const int alphaZ = alphaA + 25;

const int alphaa = 97;
const int alphaz = alphaa + 25;
const int alphaDiff = alphaa - alphaA;
char toLower(char c)
{
    int n = (int)c;
    if (n >= alphaA && n <= alphaZ)
    {
        return (char)n + alphaDiff;
    }

    return c;
}

bool needToSkip(char c)
{
    int n = (int)c;
    if (n >= alphaa && n <= alphaz)
    {
        return false;
    }
    if (n >= alphaA && n <= alphaZ)
    {
        return false;
    }
    if (n >= number0 && n <= number9)
    {
        return false;
    }

    return true;
}
bool isPalindrome(char *s)
{
    int i = 0, j = strlen(s) - 1;

    while (i <= j)
    {
        while (s[i] != '\0' && needToSkip(s[i]))
        {
            i++;
        }
        while (j >= 0 && needToSkip(s[j]))
        {
            j--;
        }
        if (i > j)
        {
            return true;
        }
        //printf("i:%c j:%c\n", s[i],s[j]);
        if (toLower(s[i]) != toLower(s[j]))
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

char *moveForward(char *ptr)
{
    while (*ptr)
    {
        if (needToSkip(*ptr))
        {
            ptr++;
        }
        else
        {
            break;
        }
    }
    return ptr;
}

char *moveBackward(char *ptr, int *pos)
{
    while (*pos >= 0)
    {
        if (needToSkip(*ptr))
        {
            ptr--;
            *pos--;
        }
        else
        {
            break;
        }
    }
    return ptr;
}

// A man, a plan, a canal: Panama -> true
bool isPalindromePtr(char *s)
{
    int pos = strlen(s) - 1;
    char *front = moveForward(s);
    char *back = moveBackward(s + pos, &pos);

    while (front <= back)
    {
        //printf("front:%c back:%c\n", *front, *back);
        if (toLower(*front) != toLower(*back))
        {
            return false;
        }
        front++;
        back--;
        pos--;
        front = moveForward(front);
        back = moveBackward(back, &pos);
    }

    return true;
}

void assert(bool expected, bool actual, char *title)
{
    if (expected == actual)
    {
        printf("success: expected:%d actual:%d for:%s\n", expected, actual, title);
    }
    else
    {
        printf("failed expected:%d actual:%d for:%s\n", expected, actual, title);
    }
}

void main()
{
    assert(true, isPalindrome("A man, a plan, a canal: Panama"), "A man, a plan, a canal: Panama");
    assert(false, isPalindrome("race a car"), "race a car");
    assert(true, isPalindrome(" "), " ");
    assert(true, isPalindrome("a."), "a.");
    assert(true, isPalindrome("ab@a"), "ab@a");
    char *s = "Marge, let's \"[went].\" I await {news} telegram.";
    assert(true, isPalindrome(s), s);
}
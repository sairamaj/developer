#include <stdio.h>
#include <string>

// take aways
//   carefull with looping variables
//   convert char to numbers use '0'
//   don't use auto for strlen as this one came as unsigned int
// strategy
// walk through reverse
// start with 1's place
// ignore the space
// consider the sign
// ex:
//   "  - 123   "
// n=1
// v = 3*1 = 3
// v = 2*10 + 3 = 23
// v = 1*100 +23 = 123
// v = v*-1
const int number0 = 48;
const int number9 = 57;

int getAsInteger(char c)
{
    if(c == '-'){
        return -1;
    }
    int n = (int)c;
    if (n >= number0 && n <= number9)
    {
        n -= number0;
        return n;
    }

    return -2;
}

bool isValid(char c)
{
    // if number or sign then it is valid
    if (c == '-' || c == '+')
    {
        return true;
    }

    if (getAsInteger(c) >= 0)
    {
        return true;
    }
    return false;
}

int myAtoi(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0;
    }

    char *ptr = str;
    int start = 0;
    
    // skip white space.
    while (*ptr != '\0' && *ptr == ' ')
    {
        start++;
        ptr++;
    }

    if (!isValid(*ptr))
    {
        return 0;
    }

    int n = 1;

    int i = strlen(str) - 1;
    int finalValue = 0, place = 1;
    bool isNegative = false;
    while (i >= start)
    {
        // printf("i:%d\n", i);
        int val = getAsInteger(str[i]);
        if (val >= 0)
        {
            finalValue += place * val;
            place *= 10;
        }
        else if (val == -1)
        {
            isNegative = true;
        }

        // printf("finalValue:%d\n", finalValue);
        i--;
    }

    return isNegative ? finalValue * -1 : finalValue;
}

void assert(int expected, int actual, char *title)
{
    if (expected != actual)
    {
        printf("%s failed. expected:%d but actual:%d\n", title, expected, actual);
    }
    else
    {
        printf("%s success. expected:%d and actual:%d\n", title, expected, actual);
    }
}
// requirement
// convert string to integer
// ex: "123" -> 123
// "a123" -> 123
// null -> 0
// "" -> 0
// "   123" -> ignore leading spaces
// "123    " -> ignore trailing spaces
// "-123" -> -123
// "+123" -> 123
// if the "xxx " > 2^31  then 2^31 and if "yyy" < -2^31  then -2^31
void main()
{
    assert(123, myAtoi("123"), "123");
    assert(-123, myAtoi("-123"), "-123");
    assert(123, myAtoi("    123    "), "123");
    assert(4193, myAtoi("4193 with words"), "4193");
    assert(0, myAtoi("words and 987"), "words and 987");
    assert(-42, myAtoi("    -42"), "    -42");
}
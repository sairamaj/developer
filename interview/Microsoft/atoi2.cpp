#include <stdio.h>
#include <limits.h>

const int number0 = 48;
const int number9 = 57;

int getIntValue(char c)
{
    int n = (int)c;
    if (n >= number0 && n <= number9)
    {
        n -= number0;
        return n;
    }

    return -1;
}

// simple case
// 123
// 1
// current:2
// value:1
// 1*10+2 = 12
// value:12
// current 3
// 12*10 + 3
// 123

// Time complexity: O(n)
// Space complexity: O(1)
int myAtoi(char *str)
{
    long long val = 0;
    char *ptr = str;

    // move the pointer to first valid char (ignre the space)
    while (*ptr != '\0' && *ptr == ' ')
    {
        ptr++;
    }

    auto signValue = 1;
    if (*ptr == '-')
    {
        signValue = -1;
        ptr++;
    }
    else if (*ptr == '+')
    {
        ptr++;
    }

    while (*ptr != '\0')
    {
        auto current = getIntValue(*ptr);
        if (current < 0)
        {
            return val * signValue;
        }
        val = val * 10 + current;
        if (val > INT_MAX)
        {
            val = val * signValue;
            if (val <= INT_MIN)
            {
                val = INT_MIN;
            }
            else
            {
                val = INT_MAX;
            }
            return val;
        }

        ptr++;
    }

    val = val * signValue;
    return val;
}

void assert(int expected, int actual, char *title)
{
    if (expected != actual)
    {
        printf("%20s failed. expected:%7d but actual:%d\n", title, expected, actual);
    }
    else
    {
        printf("%20s success. expected:%7d and actual:%d\n", title, expected, actual);
    }
}

void main()
{
    assert(123, myAtoi("123"), "123");
    assert(456, myAtoi("     456"), "     456");
    assert(4193, myAtoi("4193 with words"), "4193 with words");
    assert(-345, myAtoi("-345"), "-345");
    assert(+567, myAtoi("+567"), "567");
    assert(0, myAtoi("-+12"), "-+12");
    assert(INT_MIN, myAtoi("-91283472332"), "-91283472332");
    assert(INT_MAX, myAtoi("20000000000000000000"), "20000000000000000000");
}
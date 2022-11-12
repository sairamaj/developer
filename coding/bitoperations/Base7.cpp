/*
Given an integer num, return a string of its base 7 representation.
Example
    Input: num = 100
    Output: "202"

    Input: num = -7
    Output: "-10"
*/

/*
Strategy:
    101/7 = 14 ->3(rem)   = 3  => 3
    14/7 =  2 -> 0(rem)   =>0  => 30  => 03
    2  (<7)  =>           =>2  => 302 => 203


    -7/7  => 1 -> 0(rem)  =>0  (10)

    3/7        -> 0(div) +3(rem) = 3
*/
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string>
#include <malloc.h>

using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        string s;

        int div = num;
        int pos = 0;
        if (num < 0)
        {
            s = '-';
            pos = 1;
            div *= -1;
        }
        do
        {
            int rem = div % 7;
            div = div / 7;
            // printf("rem:%d\n", rem);
            s.insert(pos, 1, (rem + 48));
        } while (div != 0);

        return s;
    }
};
char *convertToBase7(int num)
{
    std::string s;

    int div = num;
    int pos = 0;
    if (num < 0)
    {
        s = '-';
        pos = 1;
        div *= -1;
    }
    do
    {
        int rem = div % 7;
        div = div / 7;
        // printf("rem:%d\n", rem);
        s.insert(pos, 1, (rem + 48));
    } while (div != 0);

    char *data = (char *)malloc(s.length() + 1);
    strcpy(data, s.c_str());
    return data;
}

void main()
{
    // printf("%s\n", convertToBase7(-101));
    Solution s;
    printf("%s\n", s.convertToBase7(101).c_str());
}
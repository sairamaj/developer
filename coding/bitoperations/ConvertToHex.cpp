/*
   Conversion to hex can be use the bit pattern where each 4 bits represents a hex number
*/
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string s;
        int mask = 0xf;
        int pos = 0;
        for (int i = 0; i < (sizeof(num) * 8) / 4; i++)
        {
            // printf("num:%d\n", num);
            int val = num & mask;
            int ch;
            // printf("val:%d\n", val);
            if (val <= 9)
            {
                ch = val + (int)('0');
            }
            else
            {
                ch = (val - 10) + (int)('a');
            }
            s.insert(pos, 1, ch);
            num = num >> 4;
        }

        s.erase(0, s.find_first_not_of('0'));
        return s;
    }
};

class Solution1
{
public:
    // this solution does not work for negaive numbers and also inefficient.
    string toHex(int num)
    {
        string s;
        if (num == -1)
        {
            s = "ffffffff";
            return s;
        }
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
            int rem = div % 16;
            div = div / 16;
            // printf("rem:%d\n", rem);
            int ch;
            if (rem <= 9)
            {
                ch = rem + (int)('0');
            }
            else
            {
                ch = (rem - 10) + (int)('a');
            }

            s.insert(pos, 1, ch);
        } while (div != 0);

        return s;
    }
};

void main()
{
    Solution s;
    printf("%s", s.toHex(0).c_str());
}
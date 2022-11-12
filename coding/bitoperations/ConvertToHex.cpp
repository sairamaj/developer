#include <string>
#include <stdio.h>

using namespace std;
class Solution
{
public:
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
    printf("%s", s.toHex(26).c_str());
}
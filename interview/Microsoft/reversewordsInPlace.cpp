#include <memory.h>
#include <string>
#include <vector>
#include <iostream>

#include <algorithm>>
using namespace std;

void debug(vector<char> &s, char *title)
{
    cout << "---- " << title << " ----" << endl;
    for (auto i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}
class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        reverse(s.begin(), s.end());
        int start = 0, end=0, n = s.size();
        while(start < n){
            // move to the word
            while(end < n && s[end] != ' '){
                end++;
            }

            reverse(s.begin()+start, s.begin()+end);
            start = end+1;
            end++;
        }
    }
};
void assert(char *expected, char *actual, char *title)
{
    if (strcmp(expected, actual) == 0)
    {
        printf("success: expected:|%s| actual:|%s| %s\n", expected, actual, title);
    }
    else
    {
        printf("failed: expected:|%s| actual:|%s| %s\n", expected, actual, title);
    }
}

void main()
{
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y'};
    for (auto i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }

    cout << endl;

    Solution s1;
    s1.reverseWords(s);

    for (auto i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }

    cout << endl;
}

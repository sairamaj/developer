#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    // keep map of characters
    // check at the end should be 0
    // ()  => true
    // ()[]{} => true
    // (] => false
    // ([]]) => true
    // ([}) => false
    // )(  => false
    // ( ()) => true
    // (((([[[[{{{}}}]]]])))) => true

    // strategy
    // simple stra: keep count
    // push openings
    // once found closing , validate

    bool isValid(string s)
    {
        stack<char> st;
        map<char,char> ppair;
        ppair[')'] = '(';
        ppair[']'] = '[';
        ppair['}'] = '{';


        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                //printf("pushing:%c\n", s[i]);
                st.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
               // printf("checking:%c\n", ppair[s[i]]);
                if(st.empty()){
                    return false;       // not found.
                }
                if( st.top() != ppair[s[i]]){
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

void assert(bool expected, bool actual, string s)
{
    if (expected == actual)
    {
        printf("success: expected:%d actual:%d %s\n", expected, actual, s.c_str());
    }
    else
    {
        printf("failed: expected:%d actual:%d %s\n", expected, actual, s.c_str());
    }
}

void main()
{
    Solution s;
    //assert(true, s.isValid("()"), "()");
    //assert(true, s.isValid("()[]{}"), "()[]{}");
    //assert(false, s.isValid("(]"), "(]");
    assert(false, s.isValid("([)]"), "([)]");
}
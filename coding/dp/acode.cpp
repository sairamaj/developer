/*
    Code were givent to alphabets
        A-1 B-2 ... Z-26
    If a number is given how many ways one can form.
*/
#include <stdio.h>
#include <memory.h>
#include <string>
#include <map>

using namespace std;
map<string, string> formatMap;
int total = 0;
int toCode(string s, int len)
{
    // printf("s => |%s|\n", s.substr(0,len).c_str());
    int num = stoi(s.substr(0, len));
    // printf("toCode: num:%d\n", num);
    return 64 + num;
}

void format(string str, char *buffer, int pos)
{
    if (formatMap.find(str) != formatMap.end())
    {
        printf("from cache: %s: buffer:%s\n", formatMap.at(str).c_str(), buffer);
    }
    // printf("str:|%s|\n", str.c_str());
    //  base case
    if (str.length() == 0)
    {
        buffer[pos] = '\0';
        printf("%s\n", buffer);
        total++;
        return;
    }

    // take first number
    buffer[pos] = toCode(str, 1);
    format(str.substr(1), buffer, pos + 1);
    printf("loadng:%s with:%s\n", str.c_str(), buffer);
    formatMap[str] = buffer;

    // check for 2 digits
    auto twoDigit = str.substr(0, 2);
    if (twoDigit.length() > 1)
    {
        int numberWith2Digits = stoi(str.substr(0, 2));
        // printf("numberWith2Digits : %d\n", numberWith2Digits);
        if (numberWith2Digits < 27)
        {
            buffer[pos] = toCode(str, 2);
            format(str.substr(2), buffer, pos + 1);
            formatMap[str] = buffer;
            printf("loadng:%s with:%s\n", str.c_str(), buffer);
        }
    }
}

void main()
{
    char buffer[100];
    char num[10];

    memset(buffer, 0, sizeof(buffer));
    // string str = std::to_string(25114);
    string str = std::to_string(1111111111);
    format(str, buffer, 0);
    printf("total:%d\n", total);
}
#include <iostream>
#include <string.h>
using namespace std;

void swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void permuate(char *buff, int l, int r)
{
    // base case
    if (l == r)
    {
        cout << buff << endl;
        return;
    }

    for (int i = l; i < r; i++)
    {
        swap(&buff[l], &buff[i]);
        permuate(buff, l + 1, r);
        swap(&buff[l], &buff[i]);
    }
}
void main()
{
    char buff[100];
    cout << "Type your full name: ";
    cin >> buff;
    permuate(buff, 0, strlen(buff));
}